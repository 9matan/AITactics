#include "gtest/gtest.h"
#include "AITacticsEngine/Implementation/Common/DataContainer/Data.h"

DECLARE_DATA_TYPE_BEGIN(CTestData)
DECLARE_DATA_TYPE_END(CTestData)

DEFINE_DATA_TYPE(CTestData)

using namespace AITactics;

TEST(DataType, GetClassId_EqualsToClassStringId)
{
    CStringId const classStringId("CTestData");
    EXPECT_EQ(classStringId, CTestData::GetClassId());
}

TEST(DataType, GetDataTypeId_EqualsToClassStringId)
{
    CStringId const classStringId("CTestData");
    CTestData testData;
    IData* data = &testData;

    EXPECT_EQ(classStringId, data->GetDataTypeId());
}