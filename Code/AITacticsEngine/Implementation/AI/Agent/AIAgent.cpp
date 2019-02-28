#include "AITacticsEngine/AITacticsEngine_PCH.h"
#include "AITacticsEngine/Implementation/AI/Agent/AIAgent.h"

#include "AITacticsEngine/Interface/Common/DataContainer/IData.h"
#include "AITacticsEngine/Interface/AI/Agent/IAIAgentDataHandler.h"

namespace AITactics
{

CAIAgent::CAIAgent(AIAgentId const agentId, std::unique_ptr<IDataContainer> dataContainer)
	: m_aiAgentId(agentId)
    , m_dataContainer(std::move(dataContainer))
{}

AIAgentId CAIAgent::GetAgentId() const
{
    return m_aiAgentId;
}

IDataContainer const& CAIAgent::GetAgentDataContainer() const
{
    return *m_dataContainer.get();
}

void CAIAgent::AddAction(std::unique_ptr<IAIAction> action, IAIActionHandler* actionHandler)
{
    assert(bool(action) && "The action is not valid");

    SActionEntry actionEntry;
    actionEntry.m_action = std::move(action);
    actionEntry.m_actionHandler = actionHandler;

    m_actions.emplace_back(std::move(actionEntry));
}

void CAIAgent::SetDataHandler(CStringId const dataTypeId, IAIAgentDataHandler* agentDataHandler)
{
    auto const dataHandlerIter = std::find(m_dataHandlers.begin(), m_dataHandlers.end(), dataTypeId);

    if (dataHandlerIter != m_dataHandlers.end())
    {
        dataHandlerIter->m_agentDataHandler = agentDataHandler;
        return;
    }

    SDataHandlerEntry dataHandlerEntry;
    dataHandlerEntry.m_dataTypeId = dataTypeId;
    dataHandlerEntry.m_agentDataHandler = agentDataHandler;

    m_dataHandlers.emplace_back(std::move(dataHandlerEntry));
}

void CAIAgent::ResetDataHandler(CStringId const dataTypeId)
{
    auto const dataHandlerIter = std::remove(m_dataHandlers.begin(), m_dataHandlers.end(), dataTypeId);

    if (dataHandlerIter == m_dataHandlers.end())
    {
        return;
    }

    m_dataHandlers.erase(dataHandlerIter, m_dataHandlers.end());
}

void CAIAgent::HandleData(IData const& data)
{
    auto const dataHandlerIter = std::find(m_dataHandlers.begin(), m_dataHandlers.end(), data.GetDataTypeId());

    if (dataHandlerIter == m_dataHandlers.end())
    {
        return;
    }

    SAgentDataHandlerData dataHandlerData;
    dataHandlerData.m_agent = this;
    dataHandlerData.m_data = &data;
    dataHandlerIter->m_agentDataHandler->HandleAgentData(dataHandlerData);
}

size_t CAIAgent::GetActionCount() const
{
    return m_actions.size();
}

IAIAction const& CAIAgent::GetAction(size_t const actionIndex) const
{
    assert(actionIndex < m_actions.size() && "The action index is not valid");
    return *m_actions[actionIndex].m_action.get();
}

} // namespace AITactics