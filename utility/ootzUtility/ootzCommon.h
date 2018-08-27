#pragma once

#ifdef OOTZUTILITYDLL_EXPORTS
#define OOTZUTILITYDLL_API __declspec(dllexport)
#else
#define OOTZUTILITYDLL_API __declspec(dllimport)
#endif

#ifdef __cplusplus
#define EXTERN_C       extern "C"
#else
#define EXTERN_C       extern
#endif
