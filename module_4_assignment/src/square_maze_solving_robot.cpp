#include <iostream>
#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <cmath>
#include <algorithm>

enum class RobotState {
  MOVING_STRAIGHT,
  TURNING_LEFT,
  TURNING_RIGHT,
  ADJUSTING_LEFT,
  ADJUSTING_RIGHT,
  OUT_OF_MAZE
};

class MazeSolver : public rclcpp::Node {
public:
  MazeSolver() : Node("maze_solver") {
    _publisher = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
    _subscription = this->create_subscription<sensor_msgs::msg::LaserScan>(
        "/scan", 10, std::bind(&MazeSolver::lidarCallback, this, std::placeholders::_1));
    _imu_subscription = this->create_subscription<sensor_msgs::msg::Imu>(
        "/imu", 10, std::bind(&MazeSolver::imuCallback, this, std::placeholders::_1));
    _state = RobotState::MOVING_STRAIGHT;
  }

private:
  void lidarCallback(const sensor_msgs::msg::LaserScan::SharedPtr lidar_msg) {
    analyzeObstacles(lidar_msg);
    determineState();
    publishVelocity();
  }

  void imuCallback(const sensor_msgs::msg::Imu::SharedPtr imu_msg) {
    _linear_acceleration = std::sqrt(std::pow(imu_msg->linear_acceleration.x, 2) +
                                     std::pow(imu_msg->linear_acceleration.y, 2) +
                                     std::pow(imu_msg->linear_acceleration.z, 2));

    _angular_velocity = std::sqrt(std::pow(imu_msg->angular_velocity.x, 2) +
                                  std::pow(imu_msg->angular_velocity.y, 2) +
                                  std::pow(imu_msg->angular_velocity.z, 2));

    RCLCPP_INFO(this->get_logger(), "Linear Acceleration: %f, Angular Velocity: %f",
                _linear_acceleration, _angular_velocity);
  }

  void analyzeObstacles(const sensor_msgs::msg::LaserScan::SharedPtr lidar_msg) {
    _right_obstacle = *std::min_element(lidar_msg->ranges.begin() + 260, lidar_msg->ranges.begin() + 280);
    _front_obstacle = *std::min_element(lidar_msg->ranges.begin() + 340, lidar_msg->ranges.begin() + 360);
    _left_obstacle = *std::min_element(lidar_msg->ranges.begin() + 80, lidar_msg->ranges.begin() + 100);

    RCLCPP_INFO(this->get_logger(), "Front: %f, Right: %f, Left: %f", 
                _front_obstacle, _right_obstacle, _left_obstacle);
  }

  void determineState() {
    if (_state == RobotState::OUT_OF_MAZE) {
      return;
    }

    if (_front_obstacle < _frontThreshold) {
      if (_left_obstacle < _right_obstacle) {
        _state = RobotState::TURNING_RIGHT;
      } else {
        _state = RobotState::TURNING_LEFT;
      }
    } else if (_right_obstacle < _minRightDistance) {
      _state = RobotState::ADJUSTING_LEFT;
    } else if (_right_obstacle > _targetRightDistance) {
      _state = RobotState::ADJUSTING_RIGHT;
    } else {
      _state = RobotState::MOVING_STRAIGHT;
    }
  }

  void publishVelocity() {
    switch (_state) {
      case RobotState::MOVING_STRAIGHT:
        _command.linear.x = _linearVel;
        _command.angular.z = 0.0;
        RCLCPP_INFO(this->get_logger(), "Moving Straight");
        break;
      case RobotState::TURNING_LEFT:
        _command.linear.x = 0.0;
        _command.angular.z = _angularVel;
        RCLCPP_INFO(this->get_logger(), "Turning Left");
        break;
      case RobotState::TURNING_RIGHT:
        _command.linear.x = 0.0;
        _command.angular.z = -_angularVel;
        RCLCPP_INFO(this->get_logger(), "Turning Right");
        break;
      case RobotState::ADJUSTING_LEFT:
        _command.linear.x = _linearVel;
        _command.angular.z = 0.3; // Adjust left
        RCLCPP_INFO(this->get_logger(), "Adjusting Left");
        break;
      case RobotState::ADJUSTING_RIGHT:
        _command.linear.x = _linearVel;
        _command.angular.z = -0.3; // Adjust right
        RCLCPP_INFO(this->get_logger(), "Adjusting Right");
        break;
      case RobotState::OUT_OF_MAZE:
        _command.linear.x = 0.0;
        _command.angular.z = 0.0;
        RCLCPP_INFO(this->get_logger(), "Out of Maze, Stopping");
        break;
    }
    _publisher->publish(_command);
  }

  float _frontThreshold = 1.5f;
  float _minRightDistance = 0.7f; // Minimum distance to the right wall
  float _angularVel = 0.8f;
  float _linearVel = 0.6f;
  float _targetRightDistance = 1.0f; // Target distance from the right wall to avoid collision
  float _right_obstacle, _front_obstacle, _left_obstacle;
  float _linear_acceleration, _angular_velocity;
  geometry_msgs::msg::Twist _command;
  RobotState _state;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr _publisher;
  rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr _subscription;
  rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr _imu_subscription;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MazeSolver>());
  rclcpp::shutdown();
  return 0;
}
