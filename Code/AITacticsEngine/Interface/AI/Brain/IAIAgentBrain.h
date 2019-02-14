#pragma once

#include "AITacticsEngine/Interface/AI/Agent/IAIAgentManager.h"
#include "AITacticsEngine/Interface/AI/Brain/IAIBrain.h"

namespace AITactics
{

class IAIAgentBrain : public IAIBrain
{
public:
    virtual ~IAIAgentBrain() {}
    virtual void SetAgent(CAIAgentHandle& agent) = 0;
    virtual CAIAgentHandle GetAgent() const = 0;
};

} // namespace AITactics