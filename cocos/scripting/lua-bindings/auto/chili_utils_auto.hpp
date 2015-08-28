#include "base/ccConfig.h"
#ifndef __chili_utils_h__
#define __chili_utils_h__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

int register_all_chili_utils(lua_State* tolua_S);





#endif // __chili_utils_h__
