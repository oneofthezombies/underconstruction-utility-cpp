#pragma once

#include "ootzCommon.h"

OOTZ_BEGIN
//EXTERN_C_BEGIN

namespace mathf 
{
    EXTERN_C OOTZUTILITYDLL_API const float PI;
    EXTERN_C OOTZUTILITYDLL_API float Clamp(const float value, const float min, const float max);
} // end namespace mathf

//class Mathf
//{
//public:
//
//    static OOTZUTILITYDLL_API
//    const float PI;
//
//	// [min, max] - range between min & max, including both min & max
//	static OOTZUTILITYDLL_API 
//    float Clamp(const float value, const float min, const float max);
//};

//EXTERN_C_END
OOTZ_END
