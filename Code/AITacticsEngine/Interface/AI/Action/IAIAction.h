#pragma once

namespace AITactics
{

class IDataContainer;

class IAIAction
{
public:
    virtual ~IAIAction() {}
    virtual IDataContainer const& GetActionDataContainer() const = 0;
};

} // namespace AITactics