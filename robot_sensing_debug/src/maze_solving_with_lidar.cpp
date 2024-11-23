#include <geometry_msgs/msg/twist.hpp>
#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <algorithm>

enum class RobotState {
  MOVING_STRAIGHT,
  TURNING_LEFT,
  TURNING_RIGHT,
  OUT_OF_MAZE
};

class MazeSolving : public rclcpp::Node {
public:
  MazeSolving() : Node("maze_solver"), state_(RobotState::MOVING_STRAIGHT) {
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
    subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
        "/scan", 10,
        std::bind(&MazeSolving::lidarCallback, this, std::placeholders::_1));
    RCLCPP_INFO(this->get_logger(), "Maze solver node started.");
  }

private:
  void lidarCallback(const sensor_msgs::msg::LaserScan::SharedPtr lidarMsg) {
    RCLCPP_INFO(this->get_logger(), "LIDAR callback triggered");

    float rightObstacle = *std::max_element(lidarMsg->ranges.begin() + 260, lidarMsg->ranges.begin() + 280);
    float frontObstacle = *std::max_element(lidarMsg->ranges.begin() + 340, lidarMsg->ranges.begin() + 360);
    float leftObstacle = *std::max_element(lidarMsg->ranges.begin() + 80, lidarMsg->ranges.begin() + 100);

    RCLCPP_INFO(this->get_logger(), "Front: %f, Right: %f, Left: %f", frontObstacle, rightObstacle, leftObstacle);

    if (frontObstacle < frontThreshold_ && rightObstacle < frontThreshold_ && leftObstacle < frontThreshold_) {
      state_ = RobotState::OUT_OF_MAZE;
    } else if (frontObstacle < frontThreshold_) {
      state_ = leftObstacle < rightObstacle ? RobotState::TURNING_RIGHT : RobotState::TURNING_LEFT;
    } else {
      state_ = RobotState::MOVING_STRAIGHT;
    }

    geometry_msgs::msg::Twist command;
    switch (state_) {
    case RobotState::MOVING_STRAIGHT:
      command.linear.x = linearVel_;
      command.angular.z = 0.0;
      RCLCPP_INFO(this->get_logger(), "State: MOVING_STRAIGHT, Linear Vel: %f, Angular Vel: %f", command.linear.x, command.angular.z);
      break;
    case RobotState::TURNING_LEFT:
      command.linear.x = 0.0;
      command.angular.z = angularVel_;
      RCLCPP_INFO(this->get_logger(), "State: TURNING_LEFT, Linear Vel: %f, Angular Vel: %f", command.linear.x, command.angular.z);
      break;
    case RobotState::TURNING_RIGHT:
      command.linear.x = 0.0;
      command.angular.z = -angularVel_;
      RCLCPP_INFO(this->get_logger(), "State: TURNING_RIGHT, Linear Vel: %f, Angular Vel: %f", command.linear.x, command.angular.z);
      break;
    case RobotState::OUT_OF_MAZE:
      command.linear.x = 0.0;
      command.angular.z = 0.0;
      RCLCPP_INFO(this->get_logger(), "State: OUT_OF_MAZE, Stopping robot");
      break;
    }

    RCLCPP_INFO(this->get_logger(), "Publishing cmd_vel: linear.x = %f, angular.z = %f", command.linear.x, command.angular.z);
    publisher_->publish(command);
  }

  float frontThreshold_ = 1.5f;
  float angularVel_ = 0.8f;
  float linearVel_ = 0.6f;
  RobotState state_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscription_;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MazeSolving>());
  rclcpp::shutdown();
  return 0;
}
