#pragma once
#include "behaviortree_cpp_v3/action_node.h"
using BT::NodeStatus;
NodeStatus AllRed2Sec();
NodeStatus SensorsEnabled();
NodeStatus DisableSensors();
NodeStatus AllRed();
NodeStatus CarDetected();

