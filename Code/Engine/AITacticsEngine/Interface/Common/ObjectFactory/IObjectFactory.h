#pragma once

#include <memory>

#include "AITacticsEngine/Interface/Common/StringId.h"

namespace AITactics
{

template<typename TObject>
class IObjectCreator;
class IData;

template<typename TObject>
class IObjectFactory
{
public:
    virtual ~IObjectFactory() {}
    virtual std::unique_ptr<TObject> CreateObject(IData const& data) = 0;
    virtual void RegisterCreator(CStringId const dataTypeId, std::unique_ptr<IObjectCreator<TObject>> creator) = 0;
};

} // namespace AITactics