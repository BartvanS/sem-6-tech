#include "nodes.h"
using std::cout; using std::endl;
using namespace BT;
SetLight::SetLight(const std::string &name, const NodeConfiguration &config) : SyncActionNode(name, config)
{
}
BT::PortsList SetLight::providedPorts()
{
    return {
        BT::InputPort<std::string>("color"),
        BT::InputPort<bool>("north"),
        BT::InputPort<bool>("east"),
        BT::InputPort<bool>("south"),
        BT::InputPort<bool>("west")};
}
BT::NodeStatus SetLight::tick()
{
    Optional<bool> north = getInput<bool>("north");
    Optional<bool> east = getInput<bool>("east");
    Optional<bool> south = getInput<bool>("south");
    Optional<bool> west = getInput<bool>("west");
    Optional<std::string> color = getInput<std::string>("color");
    if (color.value() == "black")
    {
        std::cout << "Lantern(s) " << north.value() << " disabled" << std::endl;
    }
    else
    {
        std::cout << "Lantern(s) "
                  << " set to color:" << color.value() << std::endl;
    }
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
    : CoroActionNode(name, config)
{
}
PortsList WaitTime::providedPorts()
{
    // This action has a single input port called "message"
    // Any port must have a name. The type is optional.
    return {InputPort<int64_t>("time")};
}
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::system_clock;
BT::NodeStatus WaitTime::tick()
{
    int64_t timeToWait = getInput<int64_t>("time").value();
    auto currentTimeMs = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    if (this->nodeStatus == NodeStatus::FAILURE || this->nodeStatus == NodeStatus::SUCCESS)
    {
        std::cout << "waiting for " << timeToWait << "ms" << std::endl;
        this->nodeStatus = NodeStatus::RUNNING;
        this->startTime  = currentTimeMs;
    }
    else if (this->nodeStatus == NodeStatus::RUNNING)
    {
        long timedif = currentTimeMs - this->startTime;
        // std::cout << "Time left to wait: " << timeToWait - timedif << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if (timedif >= timeToWait)
        {
            this->nodeStatus = NodeStatus::SUCCESS;
        }
    }
    std::cout << this->nodeStatus << std::endl;
    return this->nodeStatus;
}

///////
AlwaysRunning::AlwaysRunning(const std::string &name, const NodeConfiguration &config) : AsyncActionNode(name, config)
{
}
PortsList AlwaysRunning::providedPorts()
{
    return {};
}

BT::NodeStatus AlwaysRunning::tick()
{
    return BT::NodeStatus::RUNNING;
}
