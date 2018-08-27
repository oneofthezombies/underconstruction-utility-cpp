#include "stdafx.h"
#include "ootzMathf.h"

namespace ootz
{

const float mathf::PI = boost::math::constants::pi<float>();

float mathf::Clamp(const float value, const float min, const float max)
{
    assert(!(max < min) && "max is less than min");

    return boost::algorithm::clamp(value, min, max);
}

//const float Mathf::PI = boost::math::constants::pi<float>();
//
//float Mathf::Clamp(const float value, const float min, const float max)
//{
//	assert(NOT (max < min) && "max is less than min");
//
//    return boost::algorithm::clamp(value, min, max);
//}

} // namespace ootz