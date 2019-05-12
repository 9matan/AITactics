#pragma once

#include <memory>

#include "AITacticsEngine/Interface/Common/StringId.h"
#include "AITacticsEngine/Interface/Common/ObjectFactory/IObjectCreator.h"

namespace AITactics
{

class IData;

template<typename TObject>
class IObjectFactory : public IObjectCreator<TObject>
{
public:
    virtual ~IObjectFactory() {}
    virtual void RegisterCreator(CStringId const dataTypeId, std::unique_ptr<IObjectCreator<TObject>> creator) = 0;
};

} // namespace AITactics