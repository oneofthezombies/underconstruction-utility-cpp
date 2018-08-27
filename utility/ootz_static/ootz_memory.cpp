#include "stdafx.h"
#include "ootz_memory.h"

namespace ootz
{

std::unordered_set<void*> MemoryAllocator::memoryallocators_;

void MemoryAllocator::CheckNumUnreleaseds()
{
    std::size_t numUnreleased = memoryallocators_.size();
    assert(numUnreleased == 0 && "number of memory allocators is not zero");
}

void* MemoryAllocator::operator new(std::size_t size)
{
    void* p = std::malloc(size);
    assert(p && "failed std::malloc function");
    memoryallocators_.emplace(p);
    return p;
}

void MemoryAllocator::operator delete(void* p)
{
    assert(p && "invalid argument");
    memoryallocators_.erase(p);
    std::free(p);
}

} // namespace ootz