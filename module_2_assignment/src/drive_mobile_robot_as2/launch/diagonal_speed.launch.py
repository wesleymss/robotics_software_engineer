from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess

def generate_launch_description():

    turtlesim=Node(
        package='turtlesim',
        executable='turtlesim_node',
        name='turtlesim'
    )

    spawn_turtle2= ExecuteProcess(
        cmd = ['ros2', 'service', 'call', '/spawn', 'turtlesim/srv/Spawn', "\"{x: 1.0, y: 10.0, theta: 0.0, name: 'turtle2'}\""],
        name = 'spawn_turtle2',
        shell = True
    
    )

    spawn_turtle3= ExecuteProcess(
        cmd = ['ros2', 'service', 'call', '/spawn', 'turtlesim/srv/Spawn', "\"{x: 4.0, y: 8.0, theta: 0.0, name: 'turtle3'}\""],
        name = 'spawn_turtle3',
        shell = True
    )

    spawn_turtle4= ExecuteProcess(
        cmd = ['ros2', 'service', 'call', '/spawn', 'turtlesim/srv/Spawn', "\"{x: 8.0, y: 4.0, theta: 0.0, name: 'turtle4'}\""],
        name = 'spawn_turtle4',
        shell = True
    )

    spawn_turtle5= ExecuteProcess(
        cmd = ['ros2', 'service', 'call', '/spawn', 'turtlesim/srv/Spawn', "\"{x: 9.0, y: 2.0, theta: 0.0, name: 'turtle5'}\""],
        name = 'spawn_turtle5',
        shell = True
    )
    turtle_driver=Node(
        package='drive_mobile_robot_as2',
        executable='speed_turtle',
        name='turtle_driver'
        # parameters=[
        #     {'cmd_vel_topic': '/turtle2/cmd_vel'}
        # ]
    )

    turtle_driver2=Node(
        package='drive_mobile_robot_as2',
        executable='rotate',
        name='turtle_driver2',
        parameters=[
            {'cmd_vel_topic': '/turtle2/cmd_vel','speed': 5.0}
        ]
    )

    turtle_driver3=Node(
        package='drive_mobile_robot_as2',
        executable='speed_turtle',
        name='turtle_driver3',
        parameters=[
            {'cmd_vel_topic': '/turtle3/cmd_vel','speed': 1.0}
        ]
    )

    turtle_driver4=Node(
        package='drive_mobile_robot_as2',
        executable='speed_turtle',
        name='turtle_driver4',
        parameters=[
            {'cmd_vel_topic': '/turtle4/cmd_vel','speed': 2.0}
        ]
    )

    turtle_driver5=Node(
        package='drive_mobile_robot_as2',
        executable='rotate',
        name='turtle_driver5',
        parameters=[
            {'cmd_vel_topic': '/turtle5/cmd_vel','speed': 20.0}
        ]
    )


    return LaunchDescription([
        turtlesim,
        
        spawn_turtle2,
        spawn_turtle3,
        spawn_turtle4,
        spawn_turtle5,

        turtle_driver,
        turtle_driver2,
        turtle_driver3,
        turtle_driver4,
        turtle_driver5,

    ])