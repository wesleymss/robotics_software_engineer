#include "task_3.h"

int main()
{
    string tempName = "Temperature";
    Sensor temperatureSensor(tempName);
    temperatureSensor.readSensors();
    temperatureSensor.calibrateSensors();
    temperatureSensor.processSensorData(2000.50, 3000.5);
    temperatureSensor.processSensorData("VERY", "HIGH");
    temperatureSensor.processSensorData('T', 'F');


    cout<<"************************************"<<endl;
    string distName = "Distance";
    Sensor distanceSensor(distName);
    distanceSensor.readSensors();
    distanceSensor.calibrateSensors();
    distanceSensor.processSensorData(2000.50,3000.5);
    distanceSensor.processSensorData("VERY", "HIGH");
    distanceSensor.processSensorData('T', 'F');

    return 0;
}
