#include "conditions.h"
using namespace std;
NodeStatus AllRed2Sec()
{
    if (rand() % 2 == 0)
    {
        cout << "All lights are red for at least 2 seconds" << endl;
        return NodeStatus::SUCCESS;
    }
    else
    {
        std::cout << "Not all lights are red for at least 2 seconds" << std::endl;
        return NodeStatus::FAILURE;
    }
}
NodeStatus SensorsEnabled()
{
    cout << "Sensor status: enabled" << endl;
    return NodeStatus::SUCCESS;
}

NodeStatus AllRed()
{
    std::cout << "Stoplichten staan op rood" << std::endl;
    return NodeStatus::SUCCESS;
}
// todo: blackboard welke weg moet gecontroleerd worden?
NodeStatus CarDetected()
{
    if (rand() % 2 == 0)
    {
        std::cout << "car detected" << std::endl;
        return NodeStatus::SUCCESS;
    }
    else
    {
        std::cout << "no car detected" << std::endl;
        return NodeStatus::FAILURE;
    }
}

NodeStatus OperatorModeRegular(){
    return NodeStatus::FAILURE;
}

////////////
OperatorModeSet::OperatorModeSet(const std::string &name) : BT::SyncActionNode(name, {})
{
}

BT::NodeStatus OperatorModeSet::tick()
{
    if (this->isSet)
    {
        this->isSet = true;
        return NodeStatus::SUCCESS;
    }
    return NodeStatus::FAILURE;
}