#include "chili_effect_auto.hpp"
#include "ensCommon.h"
#include "ensRippleNode.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_chili_effect_CrippleSprite_setIsDrawDebug(lua_State* tolua_S)
{
    int argc = 0;
    ens::CrippleSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CrippleSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ens::CrippleSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_chili_effect_CrippleSprite_setIsDrawDebug'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.CrippleSprite:setIsDrawDebug");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_chili_effect_CrippleSprite_setIsDrawDebug'", nullptr);
            return 0;
        }
        cobj->setIsDrawDebug(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CrippleSprite:setIsDrawDebug",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_chili_effect_CrippleSprite_setIsDrawDebug'.",&tolua_err);
#endif

    return 0;
}
int lua_chili_effect_CrippleSprite_init(lua_State* tolua_S)
{
    int argc = 0;
    ens::CrippleSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CrippleSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ens::CrippleSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_chili_effect_CrippleSprite_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        double arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.CrippleSprite:init");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "cc.CrippleSprite:init");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_chili_effect_CrippleSprite_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CrippleSprite:init",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_chili_effect_CrippleSprite_init'.",&tolua_err);
#endif

    return 0;
}
int lua_chili_effect_CrippleSprite_doTouch(lua_State* tolua_S)
{
    int argc = 0;
    ens::CrippleSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CrippleSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ens::CrippleSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_chili_effect_CrippleSprite_doTouch'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Vec2 arg0;
        double arg1;
        double arg2;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "cc.CrippleSprite:doTouch");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "cc.CrippleSprite:doTouch");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "cc.CrippleSprite:doTouch");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_chili_effect_CrippleSprite_doTouch'", nullptr);
            return 0;
        }
        cobj->doTouch(arg0, arg1, arg2);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CrippleSprite:doTouch",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_chili_effect_CrippleSprite_doTouch'.",&tolua_err);
#endif

    return 0;
}
int lua_chili_effect_CrippleSprite_constructor(lua_State* tolua_S)
{
    int argc = 0;
    ens::CrippleSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_chili_effect_CrippleSprite_constructor'", nullptr);
            return 0;
        }
        cobj = new ens::CrippleSprite();
        tolua_pushusertype(tolua_S,(void*)cobj,"cc.CrippleSprite");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CrippleSprite:CrippleSprite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_chili_effect_CrippleSprite_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_chili_effect_CrippleSprite_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CrippleSprite)");
    return 0;
}

int lua_register_chili_effect_CrippleSprite(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CrippleSprite");
    tolua_cclass(tolua_S,"CrippleSprite","cc.CrippleSprite","cc.CCSprite",nullptr);

    tolua_beginmodule(tolua_S,"CrippleSprite");
        tolua_function(tolua_S,"new",lua_chili_effect_CrippleSprite_constructor);
        tolua_function(tolua_S,"setIsDrawDebug",lua_chili_effect_CrippleSprite_setIsDrawDebug);
        tolua_function(tolua_S,"init",lua_chili_effect_CrippleSprite_init);
        tolua_function(tolua_S,"doTouch",lua_chili_effect_CrippleSprite_doTouch);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(ens::CrippleSprite).name();
    g_luaType[typeName] = "cc.CrippleSprite";
    g_typeCast["CrippleSprite"] = "cc.CrippleSprite";
    return 1;
}
TOLUA_API int register_all_chili_effect(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_chili_effect_CrippleSprite(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

