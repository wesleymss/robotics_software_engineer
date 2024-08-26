#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

class RotateNode : public rclcpp::Node
{
public:
    RotateNode()
    : Node("rotate_node"), speed_(0.2) // Default speed
    {
        this->declare_parameter<std::string>("cmd_vel_topic", "/turtle1/cmd_vel");
        this->declare_parameter<double>("speed", 0.2);

        std::string cmd_vel_topic = this->get_parameter("cmd_vel_topic").as_string();
        speed_ = this->get_parameter("speed").as_double();

        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>(cmd_vel_topic, 10);

        timer_ = this->create_wall_timer(
            500ms, [this]() { this->timer_callback(); });
    }

private:
    void timer_callback()
    {
        auto message = geometry_msgs::msg::Twist();
        message.linear.x = 0.0;
        message.angular.z = speed_;  // Set angular velocity from parameter

        RCLCPP_INFO(this->get_logger(), "Rotating Turtle at speed: %f", speed_);
        publisher_->publish(message);
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    double speed_;  // Variable to store the speed parameter
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<RotateNode>());
    rclcpp::shutdown();
    return 0;
}
