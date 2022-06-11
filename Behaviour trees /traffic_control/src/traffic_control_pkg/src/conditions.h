#pragma once
#include "behaviortree_cpp_v3/action_node.h"
using BT::NodeStatus;
NodeStatus AllRed2Sec();
NodeStatus SensorsEnabled();
NodeStatus AllRed();
NodeStatus CarDetected();
NodeStatus OperatorModeRegular();
class OperatorModeSet : public BT::SyncActionNode
{
private:
    bool isSet = false;
public:
    OperatorModeSet(const std::string &name);

    // You must override the virtual function tick()
    NodeStatus tick() override;
};