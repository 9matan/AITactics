#pragma once

#include "AITacticsEngine/Interface/Common/EventHandler/IEventHandler.h"

namespace AITactics
{

class IAIAgent;
class IData;

struct SAgentDataHandlerEvent
{
    IAIAgent& m_agent;
    IData& m_data;
};

class IAIAgentDataHandler
{
public:
    virtual ~IAIAgentDataHandler() {}

    virtual void HandleAgentData(SAgentDataHandlerEvent& event) = 0;
};

} // namespace AITactics