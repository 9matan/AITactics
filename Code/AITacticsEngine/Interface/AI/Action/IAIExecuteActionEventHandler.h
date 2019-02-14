#pragma once

#include "AITacticsEngine/Interface/Common/EventHandler/IEventHandler.h"

namespace AITactics
{

class IDataContainer;
class IDataHandler;

struct SExecuteActionEvent
{
    IDataContainer const& m_actionDataContainer;
    IDataContainer const& m_agentDataContainer;
    IDataHandler& m_agentDataHandler;
};

class IAIExecuteActionEventHandler : public IEventHandler<SExecuteActionEvent>
{
public:
    virtual ~IAIExecuteActionEventHandler() {}
};

} // namespace AITactics