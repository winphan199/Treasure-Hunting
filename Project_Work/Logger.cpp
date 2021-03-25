#include "Logger.hpp"

void Logger::Log(string info, bool echo) {
    //if echo = true -> the information is printed to console.
    //if echo = false -> the information is stored in record.
    if (echo == true) {
        cout << info << endl;
    }
    else {
        _records.push_back(info);
    }
}

void Logger::getRecords() {
    for (int i = 0; i < _records.size(); i++) {
        cout << _records.at(i);
    }
}

Logger::~Logger() {
    _records.clear();
}
