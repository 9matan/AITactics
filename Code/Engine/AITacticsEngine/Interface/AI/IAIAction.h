#pragma once

namespace AITactics
{

class IDataContainer;

class IAIAction
{
public:
    virtual IDataContainer& GetActionDataContainer() = 0;
    virtual IDataContainer const& GetActionDataContainer() const = 0;
};

} // namespace AITactics