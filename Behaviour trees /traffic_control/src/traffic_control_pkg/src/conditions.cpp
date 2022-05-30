#include "conditions.h"

NodeStatus AllRed2Sec()
{
    return NodeStatus::SUCCESS;
}
NodeStatus SensorsEnabled()
{
    return NodeStatus::SUCCESS;
}
NodeStatus DisableSensors()
{
    return NodeStatus::SUCCESS;
}
NodeStatus AllRed()
{
    std::cout << "wow is alles rood?";
    return NodeStatus::SUCCESS;
}
NodeStatus CarDetected()
{
    if (rand() % 2 == 0)
        return NodeStatus::SUCCESS;
    else
        return NodeStatus::FAILURE;
}
