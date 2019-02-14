#pragma once

#include "AITacticsEngine/Interface/AI/Brain/AIBrainId.h"

namespace AITactics
{

class IAIBrain
{
public:
    virtual ~IAIBrain() {}
    virtual AIBrainId GetBrainId() const = 0;
    virtual void Update(float const delta) = 0;
};

} // namespace AITactics