#pragma once

#include <vector>
#include <functional>
#include <cstring>

struct DelegateType{};
//struct 

template< typename R = void, typename... Args>
class Delegate
{
private:

    static bool CompareMethod(const std::vector<std::byte>& a, const void* method, std::size_t size)
    {
        if (a.size() != size) return false;
        return std::memcmp(a.data(), method, size) == 0;
    }

    struct Binding
    {
        void* Instance;
        std::vector<std::byte> MethodBytes;
        std::function<R(Args...)> Invoke;
    };

    std::vector<Binding> Bindings;
    //std::vector<std::function<R(Args...)>> EvocationList;

    template<typename Pred>
    bool EraseIf(Pred&& p)
    {
        size_t OldSize = Bindings.size();
        Bindings.erase(
            std::remove_if(Bindings.begin(), Bindings.end(), p),
            Bindings.end());
        return OldSize != Bindings.size();
    }

public:
    template<typename T>
    void Add(T* instance, R (T::*method)(Args...))
    {
        std::vector<std::byte> methodBytes(sizeof(method));
        std::memcpy(methodBytes.data(), &method, sizeof(method));

        Bindings.push_back({
            instance,
            methodBytes,
            [instance, method](Args... args) { return (instance->*method)(args...); }
        });
    }

    // Bind const method
    template<typename T>
    void Add(const T* instance, R (T::*method)(Args...) const)
    {
        std::vector<std::byte> methodBytes(sizeof(method));
        std::memcpy(methodBytes.data(), &method, sizeof(method));

        Bindings.push_back({
            const_cast<T*>(instance),
            methodBytes,
            [instance, method](Args... args) { return (instance->*method)(args...); }
        });
    }

    template<typename T>
    bool Remove(T* instance, R (T::*method)(Args...))
    {
        return EraseIf([&](auto& b) {
            return b.Instance == instance && CompareMethod(b.MethodBytes, &method, sizeof(method));
        });
    }

    template<typename T>
    bool Remove(const T* instance, R (T::*method)(Args...) const)
    {
        return EraseIf([&](auto& b) {
            return b.Instance == instance && CompareMethod(b.MethodBytes, &method, sizeof(method));
        });
    }

    template<typename T>
    bool RemoveAll(T* instance)
    {
        return EraseIf([&](auto& b) { return b.Instance == instance; });
    }

    void Clear()const { return Bindings.clear(); }

    void Broadcast(Args... Arguments)
    {
        for(Binding Function : Bindings)
        {
            Function.Invoke(Arguments...);
        }
    }
};