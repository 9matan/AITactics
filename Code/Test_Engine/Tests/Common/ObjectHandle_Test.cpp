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

TEST(CObjectHandle, IsValid_NullProxy)
{
	CTestObjectHandle invalidObjectHandle;

	EXPECT_FALSE(invalidObjectHandle.IsValid());
}

TEST(CObjectHandle, IsValid_InvalidId)
{
	CTestProxy testProxy;
	CTestObjectHandle invalidObjectHandle(&testProxy, 0);

	EXPECT_FALSE(invalidObjectHandle.IsValid());
}

TEST(CObjectHandle, IsValid_ValidHandle)
{
	CTestProxy testProxy;
	CTestObjectHandle validObjectHandle(&testProxy, 1);

	EXPECT_TRUE(validObjectHandle.IsValid());
}

TEST(CObjectHandle, GetObjectPtr_ValidHandle)
{
	CTestProxy testProxy;
	CTestObjectHandle validObjectHandle(&testProxy, 1);

	EXPECT_TRUE(validObjectHandle.GetObjectPtr() == &testObject);
}

TEST(CObjectHandle, ArrowOperator_ValidHandle)
{
	CTestProxy testProxy;
	CTestObjectHandle validObjectHandle(&testProxy, 1);

	EXPECT_TRUE(validObjectHandle->m_intVar == testObject.m_intVar);
}