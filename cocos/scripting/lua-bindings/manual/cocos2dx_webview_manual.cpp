#include "cocos2dx_webview_manual.hpp"
#include "UIWebView.h"
#include "tolua_fix.h"
#include "CCLuaEngine.h"
#include "LuaBasicConversions.h"


static int cocos2dx_webview_setOnJSCallback(lua_State* tolua_S)
{
    int argc = 0;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    
#if COCOS2D_DEBUG >= 1
    //if (!tolua_isusertype(tolua_S,1,"b2PolygonShape",0,&tolua_err)) //goto tolua_lerror;
#endif
    
    auto cobj = (cocos2d::experimental::ui::WebView*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'chili_sharesdk_authorize'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        
        int handler = (  toluafix_ref_function(tolua_S,2,0));
        
        cobj->setOnJSCallback([=](cocos2d::experimental::ui::WebView *sender, const std::string &url){
            
            //tolua_pushnumber(tolua_S, fd);
            int id = (cobj) ? (int)cobj->_ID : -1;
            int* luaID = (cobj) ? &cobj->_luaID : nullptr;
            toluafix_pushusertype_ccobject(tolua_S, id, luaID, (void*)cobj,"ccexp.WebView");
            tolua_pushstring(tolua_S, url.c_str());
            
            LuaEngine::getInstance()->getLuaStack()->executeFunctionByHandler(handler, 2);
        });
        
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "set",argc, 3);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'chili_sharesdk_authorize'.",&tolua_err);
#endif
    
    return 0;
}


static int cocos2dx_webview_setOnDidFailLoading(lua_State* tolua_S)
{
    int argc = 0;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    
#if COCOS2D_DEBUG >= 1
    //if (!tolua_isusertype(tolua_S,1,"b2PolygonShape",0,&tolua_err)) //goto tolua_lerror;
#endif
    
    auto cobj = (cocos2d::experimental::ui::WebView*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'chili_sharesdk_authorize'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        
        int handler = (  toluafix_ref_function(tolua_S,2,0));
        
        cobj->setOnDidFailLoading([=](cocos2d::experimental::ui::WebView *sender, const std::string &url){
            
            //tolua_pushnumber(tolua_S, fd);
            int id = (cobj) ? (int)cobj->_ID : -1;
            int* luaID = (cobj) ? &cobj->_luaID : nullptr;
            toluafix_pushusertype_ccobject(tolua_S, id, luaID, (void*)cobj,"ccexp.WebView");
            tolua_pushstring(tolua_S, url.c_str());
            
            LuaEngine::getInstance()->getLuaStack()->executeFunctionByHandler(handler, 2);
        });
        
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "set",argc, 3);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'chili_sharesdk_authorize'.",&tolua_err);
#endif
    
    return 0;
}

static int cocos2dx_webview_setOnDidFinishLoading(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    
#if COCOS2D_DEBUG >= 1
    //if (!tolua_isusertype(tolua_S,1,"b2PolygonShape",0,&tolua_err)) //goto tolua_lerror;
#endif
    
    auto cobj = (cocos2d::experimental::ui::WebView*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'chili_sharesdk_authorize'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        
        int handler = (  toluafix_ref_function(tolua_S,2,0));
        
        cobj->setOnDidFinishLoading([=](cocos2d::experimental::ui::WebView *sender, const std::string &url){
            
            //tolua_pushnumber(tolua_S, fd);
            int id = (cobj) ? (int)cobj->_ID : -1;
            int* luaID = (cobj) ? &cobj->_luaID : nullptr;
            toluafix_pushusertype_ccobject(tolua_S, id, luaID, (void*)cobj,"ccexp.WebView");
            tolua_pushstring(tolua_S, url.c_str());
            
            LuaEngine::getInstance()->getLuaStack()->executeFunctionByHandler(handler, 2);
        });
        
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "set",argc, 3);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'chili_sharesdk_authorize'.",&tolua_err);
#endif
    
    return 0;
}


static int cocos2dx_webview_setOnShouldStartLoading(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    
#if COCOS2D_DEBUG >= 1
    //if (!tolua_isusertype(tolua_S,1,"b2PolygonShape",0,&tolua_err)) //goto tolua_lerror;
#endif
    
    auto cobj = (cocos2d::experimental::ui::WebView*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'chili_sharesdk_authorize'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        
        int handler = (  toluafix_ref_function(tolua_S,2,0));
        
        cobj->setOnShouldStartLoading([=](cocos2d::experimental::ui::WebView *sender, const std::string &url)->bool{
            
            //tolua_pushnumber(tolua_S, fd);
            int id = (cobj) ? (int)cobj->_ID : -1;
            int* luaID = (cobj) ? &cobj->_luaID : nullptr;
            toluafix_pushusertype_ccobject(tolua_S, id, luaID, (void*)cobj,"ccexp.WebView");
            tolua_pushstring(tolua_S, url.c_str());
            
            return LuaEngine::getInstance()->getLuaStack()->executeFunctionByHandler(handler, 2);
        });
        
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "set",argc, 3);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'chili_sharesdk_authorize'.",&tolua_err);
#endif
    
    return 0;
}

static void extendWebview(lua_State* L)
{
    lua_pushstring(L, "ccexp.WebView");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L, "setOnShouldStartLoading", cocos2dx_webview_setOnShouldStartLoading);
        tolua_function(L, "setOnDidFinishLoading", cocos2dx_webview_setOnDidFinishLoading);
        tolua_function(L, "setOnDidFailLoading", cocos2dx_webview_setOnDidFailLoading);
        tolua_function(L, "setOnJSCallback", cocos2dx_webview_setOnJSCallback);
    }
    lua_pop(L, 1);
}
TOLUA_API int register_all_cocos2dx_webview_manual(lua_State* tolua_S)
{
    if (nullptr == tolua_S)
        return 0;
    
    extendWebview(tolua_S);
    
    return 0;
}

