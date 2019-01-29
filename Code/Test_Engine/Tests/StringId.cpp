#include "gtest/gtest.h"
#include "AITacticsEngine/Interface/Common/StringId.h"

TEST(CStringIdTest, Equality1)
{
    using namespace AITactics;

    CStringId helloWorldId1("HelloWorld");
    CStringId helloWorldId2("HelloWorld");

    EXPECT_TRUE(helloWorldId1 == helloWorldId2);
}

TEST(CStringIdTest, Equality2)
{
    using namespace AITactics;

    CStringId randomTextId1("SomeRandomText");
    CStringId randomTextId2("SomeRandomText");

    EXPECT_TRUE(randomTextId1 == randomTextId2);
}

TEST(CStringIdTest, CaseSensitive)
{
    using namespace AITactics;

    CStringId lowerCaseId("helloworld");
    CStringId upperCaseId("HELLOWORLD");

    EXPECT_FALSE(lowerCaseId == upperCaseId);
}