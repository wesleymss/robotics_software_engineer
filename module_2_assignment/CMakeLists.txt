cmake_minimum_required(VERSION 3.8)
project(module_2_assignment)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)



add_executable(follow_circle src/follow_circle.cpp)
ament_target_dependencies(follow_circle rclcpp geometry_msgs)

add_executable(logarithmic_spiral src/logarithmic_spiral.cpp)
ament_target_dependencies(logarithmic_spiral rclcpp geometry_msgs)

add_executable(spawn_five_turtle src/spawn_five_turtle.cpp)
ament_target_dependencies(spawn_five_turtle rclcpp geometry_msgs)

add_executable(rotate src/rotate.cpp)
ament_target_dependencies(rotate rclcpp geometry_msgs)

add_executable(speed_turtle src/speed_turtle.cpp)
ament_target_dependencies(speed_turtle rclcpp geometry_msgs)

install(TARGETS
  follow_circle logarithmic_spiral spawn_five_turtle rotate speed_turtle
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()