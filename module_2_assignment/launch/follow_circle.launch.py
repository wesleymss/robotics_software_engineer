from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():


    turtlesim =Node(
        package='turtlesim',
        executable='turtlesim_node',
        name='turtlesim'
    )
    turtle_driver=Node(
        package='module_2_assignment',
        executable='follow_circle',
        name='turtle_driver'
    )

    

    return LaunchDescription([ 
        turtlesim, 
        turtle_driver,  
    ])