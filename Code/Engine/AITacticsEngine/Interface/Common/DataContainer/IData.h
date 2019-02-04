#pragma once

#include "AITacticsEngine/Interface/Common/StringId.h"

namespace AITactics
{

class IData
{
public:
    virtual CStringId GetDataTypeId() const = 0;
};

} // namespace AITactics