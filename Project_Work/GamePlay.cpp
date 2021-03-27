#include "GamePlay.h"

//this function implements the game
void GamePlay::gameLoop() {
    
    //Create Dungeon
    Dungeon dungeon;
    
    //Greetings
    Log("Welcome to the Treasure Hunt!");
    Log("Entered into the magical dungeon, good Luck!");
    
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
        Log(status);
        //print dungeon
        dungeon.setLevel(level);
        dungeon.printDungeon();
        //log action instruction to console
        fflush(stdin);
        cout << "Please select action (move with wasd or Q to escape) > ";
        cin >> input;
        
        //log the detail of what player chooses
        if (input[0] == 'w' || input[0] == 'W') {
            Log("Moving up.");
            moves++;
        }
        else if (input[0] == 'a' || input[0] == 'A') {
            Log("Moving left.");
            moves++;
        }
        else if (input[0] == 's' || input[0] == 'S') {
            Log("Moving down.");
            moves++;
        }
        else if (input[0] == 'd' || input[0] == 'D') {
            Log("Moving right.");
            moves++;
        }
        else if (input[0] == 'q' || input[0] == 'Q') {
            
            //exit the game which means exit the loop
            break;
        }
        else {
            //unknown character
            Log("Unknown action.");
        }
    }
    //log the log file
    string sum_up = "Congratulations! You have successfully escaped from the " + to_string(level) + "-level\ndungeon after " + to_string(moves) + " moves, with " + to_string(gems) + " gems and total " + to_string(points) + " points.";
    Log(sum_up);
    Log("You feel relaxed, breathe the fresh air and hold tightly to your treasures!");
    Log("Brief adventure history:");

    getRecords();
}
