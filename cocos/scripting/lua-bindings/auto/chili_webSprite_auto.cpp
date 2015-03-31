#include "chili_webSprite_auto.hpp"
#include "CCWebSprite.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_chili_webSprite_WebSprite_initWithFileUrl(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::WebSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.WebSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::WebSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_chili_webSprite_WebSprite_initWithFileUrl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.WebSprite:initWithFileUrl"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_chili_webSprite_WebSprite_initWithFileUrl'", nullptr);
            return 0;
        }
        bool ret = cobj->initWithFileUrl(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.WebSprite:initWithFileUrl",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_chili_webSprite_WebSprite_initWithFileUrl'.",&tolua_err);
#endif

    return 0;
}
int lua_chili_webSprite_WebSprite_createWithFileUrl(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.WebSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.WebSprite:createWithFileUrl"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_chili_webSprite_WebSprite_createWithFileUrl'", nullptr);
            return 0;
        }
        cocos2d::WebSprite* ret = cocos2d::WebSprite::createWithFileUrl(arg0);
        object_to_luaval<cocos2d::WebSprite>(tolua_S, "cc.WebSprite",(cocos2d::WebSprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.WebSprite:createWithFileUrl",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_chili_webSprite_WebSprite_createWithFileUrl'.",&tolua_err);
#endif
    return 0;
}
int lua_chili_webSprite_WebSprite_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.WebSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_chili_webSprite_WebSprite_create'", nullptr);
            return 0;
        }
        cocos2d::WebSprite* ret = cocos2d::WebSprite::create();
        object_to_luaval<cocos2d::WebSprite>(tolua_S, "cc.WebSprite",(cocos2d::WebSprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.WebSprite:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_chili_webSprite_WebSprite_create'.",&tolua_err);
#endif
    return 0;
}
int lua_chili_webSprite_WebSprite_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::WebSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_chili_webSprite_WebSprite_constructor'", nullptr);
            return 0;
        }
        cobj = new cocos2d::WebSprite();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.WebSprite");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.WebSprite:WebSprite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_chili_webSprite_WebSprite_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_chili_webSprite_WebSprite_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (WebSprite)");
    return 0;
}

int lua_register_chili_webSprite_WebSprite(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.WebSprite");
    tolua_cclass(tolua_S,"WebSprite","cc.WebSprite","cc.Sprite",nullptr);

    tolua_beginmodule(tolua_S,"WebSprite");
        tolua_function(tolua_S,"new",lua_chili_webSprite_WebSprite_constructor);
        tolua_function(tolua_S,"initWithFileUrl",lua_chili_webSprite_WebSprite_initWithFileUrl);
        tolua_function(tolua_S,"createWithFileUrl", lua_chili_webSprite_WebSprite_createWithFileUrl);
        tolua_function(tolua_S,"create", lua_chili_webSprite_WebSprite_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::WebSprite).name();
    g_luaType[typeName] = "cc.WebSprite";
    g_typeCast["WebSprite"] = "cc.WebSprite";
    return 1;
}
TOLUA_API int register_all_chili_webSprite(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_chili_webSprite_WebSprite(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

