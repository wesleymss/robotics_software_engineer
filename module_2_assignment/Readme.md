# Assignments for Module #2 : ROS2 2D Turlesim Simulation


## Task 1: Create a Custom ROS 2 Node
• Develop a ROS 2 node that makes the Turtlesim follow a unique pattern:
1. Circle Movement: The turtle should move in a circle with a radius that is provided as a user input.
2. Logarithmic Spiral Movement: The turtle should move in a logarithmic spiral pattern.

## How to run task1 :



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
ros2 run turtlesim turtlesim_node 
```
- open another terminal and run with this command (circle movement)
```
ros2 run module_2_assignment follow_circle
```
-   for logarithmic spiral movement
```
ros2 run module_2_assignment logarithmic_spiral 
```

## Task 2: Develop a Launch File
• Create a launch file that starts the Turtlesim simulation and the custom ROS 2 node simultaneously.


• Ensure proper documentation of the node and launch file creation process, including the code and the results of executing the tasks.

## How to run task2 :



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
ros2 launch module_2_assignment follow_circle.launch.py
```
- logarithmic spiral use 
```
ros2 launch module_2_assignment logarithmic_spiral.launch.py
```

#### Note:
Using the above launch file, we can invoke two nodes such as turtlesim node and turtle_driver simultaneously.  



## Task 3: Modify the Turtlesim Simulation Environment
• Use existing Turtlesim services such as spawn and clear to modify the simulation environment:
- Spawn 5 Turtlebots with a single launch file, placing them diagonally from the top left to the bottom right.
- Drive the middle 3 turtles back and forth continuously using ROS 2 services.


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
ros2 launch module_2_assignment spawn_diagonal.launch.py
```

## Task 4: Modify Turtle Behavior with Parameters
• Utilize ROS 2 parameters to alter the behavior of the turtles:
Change the speed of the turtles dynamically during the simulation.

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
ros2 launch module_2_assignment diagonal_speed.launch.py
````

#### Thank you