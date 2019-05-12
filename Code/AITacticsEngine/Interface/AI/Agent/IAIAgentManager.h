#pragma once

#include "AITacticsEngine/Interface/AI/Agent/AIAgentId.h"
#include "AITacticsEngine/Interface/Common/ObjectHandle.h"
#include "AITacticsEngine/Interface/Common/ObjectFactory/IObjectsManager.h"

namespace AITactics
{

DECLARE_DEFAULT_OBJECTS_MANAGER_INTERFACE(
    IAIAgentsManager,
    IAIAgent,
    AIAgentId,
    CAIAgentHandle
)

} // namespace AITactics