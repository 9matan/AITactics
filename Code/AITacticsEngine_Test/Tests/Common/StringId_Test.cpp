#include "gtest/gtest.h"
#include "AITacticsEngine/Interface/Common/StringId.h"

TEST(CStringId_Test, Equality1)
{
    using namespace AITactics;

    CStringId helloWorldId1("HelloWorld");
    CStringId helloWorldId2("HelloWorld");

    EXPECT_TRUE(helloWorldId1 == helloWorldId2);
}

TEST(CStringId_Test, Equality2)
{
    using namespace AITactics;

    CStringId randomTextId1("SomeRandomText");
    CStringId randomTextId2("SomeRandomText");

    EXPECT_TRUE(randomTextId1 == randomTextId2);
}

TEST(CStringId_Test, CaseSensitive)
{
    using namespace AITactics;

    CStringId lowerCaseId("helloworld");
    CStringId upperCaseId("HELLOWORLD");

    EXPECT_FALSE(lowerCaseId == upperCaseId);
}