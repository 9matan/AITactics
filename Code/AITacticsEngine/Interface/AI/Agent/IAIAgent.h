#pragma once

#include <memory>

#include "AITacticsEngine/Interface/AI/Agent/AIAgentId.h"
#include "AITacticsEngine/Interface/Common/StringId.h"

namespace AITactics
{

class IDataContainer;
class IAIAction;
class IAIActionHandler;
class IAIAgentDataHandler;

class IAIAgent
{
public:
    virtual ~IAIAgent() {}

    virtual AIAgentId GetAgentId() const = 0;
    virtual IDataContainer const& GetAgentDataContainer() const = 0;

    virtual void RegisterAction(std::unique_ptr<IAIAction> action, IAIActionHandler& actionHandler) = 0;
    virtual std::unique_ptr<IAIAction> UnregisterAction(IAIAction& action) = 0;

    virtual void RegisterData(CStringId const dataTypeId, IAIAgentDataHandler& agentDataHandler) = 0;
    virtual void UnregisterData(CStringId const dataTypeId) = 0;

    virtual size_t GetActionCount() const = 0;

    virtual IAIAction& GetAction(size_t const actionIndex) = 0;
    virtual IAIAction const& GetAction(size_t const actionIndex) const = 0;
};



} // namespace AITactics