#pragma once

#include <functional>
#include <type_traits>

namespace ootz
{

class Utility
{
public:
    template<typename T, 
    std::enable_if_t<std::is_pointer_v<T>, int> = 0>

    static void SafeOperation(T& p, const std::function<void(T&)>& op)
    {
        if (p)
        {
            op(p);
        }
    }
};

} // namespace ootz