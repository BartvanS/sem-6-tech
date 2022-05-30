#include "behaviortree_cpp_v3/bt_factory.h"
#include <cstdio>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "nodes.h"
#include "conditions.h"
using namespace BT;
int main()
{
    // We use the BehaviorTreeFactory to register our custom nodes
    BehaviorTreeFactory factory;


    // actions
    factory.registerNodeType<SetLight>("SetLight");
    factory.registerNodeType<DisableLights>("DisableLights");
    factory.registerNodeType<EnableSensors>("EnableSensors");
    factory.registerNodeType<WaitTime>("WaitTime");
    factory.registerNodeType<AlwaysRunning>("AlwaysRunning");

    // conditions
    factory.registerSimpleCondition("AllRed2Sec", std::bind(AllRed2Sec));
    factory.registerSimpleCondition("SensorsEnabled", std::bind(SensorsEnabled));
    factory.registerSimpleCondition("DisableSensors", std::bind(DisableSensors));
    factory.registerSimpleCondition("AllRed", std::bind(AllRed));
    factory.registerSimpleCondition("CarDetected", std::bind(CarDetected));

    auto tree = factory.createTreeFromFile("/home/bart/Desktop/school/eigen/Behaviour trees /traffic_control/src/traffic_control_pkg/src/traffic_control_ontwerp.xml");
    tree.tickRoot();

    return 0;
}