# Assignments for Module #4 : Robot Sensing


### Task 1: Restructure Line Following Project Code 
How to run task 1 :
- perform the following 
```
colcon build
```
- Source your workspace
```
source install/setup.bash
```
- Run with this command

```
ros2 launch module_4_assignment line_following_launch.py
```
![Alt text](/module_4_assignment/task1.gif)
------------------------------------
### Task 2: 
-Design Software Flow for Maze Solving

-Create a software flow design for maze-solving:

-Draw the design by hand or online using tools like Excalidraw.

-Add the design to your GitHub repository.

![Screenshot description](/module_4_assignment/task2.png)

-----------------------------------

### Task 3: Implement Maze Solving in Gazebo
-Create a maze environment in Gazebo:

*The maze should have a square shape.

*The robot should keep the maze structure on its right while navigating.

*Detect the wall on the right using a LIDAR sensor.

*Utilize TurtleBot3’s IMU sensor to calculate:
-Velocity,Acceleration

How to run task 3 :
- perform the following 
```
colcon build
```
- Source your workspace
```
source install/setup.bash
```
- Run with this command

```
ros2 launch module_4_assignment square_line_following.launch.py
```
![Alt text](/module_4_assignment/task3.gif)

--------------------------------------

### Task 4: Fix Errors in Launch Files
Successfully run the robot_sensing_debug package by removing errors and:

Document the error debugging process.

Provide a summary of the errors encountered and how they were resolved.

### How to run task 4:

Download robot_sensing_debug package

### Summary of the Errors:

1. In the launch file: camera_line_following.launch.py

i. The package name has to be modified to "robot_sensing_debug".

ii. The spawn turtle package should be modified to "spawn_turtlebot3.launch.py".

iii. The path reference of model.sdf should be changed according to our host system.

iv. The default spawning x_pose and y_pose has to be adjusted:


x_pose = LaunchConfiguration('x_pose', default='-6.09')
y_pose = LaunchConfiguration('y_pose', default='2.07')


2. In the launch file: custom_sensors.launch.py

i. The package name has to be modified to "robot_sensing_debug".

3. In the launch file: lidar_maze_solving.launch.py

i. The package name has to be modified to "robot_sensing_debug".

ii. The laser scan topic name should be modified to subscribe to "/scan", 10.

iii. The conditions for MOVING_STRAIGHT, TURNING_LEFT, and TURNING_RIGHT, and the appropriate command.linear.x and command.angular.z values must be adjusted.


