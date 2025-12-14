#include "Misc/Delegate.h"

template< typename R, typename... Args>
void Delegate<R,Args...>::AddBinding(std::function<R(Args...)> Function)
{

}

template< typename R, typename... Args>
void Delegate<R,Args...>::RemoveBinding(std::function<R(Args...)> Function)
{

}

template< typename R, typename... Args>
void Delegate<R,Args...>::BroadCast()
{

}