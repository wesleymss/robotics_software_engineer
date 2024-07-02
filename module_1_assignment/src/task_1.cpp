#include <iostream>
using namespace std;

void SensorReading(int tempSensorReading[5], int distanceSensorReading[5])
{

    for (int i = 0; i < 5; i++)
    {

        cout << "Temperature: " << tempSensorReading[i] << "°C" << endl;
        cout << "Distance: " << distanceSensorReading[i] << "cm" << endl;
        for (int j = 0; j < 50000; j++)
        {
            for (int k = 0; k < 50000; k++); // delay
        }
    }
}

int main()
{

    int tempSensorReading[5] = {10, 20, 30, 40, 50};
    int distanceSensorReading[5] = {100, 50, 75, 25, 150};

    SensorReading(tempSensorReading, distanceSensorReading);

    return 0;
}
