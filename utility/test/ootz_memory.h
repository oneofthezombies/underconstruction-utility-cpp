#pragma once

#include <iostream>
#include <stdexcept>
#include <unordered_set>

#include "ootz_utility.h"

namespace ootz
{

class MemoryAllocator
{
private:
    static std::unordered_set<void*> memoryallocators_;

public:
    static void CheckNumUnreleaseds();

public:
    MemoryAllocator() = default;
    ~MemoryAllocator() = default;

    void* operator new(std::size_t size);
    void operator delete(void* p);
};

class Memory
{
public:
    template<typename T, 
    std::enable_if_t<std::is_pointer_v<T>, int> = 0>

    static void SafeRelease(T& p)
    {
        Utility::SafeOperation(p, [](T& p) 
        { 
            p->Release(); 
            p = nullptr; 
        });
    }

    template<typename T, 
    std::enable_if_t<std::is_pointer_v<T>, int> = 0>

    static void SafeDelete(T& p)
    {
        if(p)
        { 
            delete p; 
            p = nullptr; 
        };
    }

    template<typename T, 
    std::enable_if_t<std::is_pointer_v<T>, int> = 0>

    static void SafeDeleteArray(T& p)
    {
        Utility::SafeOperation(p, [](T& p) 
        {
            delete[] p; 
            p = nullptr; 
        });
    }

    template<typename T, typename ...Args>
    static T* TryNew(Args... args)
    {
        T* inst = nullptr;

        try
        {
            inst = new T(args...);
        }
        catch (std::bad_alloc& ba)
        {
            std::cerr << "bad_alloc caught: " << ba.what() << '\n';
        }

        return inst;
    }
};

} // namespace ootz