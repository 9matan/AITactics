#include "AITacticsEngine_Test/Tests/AI/IAIAgent_Test.h"

#include "AITacticsEngine/Implementation/AI/Agent/AIAgent.h"

#include "AITacticsEngine_Test/MockObjects/Common/IDataContainer_Mock.h"

namespace AITactics_Test
{

static std::unique_ptr<AITactics::IAIAgent> CreateAIAgent()
{
    static AITactics::AIAgentId agentId = AITactics::AIAgentId(0);

    agentId = AITactics::AIAgentId((int)(agentId) + 1);
    return std::make_unique<AITactics::CAIAgent>(agentId, std::move(std::make_unique<IDataContainer_Mock>()));
}

INSTANTIATE_TEST_SUITE_P(CAIAgent_Test, IAIAgent_Test,
    testing::Values(&CreateAIAgent));

} // namespace AITactics_Test