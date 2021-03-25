#include "GamePlay.h"

//this function implements the game
void GamePlay::gameLoop() {
    
    //Create Dungeon
    Dungeon dungeon;
    
    //Greetings
    Logger::Log("Welcome to the Treasure Hunt!");
    Logger::Log("Entered into the magical dungeon, good Luck!");
    
    //create a player
    
    //setLevel, player energy, points, moves, input field, gems
    int level = 1;
    int points = 0;
    int moves = 0;
    int gems = 0;
    string input = "";
    //game status
    string status = "Level: " + to_string(level) + "; Player energy: 100%; Points: " + to_string(points);
    while (level < CONSTANT::getMaxLevel()) {
        //loop until the maximum level reached.
        //log status
        Logger::Log(status);
        //print dungeon
        dungeon.setLevel(level);
        dungeon.printDungeon();
        //log action instruction to console
        fflush(stdin);
        cout << "Please select action (move with wasd or Q to escape) > ";
        cin >> input;
        
        //log the detail of what player chooses
        if (input[0] == 'w' || input[0] == 'W') {
            Logger::Log("Moving up.");
            moves++;
        }
        else if (input[0] == 'a' || input[0] == 'A') {
            Logger::Log("Moving left.");
            moves++;
        }
        else if (input[0] == 's' || input[0] == 'S') {
            Logger::Log("Moving down.");
            moves++;
        }
        else if (input[0] == 'd' || input[0] == 'D') {
            Logger::Log("Moving right.");
            moves++;
        }
        else if (input[0] == 'q' || input[0] == 'Q') {
            
            //exit the game which means exit the loop
            break;
        }
        else {
            //unknown character
        }
    }
    //log the log file
    string sum_up = "Congratulations! You have successfully escaped from the " + to_string(level) + "-level\ndungeon after " + to_string(moves) + " moves, with " + to_string(gems) + " gems and total " + to_string(points) + " points.";
    Logger::Log(sum_up);
    Logger::Log("You feel relaxed, breathe the fresh air and hold tightly to your treasures!");
    Logger::Log("Brief adventure history:");
    Logger::getRecords();
}
