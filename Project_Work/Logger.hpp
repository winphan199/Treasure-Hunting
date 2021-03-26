#pragma once
#include "TreasureHuntingLib.h"
#include "CurrentTime.hpp"
class Logger: protected CurrentTime
{
private:
    static vector<string> _records; // acts as log file.
protected:
    //we don't want unauthorized object to access records so
    //this function gets records stored.
    static void getRecords();
public:
    
    //behaviors
    //this function logs the information to console when echo = true
    static void Log(string info, bool echo = true);
    
    //destructor
    ~Logger();
};
