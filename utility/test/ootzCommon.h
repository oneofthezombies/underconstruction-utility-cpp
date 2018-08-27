#pragma once

#ifdef OOTZUTILITYDLL_EXPORTS
#define OOTZUTILITYDLL_API __declspec(dllexport)
#else
#define OOTZUTILITYDLL_API __declspec(dllimport)
#endif

#define OOTZ_BEGIN namespace ootz {
#define OOTZ_END   } // end namespace ootz

#ifdef __cplusplus
#define EXTERN_C       extern "C"
#define EXTERN_C_BEGIN extern "C" {
#define EXTERN_C_END   } // end extern "C"
#else
#define EXTERN_C       extern
#define EXTERN_C_BEGIN
#define EXTERN_C_END
#endif

#define NOT !
