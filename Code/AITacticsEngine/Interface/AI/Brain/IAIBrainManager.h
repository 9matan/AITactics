#pragma once

#include "AITacticsEngine/Interface/AI/Brain/AIBrainId.h"
#include "AITacticsEngine/Interface/Common/ObjectHandle.h"
#include "AITacticsEngine/Interface/Common/ObjectFactory/IObjectsManager.h"

namespace AITactics
{

DECLARE_DEFAULT_OBJECTS_MANAGER_INTERFACE(
    IAIBrainsManager,
    IAIBrain,
    AIBrainId,
    CAIBrainHandle
)

} // namespace AITactics