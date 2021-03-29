#include "GamePlay.h"

//this function implements the game
void GamePlay::gameLoop() {
    srand((unsigned int)0);
    try {
        //Create Dungeon
        Dungeon dungeon;
        
        //Greetings
        Log("Welcome to the Treasure Hunt!");
        Log("Entered into the magical dungeon, good Luck!");
        
        //create a player
        Player player(0, 0);
        Position player_pos; //temp position of player
        //setLevel, player energy, points, moves
        int level = 0;
        int points = 0;
        int moves = 0;
        int gems = 0;
        
        
        
        while (level <= CONSTANT::getMaxLevel()) {
            //loop until the max level reached
            //generates monsters, gems, apples for a level
            vector<Gem> g_arr;
            vector<Monster> m_arr;
            vector<Apple> a_arr;
            //input field
            string input = "";
            //direction holder
            string direction = "";
            
            //set level for the game
            dungeon.setLevel(level, g_arr, m_arr, a_arr);
            //generate random position to push player to the dungeon
            
            do {
                player.setPosition(rand() % 11, rand() % 6);
                player_pos = player.getPosition();
            } while (dungeon.at(player_pos.getX(), player_pos.getY()) != CONSTANT::getSpot());
            dungeon.push(player);
            //log to records
            string level_announce = "";
            if (level == 1) {
                level_announce = "Entered the first cave.";
            }
            else {
                level_announce = "Entered the level " + to_string(level) + " cave.";
            }
            Log(level_announce, false);
            
            while (true) {
                //loop until next level
                //log status
                //game status
                string status = "Level: " + to_string(level) + "; Player energy: " + to_string(player.getEnergy()) + "%; Points: " + to_string(points);
                Log(status);
                //print dungeon
                dungeon.printDungeon();
                //log action instruction to console
                fflush(stdin);
                cout << "Please select action (move with wasd or Q to escape) > ";
                cin >> input;
                
                //log the detail of what player chooses
                //the idea is that when player moves it loses energy
                if (input[0] == 'w' || input[0] == 'W') {
                    Log("Moving up.");
                    moves++;
                    direction = "up";
                }
                else if (input[0] == 'a' || input[0] == 'A') {
                    Log("Moving left.");
                    moves++;
                    direction = "left";
                }
                else if (input[0] == 's' || input[0] == 'S') {
                    Log("Moving down.");
                    moves++;
                    direction = "down";
                }
                else if (input[0] == 'd' || input[0] == 'D') {
                    Log("Moving right.");
                    moves++;
                    direction = "right";
                }
                else if (input[0] == 'q' || input[0] == 'Q') {
                    
                    //exit the game which means exit the loop
                    break;
                }
                else {
                    //unknown character
                    Log("Unknown action.");
                }
                
                //handle input action
                bool isContinued = handleInteraction(dungeon, player, g_arr, m_arr, a_arr, direction, points, level, gems);
                //what if players lost energy then dies
                if (player.getEnergy() <= 0) {
                    level--;
                    break;
                }
                //if player can't continue in this level then get out
                if (!isContinued) {
                    break;
                }
                
                
            }
            //quit game when press quit or player is dead.
            if (input[0] == 'q' || input[0] == 'Q' || player.getEnergy() <= 0) {
                break;
            }
            level++;
        }
        
        //log the log file
        string sum_up = "Congratulations! You have successfully escaped from the " + to_string(level) + "-level\ndungeon after " + to_string(moves) + " moves, with " + to_string(gems) + " gems and total " + to_string(points) + " points.";
        Log(sum_up);
        Log("You feel relaxed, breathe the fresh air and hold tightly to your treasures!");
        Log("Brief adventure history:");
        string sum_up_rc = sum_up.substr(26);
        sum_up_rc[0] = 'S';
        Log(sum_up_rc, false);
        
        getRecords();
    } catch (const char * msg) {
        cout << msg << endl;
    }
    
}

//return true if player keeps continue in a specific level, false if player is dead or passes to higher level
bool GamePlay::handleInteraction(Dungeon &dungeon, Player &player, vector<Gem>& g_arr, vector<Monster>& m_arr, vector<Apple>& a_arr, string direction, int &points, int level, int &gems) {
    //get previous position first
    Position pre_pos = player.getPosition();

    //let it moves
    player.move(direction);
    //recent position
    Position rec_pos = player.getPosition();
    //if position out of bound
    if (rec_pos.getX() < 0 || rec_pos.getX() > 10 || rec_pos.getY() < 0 || rec_pos.getY() > 5) {
        cout << "This way is locked by the wall." << endl;
        player.setPosition(pre_pos.getX(), pre_pos.getY());
        return true;
    }
    
    //if it is available space
    if (dungeon.at(rec_pos.getX(), rec_pos.getY()) == CONSTANT::getSpot()) {
        dungeon.remove(pre_pos.getX(), pre_pos.getY());
        dungeon.push(player);
        player.setEnergy(player.getEnergy() - setEnergyLost(level));
    }
    else if (dungeon.at(rec_pos.getX(), rec_pos.getY()) == CONSTANT::getGem()) {
        //if player meets gems
        int index = 0; //holds index of gem in gem array
        //find the gem in the gem array to remove it later
        for (int i = 0; i < g_arr.size(); i++) {
            Position temp_pos = g_arr[i].getPosition();
            if (temp_pos == rec_pos) {
                index = i;
                break;
            }
        }
        //remove the player in previous position
        dungeon.remove(pre_pos.getX(), pre_pos.getY());
        //remove the gem in recent position
        dungeon.remove(rec_pos.getX(), rec_pos.getY());
        //the gem is disappeared then remove it from the gem array
        g_arr.erase(g_arr.begin() + index);
        Log("Found a gem.");
        Log("Found a gem.", false);
        gems++;
        //player get points
        points += CONSTANT::getPointsGem();
        //push player to recent position
        dungeon.push(player);
        player.setEnergy(player.getEnergy() - setEnergyLost(level));
        
        //right now Secret passage appear in random place if no gems exist
        if (g_arr.size() <= 0) {
            //Log
            Log("All gems collected from the cave, a secret doorway opened!");
            //create random secret passage
            int x = 0;
            int y = 0;
            do {
                x = rand() % 11;
                y = rand() % 6;
            } while (dungeon.at(x, y) != CONSTANT::getSpot());
            Entrance entrance(x, y);
            dungeon.push(entrance);
        }
    }
    else if (dungeon.at(rec_pos.getX(), rec_pos.getY()) == CONSTANT::getMonster()) {
        //if player meets monsters
        int index = 0; //holds index of monster in monster array
        //find monster in the array to remove it if it dies
        for (int i = 0; i < m_arr.size(); i++) {
            Position temp_pos = m_arr[i].getPosition();
            if (temp_pos == rec_pos) {
                index = i;
                break;
            }
        }
        player.setEnergy(player.getEnergy() - setEnergyLost(level));
        //if player gets killed when facing the monster
        if (player.isKilled(m_arr[index])) {
            //log
            Log("Engaged the monster and get killed.");
            Log("Engaged the monster and get killed.", false);
            //delete player in previous position
            dungeon.remove(pre_pos.getX(), pre_pos.getY());
            level--;
            return false;
        }
        else {
            //player kills the monster
            //log
            Log("Engaged and slayed the monster.");
            Log("Engaged and slayed the monster.", false);
            //delete player in previous position
            dungeon.remove(pre_pos.getX(), pre_pos.getY());
            //remove monster in recent position
            dungeon.remove(rec_pos.getX(), rec_pos.getY());
            //the monster is disappeared then remove it from the monster array
            m_arr.erase(m_arr.begin() + index);
            //player gets points for killing monsters
            points += CONSTANT::getPointsMonster();
            //push player to recent position
            dungeon.push(player);
        }
    }
    else if (dungeon.at(rec_pos.getX(), rec_pos.getY()) == CONSTANT::getApple()) {
        //if player meets magic apples
        //log
        Log("Ate a magic apple.");
        Log("Ate a magic apple", false);
        int index = 0; //holds index of apple in monster array
        //find apple in the array to remove it if it dies
        for (int i = 0; i < a_arr.size(); i++) {
            Position temp_pos = a_arr[i].getPosition();
            if (temp_pos == rec_pos) {
                index = i;
                break;
            }
        }
        //player eats apple
        player.meet(a_arr[index]);
        //if player eats apple then apple disappear
        //delete player in previous position
        dungeon.remove(pre_pos.getX(), pre_pos.getY());
        //remove apple in recent position
        dungeon.remove(rec_pos.getX(), rec_pos.getY());
        //the apple is disappeared then remove it from the apple array
        a_arr.erase(a_arr.begin() + index);
        //player gets points for eating apples
        points += CONSTANT::getPointsApple();
        //push player to recent position
        dungeon.push(player);
        player.setEnergy(player.getEnergy() - setEnergyLost(level));
    }
    else if (dungeon.at(rec_pos.getX(), rec_pos.getY()) == CONSTANT::getWall()) {
        cout << "This way is locked by the wall." << endl;
        player.setPosition(pre_pos.getX(), pre_pos.getY());
    }
    else {
        //only entrance here
        //delete player in previous position
        dungeon.remove(pre_pos.getX(), pre_pos.getY());
        //remove entrance in recent position
        dungeon.remove(rec_pos.getX(), rec_pos.getY());
        //player gets points
        points += CONSTANT::getPointsPass();
        //push player to that position
        dungeon.push(player);
        player.setEnergy(player.getEnergy() - setEnergyLost(level));
        return false;
    }
    return true;
}

int GamePlay::setEnergyLost(int level) {
    switch (level) {
        case 1:
            return CONSTANT::getEnergyLost1st();
            break;
        case 2:
            return CONSTANT::getEnergyLost2nd();
            break;
        case 3:
            return CONSTANT::getEnergyLost3rd();
            break;
        case 4:
            return CONSTANT::getEnergyLost4th();
            break;
        case 5:
            return CONSTANT::getEnergyLost5th();
            break;
        case 6:
            return CONSTANT::getEnergyLost6th();
            break;
        case 7:
            return CONSTANT::getEnergyLost7th();
            break;
        case 8:
            return CONSTANT::getEnergyLost8th();
            break;
        case 9:
            return CONSTANT::getEnergyLost9th();
            break;
        case 10:
            return CONSTANT::getEnergyLost10th();
            break;
        default:
            return 0;
            break;
    }
}
