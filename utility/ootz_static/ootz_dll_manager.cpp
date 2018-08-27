#include "stdafx.h"
#include "ootz_dll_manager.h"
#include "ootz_memory.h"

namespace ootz
{

std::map<const char*, Dll*> Dll::dlls_;

Dll* Dll::FindHandle(const std::map<FileName, Dll*>& collection, const char* filename)
{
    const auto result = collection.find(filename);
    if (result != collection.end())
    {
        return result->second;
    }

    return nullptr;
}

Dll* Dll::LoadHandle(const char* filename)
{
    HMODULE hModule = LoadLibraryA(filename);

    assert(hModule && "failed dll load");

    return Memory::TryNew<Dll>(hModule);
}

void Dll::Release()
{
    std::for_each(dlls_.begin(), dlls_.end(), [](auto& it) 
    { 
        Memory::SafeDelete(it.second); 
    });
}

Dll& Dll::GetHandle(const char* filename)
{
    assert(filename && "file name is empty");

    Dll* dll = FindHandle(dlls_, filename);
    
    if (!dll)
    {
        dll = LoadHandle(filename);
        dlls_.emplace(filename, dll);
    }

    return *dll;
}

Dll::Dll(const HMODULE& hModule)
    : hModule_(hModule)
{
}

Dll::~Dll()
{
    ReleaseModule();
}

void Dll::ReleaseModule()
{
    if (!hModule_) return;

    const BOOL success = FreeLibrary(hModule_);
    if (success) return;

    const DWORD errorcode = GetLastError();
    const HRESULT hresult = HRESULT_FROM_WIN32(errorcode);

    // handle error
}

Dll::AddressPtr Dll::FindAddress(const std::map<AddressName, AddressPtr>& collection, const char* addressname)
{
    const auto result = collection.find(addressname);

    if (result != collection.end())
        return result->second;

    return nullptr;
}

Dll::AddressPtr Dll::FindAddress(const HMODULE& hmodule, const char* addressname)
{
    AddressPtr p = GetProcAddress(hmodule, addressname);

    assert(p && "failed to find address");

    return p;
}

Dll::AddressPtr Dll::GetAddressPtr(const char* addressname)
{
    assert(addressname && "address name is empty");

    AddressPtr p = FindAddress(addresses_, addressname);

    if (!p)
    {
        p = FindAddress(hModule_, addressname);
        addresses_.emplace(addressname, p);
    }

    return p;
}

} // namespace ootz