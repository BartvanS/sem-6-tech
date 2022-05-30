#include "nodes.h"

using namespace BT;
SetLight::SetLight(const std::string &name, const NodeConfiguration &config) : SyncActionNode(name, config)
{
}
BT::PortsList SetLight::providedPorts()
{
    return {BT::InputPort<std::string>("color"), BT::InputPort<std::string>("orientation_lantern")};
}
BT::NodeStatus SetLight::tick()
{
    Optional<std::string> orientation = getInput<std::string>("orientation_lantern");
    Optional<std::string> color = getInput<std::string>("color");
    std::cout << "Lantern(s) " << orientation->c_str() << "set to color:" << color->c_str() << "\n"
              << std::endl;
    return BT::NodeStatus::SUCCESS;
}
///////////////////
EnableSensors::EnableSensors(const std::string &name) : BT::SyncActionNode(name, {})
{
}

BT::NodeStatus EnableSensors::tick()
{
    std::cout << "Sensors enabled";
    return BT::NodeStatus::SUCCESS;
}

///////////////////////////
DisableSensors::DisableSensors(const std::string &name) : BT::SyncActionNode(name, {})
{
}

BT::NodeStatus DisableSensors::tick()
{
    std::cout << "Sensors disabled";
    return BT::NodeStatus::SUCCESS;
}
//////////////////////
#include <ctime>
WaitTime::WaitTime(const std::string &name, const NodeConfiguration &config)
    : SyncActionNode(name, config)
{
}
PortsList WaitTime::providedPorts()
{
    // This action has a single input port called "message"
    // Any port must have a name. The type is optional.
    return {InputPort<std::int64_t>("time")};
}
BT::NodeStatus WaitTime::tick()
{
    Optional<std::int64_t> timeToWait = getInput<std::int64_t>("time");
    if (this->nodeStatus == NodeStatus::FAILURE || this->nodeStatus == NodeStatus::SUCCESS)
    {
        this->nodeStatus = NodeStatus::RUNNING;
        this->startTime = std::time(NULL);
    }
    else if (this->nodeStatus == NodeStatus::RUNNING)
    {
        long timedif = (this->startTime - std::time(NULL));
        if (timedif > timeToWait)
        {
            this->nodeStatus = NodeStatus::SUCCESS;
        }
    }
    return this->nodeStatus;
}

///////
AlwaysRunning::AlwaysRunning(const std::string &name) : BT::SyncActionNode(name, {})
{
}

BT::NodeStatus AlwaysRunning::tick()
{
    return BT::NodeStatus::RUNNING;
}
