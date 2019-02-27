#pragma once

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "AITacticsEngine/Interface/AI/Agent/IAIAgentDataHandler.h"

namespace AITactics_Test
{

class IAIAgentDataHandler_Mock : public AITactics::IAIAgentDataHandler
{
public:
    MOCK_METHOD1(HandleAgentData, void(AITactics::SAgentDataHandlerData& handlerData));
};

} // namespace AITactics_Test