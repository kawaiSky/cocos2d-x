#include "base/ccConfig.h"
#ifndef __chili_h__
#define __chili_h__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

int register_all_chili(lua_State* tolua_S);






#endif // __chili_h__
