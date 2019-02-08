#pragma once

#include "AITacticsEngine/Interface/AI/Agent/AIAgentId.h"
#include "AITacticsEngine/Interface/Common/ObjectHandle.h"
#include "AITacticsEngine/Interface/Common/ObjectFactory/IObjectsManager.h"

namespace AITactics
{

class IAIAgent;

class IAIAgentsManager : public IObjectsManager<IAIAgent, AIAgentId>
{};

template<>
IAIAgent* GetObjectPtrById(IAIAgentsManager* aiAgentsManager, AIAgentId const agentId)
{
    return aiAgentsManager->GetObject(agentId);
}

using CAIAgentHandle = IAIAgentsManager::CHandle;

} // namespace AITactics