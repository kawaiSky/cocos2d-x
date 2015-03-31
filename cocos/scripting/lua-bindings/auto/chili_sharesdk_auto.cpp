#include "chili_sharesdk_auto.hpp"
#include "C2DXShareSDKLua.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_chili_C2DXShareSDKLua_cancelAuthorize(lua_State* tolua_S)
{
    int argc = 0;
    C2DXShareSDKLua* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"C2DXShareSDKLua",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (C2DXShareSDKLua*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_chili_C2DXShareSDKLua_cancelAuthorize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "C2DXShareSDKLua:cancelAuthorize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_chili_C2DXShareSDKLua_cancelAuthorize'", nullptr);
            return 0;
        }
        cobj->cancelAuthorize(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "C2DXShareSDKLua:cancelAuthorize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_chili_C2DXShareSDKLua_cancelAuthorize'.",&tolua_err);
#endif

    return 0;
}
int lua_chili_C2DXShareSDKLua_hasAutorized(lua_State* tolua_S)
{
    int argc = 0;
    C2DXShareSDKLua* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"C2DXShareSDKLua",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (C2DXShareSDKLua*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_chili_C2DXShareSDKLua_hasAutorized'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "C2DXShareSDKLua:hasAutorized");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_chili_C2DXShareSDKLua_hasAutorized'", nullptr);
            return 0;
        }
        bool ret = cobj->hasAutorized(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "C2DXShareSDKLua:hasAutorized",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_chili_C2DXShareSDKLua_hasAutorized'.",&tolua_err);
#endif

    return 0;
}
int lua_chili_C2DXShareSDKLua_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"C2DXShareSDKLua",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_chili_C2DXShareSDKLua_getInstance'", nullptr);
            return 0;
        }
        C2DXShareSDKLua* ret = C2DXShareSDKLua::getInstance();
        object_to_luaval<C2DXShareSDKLua>(tolua_S, "C2DXShareSDKLua",(C2DXShareSDKLua*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "C2DXShareSDKLua:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_chili_C2DXShareSDKLua_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_chili_C2DXShareSDKLua_constructor(lua_State* tolua_S)
{
    int argc = 0;
    C2DXShareSDKLua* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_chili_C2DXShareSDKLua_constructor'", nullptr);
            return 0;
        }
        cobj = new C2DXShareSDKLua();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"C2DXShareSDKLua");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "C2DXShareSDKLua:C2DXShareSDKLua",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_chili_C2DXShareSDKLua_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_chili_C2DXShareSDKLua_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (C2DXShareSDKLua)");
    return 0;
}

int lua_register_chili_C2DXShareSDKLua(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"C2DXShareSDKLua");
    tolua_cclass(tolua_S,"C2DXShareSDKLua","C2DXShareSDKLua","",nullptr);

    tolua_beginmodule(tolua_S,"C2DXShareSDKLua");
        tolua_function(tolua_S,"new",lua_chili_C2DXShareSDKLua_constructor);
        tolua_function(tolua_S,"cancelAuthorize",lua_chili_C2DXShareSDKLua_cancelAuthorize);
        tolua_function(tolua_S,"hasAutorized",lua_chili_C2DXShareSDKLua_hasAutorized);
        tolua_function(tolua_S,"getInstance", lua_chili_C2DXShareSDKLua_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(C2DXShareSDKLua).name();
    g_luaType[typeName] = "C2DXShareSDKLua";
    g_typeCast["C2DXShareSDKLua"] = "C2DXShareSDKLua";
    return 1;
}
TOLUA_API int register_all_chili(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_chili_C2DXShareSDKLua(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

