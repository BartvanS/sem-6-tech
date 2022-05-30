cmake_minimum_required(VERSION 3.5)
project(traffic_control_pkg)

#Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(behaviortree_cpp_v3 REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
# include_directories(src)

add_executable(main src/main.cpp src/nodes.cpp src/conditions.cpp)
ament_target_dependencies(main behaviortree_cpp_v3 rclcpp std_msgs)

install(TARGETS
  main
  DESTINATION lib/${PROJECT_NAME})

ament_package()
