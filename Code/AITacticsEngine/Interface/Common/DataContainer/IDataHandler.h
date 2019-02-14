#pragma once

namespace AITactics
{

class IData;

class IDataHandler
{
public:
    virtual ~IDataHandler() {}
    virtual void HandleData(IData const& data) const = 0;
};

} // namespace AITactics