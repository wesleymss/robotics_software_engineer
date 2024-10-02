from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os
from launch.actions import ExecuteProcess

def generate_launch_description():
    # Get the path to the 'custom_robots' package
    pkgPath = get_package_share_directory('module_3_assignment')

    # Specify the location of the URDF file within the package
    urdfFile = os.path.join(pkgPath, 'urdf', 'mobile.urdf')

    return LaunchDescription([
        # Node to publish the state of the robot to TF
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            arguments=[urdfFile]),
        # Node to publish the joint states of the robot, helping in visualizing the robot in RViz
        Node(
            package='joint_state_publisher',
            executable='joint_state_publisher',
            name='joint_state_publisher',
            arguments=[urdfFile]),
        # Launch Gazebo with the ROS plugins required for simulation
        ExecuteProcess(
            cmd=['gazebo', '--verbose', '-s', 'libgazebo_ros_factory.so'],
            output='screen'),
        # Spawn the robot entity in Gazebo simulation from the URDF topic
        Node(
            package='gazebo_ros',
            executable='spawn_entity.py',
            name='robot_spawner',
            output='screen',
            arguments=["-topic", "/robot_description", "-entity", "ackerman_bot"])
    ])
