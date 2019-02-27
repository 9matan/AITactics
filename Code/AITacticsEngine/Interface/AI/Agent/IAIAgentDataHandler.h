#pragma once

namespace AITactics
{

class IAIAgent;
class IData;

struct SAgentDataHandlerData
{
    IAIAgent* m_agent;
    IData const* m_data;
};

class IAIAgentDataHandler
{
public:
    virtual ~IAIAgentDataHandler() {}

    virtual void HandleAgentData(SAgentDataHandlerData& handlerData) = 0;
};

} // namespace AITactics