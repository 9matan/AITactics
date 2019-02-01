#pragma once

#include "Interface/Common/EventHandler/IEventHandler.h"

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

using IAIexecuteActionEventHandler = IEventHandler<SExecuteActionEvent>;

} // namespace AITactics