#pragma once
#include "behaviortree_cpp_v3/action_node.h"
using BT::NodeStatus;
// ACTIONS
using namespace BT;
class SetLight : public BT::SyncActionNode
{
  public:
    SetLight(const std::string& name, const NodeConfiguration& config);       
    static BT::PortsList providedPorts();
    // You must override the virtual function tick()
    BT::NodeStatus tick() override;
};

class EnableSensors : public BT::SyncActionNode
{
  public:
    EnableSensors(const std::string& name);
    
    // You must override the virtual function tick()
    BT::NodeStatus tick() override;
};

class DisableSensors : public BT::SyncActionNode
{
  public:
    DisableSensors(const std::string& name);
    

    // You must override the virtual function tick()
    BT::NodeStatus tick() override;
};

class WaitTime : public BT::SyncActionNode
{
  long startTime = 0;
  NodeStatus nodeStatus = NodeStatus::FAILURE;
  public:
    WaitTime(const std::string& name, const NodeConfiguration& config);
    static BT::PortsList providedPorts();
    // You must override the virtual function tick()
    BT::NodeStatus tick() override;
};
class AlwaysRunning : public BT::SyncActionNode
{
  public:
    AlwaysRunning(const std::string& name);
    

    // You must override the virtual function tick()
    BT::NodeStatus tick() override;
};


