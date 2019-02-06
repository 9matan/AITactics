#pragma once

#include "AITacticsEngine/Interface/Common/EventHandler/IEventHandler.h"

namespace AITactics
{

class IAIAgent;
class IData;

struct SAgentDataEvent
{
    IAIAgent& m_agent;
    IData& m_data;
};

class IAIAgentDataEventHandler : public IEventHandler<SAgentDataEvent>
{
};

} // namespace AITactics