#pragma once

#include "AITacticsEngine/Interface/AI/Brain/AIBrainId.h"
#include "AITacticsEngine/Interface/Common/ObjectHandle.h"
#include "AITacticsEngine/Interface/Common/ObjectFactory/IObjectsManager.h"

namespace AITactics
{

class IAIBrain;

class IAIBrainsManager : public IObjectsManager<IAIBrain, AIBrainId>
{
public:
    virtual ~IAIBrainsManager() {}
};

template<>
IAIBrain* GetObjectPtrById(IAIBrainsManager* aiBrainsManager, AIBrainId const brainId)
{
    return aiBrainsManager->GetObject(brainId);
}

using CAIBrainHandle = IAIBrainsManager::CHandle;

} // namespace AITactics