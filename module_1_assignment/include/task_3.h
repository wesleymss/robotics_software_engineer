#ifndef SENSORLIBRARY_H
#define SENSORLIBRARY_H

#include <iostream>
#include <string> 
using namespace std;

class Sensor
{

private:
    string sensorName;

public:
    
    Sensor(const string& name);
    

    void readSensors();
    void calibrateSensors();

    
    template<typename T, typename U>
    void processSensorData(T data1, U data2) {
        cout << "Processing data: " << data1 << " and " << data2 << endl;
    }
    
};

#endif // SENSORLIBRARY_H



