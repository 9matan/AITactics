#pragma once

#include <memory>

#include "AITacticsEngine/Interface/Common/StringId.h"

namespace AITactics
{

class IDataContainer;
class IAIAction;
class IAIExecuteActionEventHandler;
class IAIAgentDataEventHandler;

class IAIAgent
{
public:
    virtual IDataContainer const& GetAgentDataContainer() const = 0;

    virtual void RegisterAction(std::unique_ptr<IAIAction> action, IAIExecuteActionEventHandler& actionHandler) = 0;
    virtual std::unique_ptr<IAIAction> UnregisterAction(IAIAction& action) = 0;
    virtual void ExecuteAction(IAIAction& action) = 0;

    virtual void RegisterDataHandler(CStringId const dataTypeId, IAIAgentDataEventHandler& agentDataHandler) = 0;
    virtual void UnregisterDataHandler(CStringId const dataTypeId) = 0;

    virtual size_t GetActionCount() const = 0;

    virtual IAIAction& GetAction(size_t const actionIndex) = 0;
    virtual IAIAction const& GetAction(size_t const actionIndex) const = 0;
};

} // namespace AITactics