#include "chili_utils_auto.hpp"
#include "utils.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_chili_utils_MyUtils_getPixelColor(lua_State* tolua_S)
{
    int argc = 0;
    MyUtils* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyUtils",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MyUtils*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_chili_utils_MyUtils_getPixelColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Image* arg0;
        cocos2d::Point arg1;

        ok &= luaval_to_object<cocos2d::Image>(tolua_S, 2, "cc.Image",&arg0);

        ok &= luaval_to_point(tolua_S, 3, &arg1, "MyUtils:getPixelColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_chili_utils_MyUtils_getPixelColor'", nullptr);
            return 0;
        }
        cocos2d::Color4B ret = cobj->getPixelColor(arg0, arg1);
        color4b_to_luaval(tolua_S, ret);
        return 1;
    }
    if (argc == 3) 
    {
        cocos2d::Image* arg0;
        cocos2d::Point arg1;
        bool arg2;

        ok &= luaval_to_object<cocos2d::Image>(tolua_S, 2, "cc.Image",&arg0);

        ok &= luaval_to_point(tolua_S, 3, &arg1, "MyUtils:getPixelColor");

        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "MyUtils:getPixelColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_chili_utils_MyUtils_getPixelColor'", nullptr);
            return 0;
        }
        cocos2d::Color4B ret = cobj->getPixelColor(arg0, arg1, arg2);
        color4b_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyUtils:getPixelColor",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_chili_utils_MyUtils_getPixelColor'.",&tolua_err);
#endif

    return 0;
}
int lua_chili_utils_MyUtils_renderNow(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MyUtils",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_chili_utils_MyUtils_renderNow'", nullptr);
            return 0;
        }
        MyUtils::renderNow();
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MyUtils:renderNow",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_chili_utils_MyUtils_renderNow'.",&tolua_err);
#endif
    return 0;
}
int lua_chili_utils_MyUtils_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MyUtils",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_chili_utils_MyUtils_getInstance'", nullptr);
            return 0;
        }
        MyUtils* ret = MyUtils::getInstance();
        object_to_luaval<MyUtils>(tolua_S, "MyUtils",(MyUtils*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MyUtils:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_chili_utils_MyUtils_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_chili_utils_MyUtils_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MyUtils)");
    return 0;
}

int lua_register_chili_utils_MyUtils(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MyUtils");
    tolua_cclass(tolua_S,"MyUtils","MyUtils","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"MyUtils");
        tolua_function(tolua_S,"getPixelColor",lua_chili_utils_MyUtils_getPixelColor);
        tolua_function(tolua_S,"renderNow", lua_chili_utils_MyUtils_renderNow);
        tolua_function(tolua_S,"getInstance", lua_chili_utils_MyUtils_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(MyUtils).name();
    g_luaType[typeName] = "MyUtils";
    g_typeCast["MyUtils"] = "MyUtils";
    return 1;
}
TOLUA_API int register_all_chili_utils(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_chili_utils_MyUtils(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

