#pragma once

namespace AITactics
{

class IData;

class IDataHandler
{
public:
    virtual ~IDataHandler() {}
    virtual void HandleData(IData const& data) = 0;
};

} // namespace AITactics