#pragma once

#include <cassert>

namespace AITactics
{

template<typename TObject, typename TProxy, typename TObjectId>
TObject* GetObjectPtrById(TProxy* proxy, TObjectId const objectId)
{
    static_assert(false, "GetObjectPtrById is not implemented for these types");
}
 
template<typename TObject, typename TProxy, typename TObjectId = unsigned int>
class CObjectHandle
{
public:
    CObjectHandle() 
        : m_proxy(nullptr)
    {}
    
    CObjectHandle(TProxy* proxy, TObjectId objectId)
        : m_proxy(proxy)
        , m_objectId(objectId)
    {
        assert(proxy && "proxy must not be null");
    }
    
	inline bool IsValid() const
    {
        return m_proxy && GetObjectPtr() != nullptr;
    }
    
    inline TObject* operator->() const
    {
        assert(IsValid() && "handle is not valid");
        return GetObjectPtr();
    }

	inline TObject* GetObjectPtr() const
	{
		assert(m_proxy && "proxy must not be null");
		return GetObjectPtrById<TObject, TProxy, TObjectId>(m_proxy, m_objectId);
	}
    
private:
    TProxy* m_proxy;
    TObjectId m_objectId;
};
    
} // namespace AITacticsEngine