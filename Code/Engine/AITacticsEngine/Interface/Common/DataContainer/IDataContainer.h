#pragma once

#include "Interface/Common/DataContainer/IData.h"

namespace AITactics
{

class IDataContainer
{
public:
    virtual IData* GetDataByTypeId(CStringId const dataTypeId) = 0;
    virtual void AddData(IData* data) = 0;
    virtual void RemoveData(CStringId const dataTypeId) = 0;
    virtual void ContainsData(CStringId const dataTypeId) const = 0;

    virtual IData const* GetDataByTypeId(CStringId const dataTypeId) const = 0;
};

} // namespace AITactics