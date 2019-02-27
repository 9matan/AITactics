#pragma once

#include <vector>

#include "AITacticsEngine/Interface/AI/Agent/IAIAgent.h"
#include "AITacticsEngine/Interface/Common/DataContainer/IDataContainer.h"

namespace AITactics
{

class CAIAgent : public IAIAgent
{
public:
    CAIAgent(AIAgentId const agentId, std::unique_ptr<IDataContainer> dataContainer);

	virtual AIAgentId GetAgentId() const override;
	virtual IDataContainer const& GetAgentDataContainer() const override;

	virtual void AddAction(std::unique_ptr<IAIAction> action, IAIActionHandler* actionHandler) override;

	virtual void RegisterData(CStringId const dataTypeId, IAIAgentDataHandler* agentDataHandler) override;
	virtual void UnregisterData(CStringId const dataTypeId) override;
    virtual void HandleData(IData const& data) override;

	virtual size_t GetActionCount() const override;
	virtual IAIAction const& GetAction(size_t const actionIndex) const override;

private:
    struct SDataHandlerEntry
    {
        bool operator==(CStringId const dataTypeId) { return dataTypeId == m_dataTypeId; }

        CStringId m_dataTypeId;
        IAIAgentDataHandler* m_agentDataHandler;
    };

    struct SActionEntry
    {
        std::unique_ptr<IAIAction> m_action;
        IAIActionHandler* m_actionHandler;
    };

    using ActionContainer = std::vector<SActionEntry>;
    using DataHandlerContainer = std::vector<SDataHandlerEntry>;
    
private:
	AIAgentId m_aiAgentId;
    ActionContainer m_actions;
    DataHandlerContainer m_dataHandlers;
    std::unique_ptr<IDataContainer> m_dataContainer;
};

} // namespace AITactics