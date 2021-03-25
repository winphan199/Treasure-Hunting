#pragma once
#include "TreasureHuntingLib.h"

class Logger {
private:
    static vector<string> _records; // acts as log file.
public:
    
    //behaviors
    //this function logs the information to console when echo = true
    static void Log(string info, bool echo = true);
    
    //this function gets records stored.
    static void getRecords();
    
    //destructor
    ~Logger();
};
