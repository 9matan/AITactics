#pragma once

namespace AITactics
{

template<typename TEvent>
class IEventHandlerContext
{
    virtual void OnEventHandled() = 0;
    virtual TEvent const& GetEvent() const = 0;
};

} // namespace AITactics