#pragma once

#include "stdafx.h"

template<typename T>
class Singleton : private boost::noncopyable
{
public:
    static T& GetInstance()
    {
        static T instance_;
        return instance_;
    }

protected:
    Singleton() = default;

public:
    virtual ~Singleton() = default;
};
