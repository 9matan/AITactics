#pragma once

namespace AITactics
{

class IDataContainer;
class IDataHandler;

struct SActionExecutionData
{
    IDataContainer const* m_actionDataContainer;
    IDataContainer const* m_executionDataContainer;
    IDataContainer const* m_agentDataContainer;
    IDataHandler* m_agentDataHandler;
};

class IAIActionHandler
{
public:
    virtual ~IAIActionHandler() {}
    virtual bool CanExecuteAction(SActionExecutionData& executionData) const = 0;
    virtual void ExecuteAction(SActionExecutionData& executionData) = 0;
};

} // namespace AITactics