#include <iostream>
#include <string>

using namespace std;

namespace Robot {

    class Robot {
    public:
        
        Robot(string name, int speed, int weight, int size, int numberOfSensors)
            : name(name), speed(speed), weight(weight), size(size), numberOfSensors(numberOfSensors) {
            
            cout << " Name of the robot    : " << name << " robot" << endl;
            cout << "             Speed    : " << speed << " km/hr" << endl;
            cout << "            Weight    : " << weight << " kg" << endl;
            cout << "              Size    : " << size << " m" << endl;
            cout << " Number of Sensors    : " << numberOfSensors << endl;
        }

       
        void moveForward() {
            cout << name << " robot is moving forward at the speed of " << speed << " km/hr..." << endl;
        }

        void moveBackward() {
            cout << name << " robot is moving backward at the speed of " << speed/2 << " km/hr..." << endl;
        }

        void stop() {
            cout << name << " robot is halting..." << endl;
        }

    private:
        string name;
        int speed;
        int weight;
        int size;
        int numberOfSensors;
    };

}

namespace Robot::Wheeled {

    class WheeledRobot : public Robot {
    public:
        WheeledRobot(string name, int speed, int weight, int size, int numberOfSensors)
            : Robot(name, speed, weight, size, numberOfSensors){

                cout<< name << " robot is initializing" <<endl;
            }
    };

}

namespace Robot::Legged {

    class LeggedRobot : public Robot {
    public:
        LeggedRobot(string name, int speed, int weight, int size, int numberOfSensors)
            : Robot(name, speed, weight, size, numberOfSensors){

                cout<< name << " robot is initializing" <<endl;
            }
    };

}

int main() {

    
    Robot::Wheeled::WheeledRobot mobile("jetbot", 50, 20, 10, 5);
    mobile.moveForward();
    mobile.moveBackward();
    mobile.stop();

    cout << "******"<< endl;

    
    Robot::Legged::LeggedRobot leg("hexapod", 10, 30, 15, 8);
    leg.moveForward();
    leg.moveBackward();
    leg.stop();

    cout << "******"<< endl;

    return 0;
}
