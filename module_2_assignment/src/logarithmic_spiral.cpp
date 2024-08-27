#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <cmath> 

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

class RobotDriver : public rclcpp::Node
{
public:
    RobotDriver()
    : Node("robot_driver"), count_(0)
    {
        this->declare_parameter<std::string>("cmd_vel_topic", "/turtle1/cmd_vel");
        std::string cmd_vel_topic = this->get_parameter("cmd_vel_topic").as_string();

        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>(cmd_vel_topic, 10);
        timer_ = this->create_wall_timer(
            100ms, std::bind(&RobotDriver::timer_callback, this));
    }

private:
    void timer_callback()
    {
        auto message = geometry_msgs::msg::Twist();
        
      
        double a = 0.5; 
        double b = 0.9; 

      
        double theta = count_ * 0.01;

        
        message.linear.x = a * exp(b * theta);  
        message.angular.z = b;                   

        RCLCPP_INFO(this->get_logger(), "Driving Turtle in a Spiral: linear.x=%.2f angular.z=%.2f", message.linear.x, message.angular.z);
        publisher_->publish(message);

        count_++;
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    size_t count_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<RobotDriver>());
    rclcpp::shutdown();
    return 0;
}
