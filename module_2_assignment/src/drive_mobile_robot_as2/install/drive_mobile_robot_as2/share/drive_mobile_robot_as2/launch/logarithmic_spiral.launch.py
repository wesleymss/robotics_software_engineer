from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():


    turtlesim =Node(
        package='turtlesim',
        executable='turtlesim_node',
        name='turtlesim'
    )
    turtle_driver2=Node(
        package='drive_mobile_robot_as2',
        executable='logarithmic_spiral',
        name='turtle_driver2'
    )

    

    return LaunchDescription([ 
        turtlesim, 
        turtle_driver2,  
    ])