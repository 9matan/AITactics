#pragma once

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "AITacticsEngine/Interface/AI/Action/IAIAction.h"

namespace AITactics_Test
{

class IAIAction_Mock : public AITactics::IAIAction
{
public:
    MOCK_CONST_METHOD0(GetActionDataContainer, AITactics::IDataContainer const&());
};

} // namespace AITactics_Test