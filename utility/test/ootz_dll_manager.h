#pragma once

#include <map>
#include <Windows.h>

#include "ootz_noncopyable.h"
#include "ootz_utility.h"
#include "ootz_memory.h"

namespace ootz
{

class Dll : private NonCopyable, public MemoryAllocator
{

// aliases
public:
    using AddressPtr = FARPROC;

private:
    using FileName = const char*;
    using AddressName = const char*;

// statics
private:
    static std::map<FileName, Dll*> dlls_;

private:
    static Dll* FindHandle(const std::map<FileName, Dll*>& collection, const char* filename);
    static Dll* LoadHandle(const char* filename);

public:
    static void Release();
    static Dll& GetHandle(const char* filename);

// non-statics
private:
    HMODULE hModule_;
    std::map<AddressName, AddressPtr> addresses_;

private:
    void ReleaseModule();
    AddressPtr FindAddress(const std::map<AddressName, AddressPtr>& collection, const char* addressname);
    AddressPtr FindAddress(const HMODULE& hmodule, const char* addressname);

public:
    Dll(const HMODULE& hmodule);
    ~Dll();

    AddressPtr GetAddressPtr(const char* addressname);
};

} // namespace ootz