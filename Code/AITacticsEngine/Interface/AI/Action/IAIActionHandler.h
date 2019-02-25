#pragma once

#include "AITacticsEngine/Interface/Common/EventHandler/IEventHandler.h"

namespace AITactics
{

class IDataContainer;
class IDataHandler;

struct SActionHandlerEvent
{
    IDataContainer const& m_actionDataContainer;
    IDataContainer const& m_agentDataContainer;
    IDataHandler& m_agentDataHandler;
};

class IAIActionHandler
{
public:
    virtual ~IAIActionHandler() {}
    virtual void HandleAction(SActionHandlerEvent& event) = 0;
};

} // namespace AITactics