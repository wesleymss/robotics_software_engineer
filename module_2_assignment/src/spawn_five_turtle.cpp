#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

class RobotDriver : public rclcpp::Node
{
public:
    RobotDriver()
    : Node("robot_driver"), count_(0), forward_(true)
    {
        this->declare_parameter<std::string>("cmd_vel_topic", "/turtle1/cmd_vel");
        std::string cmd_vel_topic = this->get_parameter("cmd_vel_topic").as_string();

        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>(cmd_vel_topic, 10);
        timer_ = this->create_wall_timer(
            500ms, std::bind(&RobotDriver::timer_callback, this));
    }

private:
    void timer_callback()
    {
        auto message = geometry_msgs::msg::Twist();
        
        // Alternate between forward and backward motion
        if (forward_)
        {
            message.linear.x = 0.2;  // Move forward
        }
        else
        {
            message.linear.x = -0.2; // Move backward
        }
        
        message.angular.z = 0.0;  // No rotation for back-and-forth motion

        RCLCPP_INFO(this->get_logger(), "Driving Turtle: %s", forward_ ? "Forward" : "Backward");
        publisher_->publish(message);

        // Reverse direction every 10 iterations (5 seconds)
        count_++;
        if (count_ >= 10)
        {
            forward_ = !forward_;
            count_ = 0;
        }
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    size_t count_;
    bool forward_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<RobotDriver>());
    rclcpp::shutdown();
    return 0;
}
