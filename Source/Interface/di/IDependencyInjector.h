#pragma once

namespace AITactics
{

template<typename TInjector>
class IDependencyInjector
{
public:
    virtual TInjector MakeInjector() const = 0;
};

} // namespace AITactics