#pragma once

#include <memory>

namespace AITactics
{

class IData;

template<typename TObject>
class IObjectCreator
{
public:
    virtual std::unique_ptr<TObject> CreateObject(IData const& data) = 0;
};

} // namespace AITactics