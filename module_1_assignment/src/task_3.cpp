#include "task_3.h"

Sensor::Sensor(const string &name) : sensorName(name)
{
    cout << sensorName << " sensor is initialized." << endl;


}

void Sensor::readSensors()
{
    cout << "Reading " << sensorName << " sensor values..." << endl;
}

void Sensor::calibrateSensors()
{
    cout << "Calibrating " << sensorName << " sensor values..." << endl;
}




