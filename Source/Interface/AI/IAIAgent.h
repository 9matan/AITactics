#pragma once

#include "Interface/AI/IAIAction.h"

namespace AITactics
{

class IAIAgent
{
public:
    virtual bool CanExecuteAction(IAIAction const*) const = 0;
    virtual void ExecuteAction(IAIAction const*) = 0;
    virtual void UpdateAgent() = 0;
};

} // namespace AITactics