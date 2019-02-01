#pragma once

namespace AITactics
{

template<typename TEvent>
class IEventHandlerContext;

template<typename TEvent>
class IEventHandler
{
    virtual void HandleEvent(IEventHandlerContext<TEvent>& eventContext) = 0;
};

} // namespace AITactics