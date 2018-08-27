#pragma once

#include "ootz_noncopyable.h"

namespace ootz
{

template<typename T>
class Singleton : private NonCopyable
{
public:
    static T& GetInstance()
    {
        static T instance_;
        return instance_;
    }
};

} // namespace ootz