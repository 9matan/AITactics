#include "gtest/gtest.h"

#include <memory>

#include "AITacticsEngine/Interface/AI/Agent/IAIAgent.h"

#include "AITacticsEngine_Test/FakeObjects/Common/IDataFake_RuntimeDataType.h"
#include "AITacticsEngine_Test/MockObjects/AI/Action/IAIAction_Mock.h"
#include "AITacticsEngine_Test/MockObjects/AI/Action/IAIActionHandler_Mock.h"
#include "AITacticsEngine_Test/MockObjects/AI/Agent/IAIAgentDataHandler_Mock.h"

namespace
{

bool ContainsAction(AITactics::IAIAgent const& agent, AITactics::IAIAction const* const action)
{
    for (size_t i = 0; i < agent.GetActionCount(); ++i)
    {
        if (action == &agent.GetAction(i))
        {
            return true;
        }
    }

    return false;
}

} // namespace

namespace AITactics_Test
{

using CreatorIAIAgent = std::unique_ptr<AITactics::IAIAgent>(*)();

class IAIAgent_Test : public testing::TestWithParam<CreatorIAIAgent>
{
public:
    virtual void SetUp() override
    {
        m_aiAgent = std::move(GetParam()());
    }

protected:
    std::unique_ptr<AITactics::IAIAgent> m_aiAgent;
};

TEST_P(IAIAgent_Test, AddAction_CountIncreasedBy1)
{
    auto action = std::make_unique<IAIAction_Mock>();
    IAIActionHandler_Mock actionHandler;
    size_t const initActionCount = m_aiAgent->GetActionCount();

    m_aiAgent->AddAction(std::move(action), &actionHandler);

    EXPECT_TRUE(m_aiAgent->GetActionCount() == initActionCount + 1);
}

TEST_P(IAIAgent_Test, AddAction_ActionAdded)
{
    auto action = std::make_unique<IAIAction_Mock>();
    AITactics::IAIAction* actionPtr = action.get();
    IAIActionHandler_Mock actionHandler;
    
    m_aiAgent->AddAction(std::move(action), &actionHandler);

    EXPECT_TRUE(ContainsAction(*m_aiAgent.get(), actionPtr));
}

TEST_P(IAIAgent_Test, AddAction_InvalidActionHandler_ActionAdded)
{
    auto action = std::make_unique<IAIAction_Mock>();
    AITactics::IAIAction* actionPtr = action.get();

    m_aiAgent->AddAction(std::move(action), nullptr);

    EXPECT_TRUE(ContainsAction(*m_aiAgent.get(), actionPtr));
}

TEST_P(IAIAgent_Test, AddAction_AddInvalidAction_Assert)
{
    IAIActionHandler_Mock actionHandler;
    std::unique_ptr<AITactics::IAIAction> nullAction(nullptr);

    EXPECT_DEATH(m_aiAgent->AddAction(std::move(nullAction), &actionHandler), "action");
}

TEST_P(IAIAgent_Test, HandleData_HandleDataWithSetDataHandler_HandleAgentDataInvoked)
{
    AITactics::CStringId dataTypeId("DataType1");
    IDataFake_RuntimeDataType data(dataTypeId);
    IAIAgentDataHandler_Mock dataHandler;
    m_aiAgent->SetDataHandler(dataTypeId, &dataHandler);
    
    EXPECT_CALL(dataHandler, HandleAgentData(testing::_))
        .Times(1);
    m_aiAgent->HandleData(data);
}

TEST_P(IAIAgent_Test, ResetDataHandler_ResetExistingDataHandler_HandleAgentDataNotInvoked)
{
    AITactics::CStringId dataTypeId("DataType1");
    IDataFake_RuntimeDataType data(dataTypeId);
    IAIAgentDataHandler_Mock dataHandler;
    m_aiAgent->SetDataHandler(dataTypeId, &dataHandler);

    m_aiAgent->ResetDataHandler(dataTypeId);

    EXPECT_CALL(dataHandler, HandleAgentData(testing::_))
        .Times(0);
    m_aiAgent->HandleData(data);
}

} // AITactics_Test