#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "AITacticsEngine/Interface/Common/DataContainer/IData.h"

namespace AITactics_Test
{

class IData_Mock : public AITactics::IData
{
public:
    MOCK_CONST_METHOD0(GetDataTypeId, AITactics::CStringId());
};

} // namespace AITactics_Test