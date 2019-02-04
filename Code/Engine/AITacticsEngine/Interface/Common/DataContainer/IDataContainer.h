#pragma once

#include <memory>

#include "AITacticsEngine/Interface/Common/DataContainer/IData.h"

namespace AITactics
{

class IDataContainer
{
public:
    virtual void AddData(std::unique_ptr<IData> data) = 0;
    virtual std::unique_ptr<IData> RemoveData(CStringId const dataTypeId) = 0;

    virtual IData* GetDataByTypeId(CStringId const dataTypeId) = 0;
    virtual IData const* GetDataByTypeId(CStringId const dataTypeId) const = 0;
    
    virtual bool ContainsData(CStringId const dataTypeId) const = 0;
};

} // namespace AITactics