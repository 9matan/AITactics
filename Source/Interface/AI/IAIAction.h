#pragma once

namespace AITactics
{

using CActionTypeId = unsigned int;

class IAIAction
{
public:
    virtual CActionTypeId GetActionTypeId() const = 0;
};

} // namespace AITactics