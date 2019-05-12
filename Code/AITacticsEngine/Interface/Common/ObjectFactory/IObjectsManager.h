#pragma once

#include <memory>

#include "AITacticsEngine/Interface/Common/StringId.h"
#include "AITacticsEngine/Interface/Common/ObjectFactory/IObjectCreator.h"

namespace AITactics
{

class IData;
template<typename TObject, typename TProxy, typename TObjectId>
class CObjectHandle;

template<typename TObject, typename TObjectId>
class IObjectsManager
{
public:
    using CHandle = CObjectHandle<TObject, IObjectsManager<TObject, TObjectId>, TObjectId>;

    virtual ~IObjectsManager() {}
    virtual CHandle CreateObject(IData const& data) = 0;
    virtual void RegisterCreator(CStringId const dataTypeId, std::unique_ptr<IObjectCreator<TObject>> creator) = 0;
    virtual TObject* GetObject(TObjectId objectId) = 0;
};

#define DECLARE_DEFAULT_OBJECTS_MANAGER_INTERFACE(IManager, IObject, Id, ObjectHandle) \
class IObject; \
class IManager : public IObjectsManager<IObject, Id> \
{ \
public: \
    virtual ~IManager() {} \
}; \
template<> \
IObject* GetObjectPtrById(IManager* manager, Id const objectId) \
{ \
    return manager->GetObject(objectId); \
} \
using ObjectHandle = IAIAgentsManager::CHandle;

} // namespace AITactics