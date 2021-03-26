#pragma once
#include "TreasureHuntingLib.h"

class CurrentTime {
protected:
    static const string getCurrentDateTime() {
        // Some computation here
        auto end = chrono::system_clock::now();

        time_t end_time = chrono::system_clock::to_time_t(end);

        string time_in_string = ctime(&end_time);
        //remove \n in the string
        time_in_string.erase(remove(time_in_string.begin(), time_in_string.end(), '\n'),
                    time_in_string.end());
        return time_in_string;
    }
};
