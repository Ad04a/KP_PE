#pragma once

#include <vector>
#include <functional>


struct DelegateType{};
//struct 

template< typename R = void, typename... Args>
class Delegate
{

private:
    std::vector<std::function<R(Args...)>> EvocationList;

public:
    void AddBinding(std::function<R(Args...)> Function);
    void RemoveBinding(std::function<R(Args...)> Function);
    void BroadCast();
};