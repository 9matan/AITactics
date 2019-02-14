#include "Test_AITacticsEngine/FakeObjects/Common/IDataFake_RuntimeDataType.h"

using namespace AITactics;

namespace AITactics_Test
{

IDataFake_RuntimeDataType::IDataFake_RuntimeDataType(char const* const dataType)
    : m_dataType(dataType)
{
}

IDataFake_RuntimeDataType::IDataFake_RuntimeDataType(CStringId const& dataTypeId)
    : m_dataType(dataTypeId)
{
}

CStringId IDataFake_RuntimeDataType::GetDataTypeId() const
{
    return m_dataType;
}

} // namespace AITactics_Test