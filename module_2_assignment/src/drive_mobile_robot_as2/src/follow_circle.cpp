#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class Robotdriver : public rclcpp::Node
{
  public:
    Robotdriver()
    : Node("Robot_driver"), count_(0)
    {

      this->declare_parameter<std::string>("cmd_vel_topic","/turtle1/cmd_vel");
      std::string cmd_vel_topic = this->get_parameter("cmd_vel_topic").as_string();

      publisher_ = this->create_publisher<geometry_msgs::msg::Twist>(cmd_vel_topic, 10);
      timer_ = this->create_wall_timer(
      500ms, std::bind(&Robotdriver::timer_callback, this));
    }

  private:
    void timer_callback()
    {
      auto message = geometry_msgs::msg::Twist();
      message.linear.x = 0.4;
      message.angular.z = 0.5;

      RCLCPP_INFO(this->get_logger(), "Driving Turtle");
      publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Robotdriver>());
  rclcpp::shutdown();
  return 0;
}