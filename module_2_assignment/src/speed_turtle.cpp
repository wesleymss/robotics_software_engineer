#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

class RobotDriver : public rclcpp::Node
{
public:
    RobotDriver()
    : Node("robot_driver"), count_(0), forward_(true)
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

        // Alternate between forward and backward motion
        if (forward_)
        {
            message.linear.x = speed_;  // Move forward with the specified speed
        }
        else
        {
            message.linear.x = -speed_; // Move backward with the specified speed
        }
        
        message.angular.z = 0.0;  // No rotation for back-and-forth motion

        RCLCPP_INFO(this->get_logger(), "Driving Turtle: %s at speed: %f", 
                    forward_ ? "Forward" : "Backward", speed_);
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
    double speed_;  // Variable to store the speed parameter
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<RobotDriver>());
    rclcpp::shutdown();
    return 0;
}
