#pragma once

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "AITacticsEngine/Interface/Common/DataContainer/IDataContainer.h"

namespace AITactics_Test
{

#pragma warning(push)
#pragma warning(disable : 4373)

class IDataContainer_Mock : public AITactics::IDataContainer
{
public:
    MOCK_METHOD1(AddData, void (std::unique_ptr<AITactics::IData>));
    MOCK_METHOD1(RemoveData, std::unique_ptr<AITactics::IData>(AITactics::CStringId const));

    MOCK_METHOD1(GetDataByTypeId, AITactics::IData&(AITactics::CStringId const));
    MOCK_CONST_METHOD1(GetDataByTypeId, AITactics::IData const&(AITactics::CStringId const));

    MOCK_CONST_METHOD1(ContainsData, bool(AITactics::CStringId const));
};

#pragma warning(pop)

} // namespace AITactics_Test