#include "Component.h"
#include "../Entity/Entity.h"

Component::Component(std::string componentName)
{
    this->componentName = componentName;
}