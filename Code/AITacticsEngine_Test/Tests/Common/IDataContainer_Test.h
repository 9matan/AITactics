#pragma once

#include "gtest/gtest.h"

#include <memory>
#include <string>

#include "AITacticsEngine/Interface/Common/DataContainer/IDataContainer.h"

#include "AITacticsEngine_Test/FakeObjects/Common/IDataFake_RuntimeDataType.h"

namespace AITactics_Test
{

using CreatorIDataContainer = std::unique_ptr<AITactics::IDataContainer>(*)();

class IDataContainer_Test : public testing::TestWithParam<CreatorIDataContainer>
{
public:
    virtual void SetUp() override
    {
        m_dataContainer = std::move(GetParam()());
    }

protected:
    std::unique_ptr<AITactics::IDataContainer> m_dataContainer;
};

TEST_P(IDataContainer_Test, AddData_ContainsData)
{
    AITactics::CStringId const data1TypeId("data1");
    auto data1 = std::make_unique<IDataFake_RuntimeDataType>(data1TypeId);

    m_dataContainer->AddData(std::move(data1));

    EXPECT_TRUE(m_dataContainer->ContainsData(data1TypeId));
}

TEST_P(IDataContainer_Test, AddData_RemoveData_ContainsData)
{
    AITactics::CStringId const data1TypeId("data1");
    AITactics::CStringId const data2TypeId("data2");
    auto data1 = std::make_unique<IDataFake_RuntimeDataType>(data1TypeId);
    auto data2 = std::make_unique<IDataFake_RuntimeDataType>(data2TypeId);

    m_dataContainer->AddData(std::move(data1));
    m_dataContainer->AddData(std::move(data2));
    m_dataContainer->RemoveData(data1TypeId);

    EXPECT_FALSE(m_dataContainer->ContainsData(data1TypeId));
    EXPECT_TRUE(m_dataContainer->ContainsData(data2TypeId));
}

TEST_P(IDataContainer_Test, AddData_GetDataByTypeId)
{
    AITactics::CStringId const data1TypeId("data1");
    auto data1 = std::make_unique<IDataFake_RuntimeDataType>(data1TypeId);

    m_dataContainer->AddData(std::move(data1));

    EXPECT_TRUE(m_dataContainer->GetDataByTypeId(data1TypeId).GetDataTypeId() == data1TypeId);
}

TEST_P(IDataContainer_Test, GetDataByTypeId_NotExistingData)
{
    AITactics::CStringId const data1TypeId("data1");
    EXPECT_DEATH(m_dataContainer->GetDataByTypeId(data1TypeId), "data");
}

TEST_P(IDataContainer_Test, AddData_ExistingData)
{
    AITactics::CStringId const data1TypeId("data1");
    AITactics::CStringId const data2TypeId("data1");
    auto data1 = std::make_unique<IDataFake_RuntimeDataType>(data1TypeId);
    auto data2 = std::make_unique<IDataFake_RuntimeDataType>(data2TypeId);

    m_dataContainer->AddData(std::move(data1));

    EXPECT_DEATH(m_dataContainer->AddData(std::move(data2)), "data");
}

TEST_P(IDataContainer_Test, RemoveData_NotExistingData)
{
    AITactics::CStringId const data1TypeId("data1");
    EXPECT_DEATH(m_dataContainer->RemoveData(data1TypeId), "data");
}

} // AITactics_Test