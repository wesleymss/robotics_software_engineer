# Assignments for Module #3 : Robot structure with URDF



### Assignment 1: Robotic Arm Creation using TF
Create a custom transform tree for a
    - Robotics arm of 3 DOF without body ( only transforms)
    - visualize it in rviz + utilize joint state publisher GUI to see transforms
    - You should not have any visualize tag filled yet.

## How to run Assignment 1 :
- perform the following 
```
colcon build
```
- Source your workspace
```
source install/setup.bash
```
- Run with this command

````
ros2 launch module_3_assignment task1_rviz.launch.py 
````
- Rviz will be launched 
- Choose base_link as fixed frame
- Add tf for viewing the transformation tree for the robotic arm.
------------------------------------------------------------------------------------------
### Assignment 2: Joints Understanding
- **Tasks**:
Add joints to the same Robotic Arm that you created earlier
    - Finger joints with prismatic joint type
    - Have base joint as continous
    - All other joints should be Revolute
    - Add visualize tag to your robot urdf and create body mostly using cylinders

## How to run Assignment 2 :

- perform the following 
```
colcon build
```
- Source your workspace
```
source install/setup.bash
```
- Run with this command

````
ros2 launch module_3_assignment task2_rviz.launch.py
````
- Rviz will be launched 
- Choose base_link as fixed frame
- Add RobotModel from Rviz2
    - under Description Topic, choose /robot_description
- Add tf for viewing the transformation tree for the robotic arm.

-----------------------------------------------------------------------------------------

### Assignment 3: Building Mobile Manipulator
- **Tasks**:
Put your robotic arm on top of different drive robot
    - Connect using base_link of diff bot.
## How to run Assignment 3 :

- perform the following 
```
colcon build
```
- Source your workspace
```
source install/setup.bash
```
- Run with this command

````
ros2 launch module_3_assignment task3_rviz.launch.py
````

![Screenshot description](/module_3_assignment/ackermannarm.png)

- Rviz will be launched 
- Choose base_link as fixed frame
- Add RobotModel from Rviz2
    - under Description Topic, choose /robot_description
- Add tf for viewing the transformation tree for the robotic arm.