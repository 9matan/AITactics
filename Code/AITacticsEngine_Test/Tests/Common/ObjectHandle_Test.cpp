#include "gtest/gtest.h"
#include "AITacticsEngine/Interface/Common/ObjectHandle.h"

#include <unordered_map>

class CTestObject
{
public:
	int m_intVar;
};

class CTestProxy
{
};

namespace
{

static CTestObject testObject{10};

}

namespace AITactics
{

template<>
CTestObject* GetObjectPtrById(CTestProxy* proxy, unsigned int const objectId)
{
	if (objectId == 0)
		return nullptr;

	return &testObject;
}

} // namespace AITactics

using CTestObjectHandle = AITactics::CObjectHandle<CTestObject, CTestProxy, unsigned int>;

TEST(CObjectHandle_Test, IsValid_NullProxy_ReturnsFalse)
{
	CTestObjectHandle invalidObjectHandle;

	EXPECT_FALSE(invalidObjectHandle.IsValid());
}

TEST(CObjectHandle_Test, IsValid_InvalidId_ReturnsFalse)
{
	CTestProxy testProxy;
	CTestObjectHandle invalidObjectHandle(&testProxy, 0);

	EXPECT_FALSE(invalidObjectHandle.IsValid());
}

TEST(CObjectHandle_Test, IsValid_ValidHandle_ReturnsTrue)
{
	CTestProxy testProxy;
	CTestObjectHandle validObjectHandle(&testProxy, 1);

	EXPECT_TRUE(validObjectHandle.IsValid());
}

TEST(CObjectHandle_Test, GetObjectPtr_ValidHandle_ReturnsValidPtr)
{
	CTestProxy testProxy;
	CTestObjectHandle validObjectHandle(&testProxy, 1);

	EXPECT_TRUE(validObjectHandle.GetObjectPtr() == &testObject);
}

TEST(CObjectHandle_Test, GetObjectPtr_InvalidId_ReturnsNullPtr)
{
    CTestProxy testProxy;
    CTestObjectHandle invalidObjectHandle(&testProxy, 0);

    EXPECT_TRUE(invalidObjectHandle.GetObjectPtr() == nullptr);
}

TEST(CObjectHandle_Test, ArrowOperator_ValidHandle_ReturnsValidPtr)
{
	CTestProxy testProxy;
	CTestObjectHandle validObjectHandle(&testProxy, 1);

	EXPECT_TRUE(validObjectHandle->m_intVar == testObject.m_intVar);
}

TEST(CObjectHandle_Test, ArrowOperator_InvalidId_HandleAssert)
{
    CTestProxy testProxy;
    CTestObjectHandle validObjectHandle(&testProxy, 0);
    EXPECT_DEATH(validObjectHandle->m_intVar, "handle");
}