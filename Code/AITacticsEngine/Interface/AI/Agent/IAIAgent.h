#pragma once

#include <memory>

#include "AITacticsEngine/Interface/AI/Agent/AIAgentId.h"
#include "AITacticsEngine/Interface/AI/Action/IAIAction.h"
#include "AITacticsEngine/Interface/Common/StringId.h"
#include "AITacticsEngine/Interface/Common/DataContainer/IDataHandler.h"

namespace AITactics
{

class IDataContainer;
class IAIActionHandler;
class IAIAgentDataHandler;

class IAIAgent : public IDataHandler
{
public:
    virtual ~IAIAgent() {}

    virtual AIAgentId GetAgentId() const = 0;
    virtual IDataContainer const& GetAgentDataContainer() const = 0;

    virtual void AddAction(std::unique_ptr<IAIAction> action, IAIActionHandler* actionHandler) = 0;

    virtual void RegisterData(CStringId const dataTypeId, IAIAgentDataHandler* agentDataHandler) = 0;
    virtual void UnregisterData(CStringId const dataTypeId) = 0;

    virtual size_t GetActionCount() const = 0;
    virtual IAIAction const& GetAction(size_t const actionIndex) const = 0;
};



} // namespace AITactics