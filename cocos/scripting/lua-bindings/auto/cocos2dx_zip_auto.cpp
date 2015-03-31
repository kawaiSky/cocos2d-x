#include "cocos2dx_zip_auto.hpp"
#include "ZipUtils.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_zip_ZipUtils_setPvrEncryptionKey(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.ZipUtils",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 4)
    {
        unsigned int arg0;
        unsigned int arg1;
        unsigned int arg2;
        unsigned int arg3;
        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "cc.ZipUtils:setPvrEncryptionKey");
        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "cc.ZipUtils:setPvrEncryptionKey");
        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "cc.ZipUtils:setPvrEncryptionKey");
        ok &= luaval_to_uint32(tolua_S, 5,&arg3, "cc.ZipUtils:setPvrEncryptionKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_zip_ZipUtils_setPvrEncryptionKey'", nullptr);
            return 0;
        }
        cocos2d::ZipUtils::setPvrEncryptionKey(arg0, arg1, arg2, arg3);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.ZipUtils:setPvrEncryptionKey",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_zip_ZipUtils_setPvrEncryptionKey'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_zip_ZipUtils_inflateMemory(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.ZipUtils",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        unsigned char* arg0;
        ssize_t arg1;
        unsigned char** arg2;
        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*
		ok = false;
        ok &= luaval_to_ssize(tolua_S, 3, &arg1, "cc.ZipUtils:inflateMemory");
        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char**
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_zip_ZipUtils_inflateMemory'", nullptr);
            return 0;
        }
        ssize_t ret = cocos2d::ZipUtils::inflateMemory(arg0, arg1, arg2);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.ZipUtils:inflateMemory",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_zip_ZipUtils_inflateMemory'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_zip_ZipUtils_isCCZFile(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.ZipUtils",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.ZipUtils:isCCZFile"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_zip_ZipUtils_isCCZFile'", nullptr);
            return 0;
        }
        bool ret = cocos2d::ZipUtils::isCCZFile(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.ZipUtils:isCCZFile",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_zip_ZipUtils_isCCZFile'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_zip_ZipUtils_setPvrEncryptionKeyPart(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.ZipUtils",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        int arg0;
        unsigned int arg1;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.ZipUtils:setPvrEncryptionKeyPart");
        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "cc.ZipUtils:setPvrEncryptionKeyPart");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_zip_ZipUtils_setPvrEncryptionKeyPart'", nullptr);
            return 0;
        }
        cocos2d::ZipUtils::setPvrEncryptionKeyPart(arg0, arg1);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.ZipUtils:setPvrEncryptionKeyPart",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_zip_ZipUtils_setPvrEncryptionKeyPart'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_zip_ZipUtils_isCCZBuffer(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.ZipUtils",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const unsigned char* arg0;
        ssize_t arg1;
        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*
		ok = false;
        ok &= luaval_to_ssize(tolua_S, 3, &arg1, "cc.ZipUtils:isCCZBuffer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_zip_ZipUtils_isCCZBuffer'", nullptr);
            return 0;
        }
        bool ret = cocos2d::ZipUtils::isCCZBuffer(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.ZipUtils:isCCZBuffer",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_zip_ZipUtils_isCCZBuffer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_zip_ZipUtils_isGZipFile(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.ZipUtils",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.ZipUtils:isGZipFile"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_zip_ZipUtils_isGZipFile'", nullptr);
            return 0;
        }
        bool ret = cocos2d::ZipUtils::isGZipFile(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.ZipUtils:isGZipFile",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_zip_ZipUtils_isGZipFile'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_zip_ZipUtils_inflateMemoryWithHint(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.ZipUtils",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 4)
    {
        unsigned char* arg0;
        ssize_t arg1;
        unsigned char** arg2;
        ssize_t arg3;
        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*
		ok = false;
        ok &= luaval_to_ssize(tolua_S, 3, &arg1, "cc.ZipUtils:inflateMemoryWithHint");
        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char**
		ok = false;
        ok &= luaval_to_ssize(tolua_S, 5, &arg3, "cc.ZipUtils:inflateMemoryWithHint");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_zip_ZipUtils_inflateMemoryWithHint'", nullptr);
            return 0;
        }
        ssize_t ret = cocos2d::ZipUtils::inflateMemoryWithHint(arg0, arg1, arg2, arg3);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.ZipUtils:inflateMemoryWithHint",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_zip_ZipUtils_inflateMemoryWithHint'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_zip_ZipUtils_inflateCCZBuffer(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.ZipUtils",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        const unsigned char* arg0;
        ssize_t arg1;
        unsigned char** arg2;
        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*
		ok = false;
        ok &= luaval_to_ssize(tolua_S, 3, &arg1, "cc.ZipUtils:inflateCCZBuffer");
        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char**
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_zip_ZipUtils_inflateCCZBuffer'", nullptr);
            return 0;
        }
        int ret = cocos2d::ZipUtils::inflateCCZBuffer(arg0, arg1, arg2);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.ZipUtils:inflateCCZBuffer",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_zip_ZipUtils_inflateCCZBuffer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_zip_ZipUtils_inflateGZipFile(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.ZipUtils",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const char* arg0;
        unsigned char** arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.ZipUtils:inflateGZipFile"); arg0 = arg0_tmp.c_str();
        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char**
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_zip_ZipUtils_inflateGZipFile'", nullptr);
            return 0;
        }
        int ret = cocos2d::ZipUtils::inflateGZipFile(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.ZipUtils:inflateGZipFile",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_zip_ZipUtils_inflateGZipFile'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_zip_ZipUtils_uncompressDir(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.ZipUtils",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.ZipUtils:uncompressDir"); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "cc.ZipUtils:uncompressDir"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_zip_ZipUtils_uncompressDir'", nullptr);
            return 0;
        }
        bool ret = cocos2d::ZipUtils::uncompressDir(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.ZipUtils:uncompressDir",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_zip_ZipUtils_uncompressDir'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_zip_ZipUtils_isGZipBuffer(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.ZipUtils",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const unsigned char* arg0;
        ssize_t arg1;
        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*
		ok = false;
        ok &= luaval_to_ssize(tolua_S, 3, &arg1, "cc.ZipUtils:isGZipBuffer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_zip_ZipUtils_isGZipBuffer'", nullptr);
            return 0;
        }
        bool ret = cocos2d::ZipUtils::isGZipBuffer(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.ZipUtils:isGZipBuffer",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_zip_ZipUtils_isGZipBuffer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_zip_ZipUtils_inflateCCZFile(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.ZipUtils",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const char* arg0;
        unsigned char** arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.ZipUtils:inflateCCZFile"); arg0 = arg0_tmp.c_str();
        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char**
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_zip_ZipUtils_inflateCCZFile'", nullptr);
            return 0;
        }
        int ret = cocos2d::ZipUtils::inflateCCZFile(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.ZipUtils:inflateCCZFile",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_zip_ZipUtils_inflateCCZFile'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_zip_ZipUtils_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ZipUtils)");
    return 0;
}

int lua_register_cocos2dx_zip_ZipUtils(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.ZipUtils");
    tolua_cclass(tolua_S,"ZipUtils","cc.ZipUtils","",nullptr);

    tolua_beginmodule(tolua_S,"ZipUtils");
        tolua_function(tolua_S,"setPvrEncryptionKey", lua_cocos2dx_zip_ZipUtils_setPvrEncryptionKey);
        tolua_function(tolua_S,"inflateMemory", lua_cocos2dx_zip_ZipUtils_inflateMemory);
        tolua_function(tolua_S,"isCCZFile", lua_cocos2dx_zip_ZipUtils_isCCZFile);
        tolua_function(tolua_S,"setPvrEncryptionKeyPart", lua_cocos2dx_zip_ZipUtils_setPvrEncryptionKeyPart);
        tolua_function(tolua_S,"isCCZBuffer", lua_cocos2dx_zip_ZipUtils_isCCZBuffer);
        tolua_function(tolua_S,"isGZipFile", lua_cocos2dx_zip_ZipUtils_isGZipFile);
        tolua_function(tolua_S,"inflateMemoryWithHint", lua_cocos2dx_zip_ZipUtils_inflateMemoryWithHint);
        tolua_function(tolua_S,"inflateCCZBuffer", lua_cocos2dx_zip_ZipUtils_inflateCCZBuffer);
        tolua_function(tolua_S,"inflateGZipFile", lua_cocos2dx_zip_ZipUtils_inflateGZipFile);
        tolua_function(tolua_S,"uncompressDir", lua_cocos2dx_zip_ZipUtils_uncompressDir);
        tolua_function(tolua_S,"isGZipBuffer", lua_cocos2dx_zip_ZipUtils_isGZipBuffer);
        tolua_function(tolua_S,"inflateCCZFile", lua_cocos2dx_zip_ZipUtils_inflateCCZFile);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::ZipUtils).name();
    g_luaType[typeName] = "cc.ZipUtils";
    g_typeCast["ZipUtils"] = "cc.ZipUtils";
    return 1;
}
TOLUA_API int register_all_cocos2dx_zip(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_cocos2dx_zip_ZipUtils(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

