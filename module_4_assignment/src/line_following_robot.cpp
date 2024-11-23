#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "cv_bridge/cv_bridge.h"
#include "opencv2/opencv.hpp"

class CameraSubscriber : public rclcpp::Node
{
public:
  CameraSubscriber()
      : Node("camera_subscriber_node"), angularVel_(0.3)
  {
    this->declare_parameter<int>("lower_threshold", 200);
    this->declare_parameter<int>("upper_threshold", 250);
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
    subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
        "/camera/image_raw", 10,
        std::bind(&CameraSubscriber::cameraCallback, this, std::placeholders::_1));
    RCLCPP_INFO(this->get_logger(), "\n------ Node Started -----\n");
  }

private:
  void cameraCallback(const sensor_msgs::msg::Image::SharedPtr cameraMsg)
  {
    auto velocityMsg = geometry_msgs::msg::Twist();
    cv_bridge::CvImagePtr cvPtr;
    cvPtr = cv_bridge::toCvCopy(cameraMsg, "bgr8");
    cv::Mat grayImage, cannyImage;
    cv::cvtColor(cvPtr->image, grayImage, cv::COLOR_BGR2GRAY);

    int upperThreshold_ = this->get_parameter("upper_threshold").as_int();
    int lowerThreshold_ = this->get_parameter("lower_threshold").as_int();
    cv::Canny(grayImage, cannyImage, lowerThreshold_, upperThreshold_);

    int row_ = 150, column_ = 0;
    cv::Mat roi_ = cannyImage(cv::Range(row_, row_ + 240), cv::Range(column_, column_ + 640));

    std::vector<int> edge_;
    for (int i_ = 0; i_ < 640; ++i_)
    {
      if (roi_.at<uchar>(160, i_) == 255)
      {
        edge_.push_back(i_);
      }
    }

    if (!edge_.empty())
    {
      int midArea_ = edge_.back() - edge_.front();
      int midPoint_ = edge_.front() + midArea_ / 2;
      int robotMidPoint_ = 640 / 2;

      // Calculate error and adjust robot's direction
      double error_ = robotMidPoint_ - midPoint_;
      velocityMsg.linear.x = 0.1;
      if (error_ < 0)
      {
        velocityMsg.angular.z = -angularVel_;
      }
      else
      {
        velocityMsg.angular.z = angularVel_;
      }

      publisher_->publish(velocityMsg);

      // Visualization
      cv::circle(roi_, cv::Point(midPoint_, 160), 2, cv::Scalar(255, 255, 255), -1);
      cv::circle(roi_, cv::Point(robotMidPoint_, 160), 5, cv::Scalar(255, 255, 255), -1);
      cv::imshow("Image", roi_);
      cv::waitKey(1);
    }
  }

  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
  double angularVel_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CameraSubscriber>());
  rclcpp::shutdown();
  return 0;
}
