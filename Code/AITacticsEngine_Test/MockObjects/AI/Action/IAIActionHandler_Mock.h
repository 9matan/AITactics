#pragma once

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "AITacticsEngine/Interface/AI/Action/IAIActionHandler.h"

namespace AITactics_Test
{

class IAIActionHandler_Mock : public AITactics::IAIActionHandler
{
public:
    MOCK_CONST_METHOD1(CanExecuteAction, bool(AITactics::SActionExecutionData&));
    MOCK_METHOD1(ExecuteAction, void(AITactics::SActionExecutionData&));
};

} // namespace AITactics_Test