#pragma once

#include "Interface/AI/IAIAgent.h"

namespace AITactics
{

class IAIBrain
{
public:
    virtual void AddAgent(IAIAgent* agent) = 0;
    virtual void AddAIBrainListener() = 0;
};

} // namespace AITactics