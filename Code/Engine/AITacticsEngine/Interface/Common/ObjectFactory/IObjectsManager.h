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

    virtual CHandle CreateObject(IData const& data) = 0;
    virtual void RegisterCreator(CStringId const dataTypeId, std::unique_ptr<IObjectCreator<TObject>> creator) = 0;
    virtual TObject* GetObject(TObjectId objectId) = 0;
};

} // namespace AITactics