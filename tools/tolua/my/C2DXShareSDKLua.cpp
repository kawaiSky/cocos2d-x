//
//  C2DXShareSDKLua.cpp
//  arkanoid
//
//  Created by 郑少凯 on 14/12/31.
//
//

#include "C2DXShareSDKLua.h"
static C2DXShareSDKLua* _instance = nullptr;
C2DXShareSDKLua::C2DXShareSDKLua()
:_authorizeHandle(0){

}
void C2DXShareSDKLua::authorize(int plat,int luaHandle){
    this->_authorizeHandle = luaHandle;
    C2DXShareSDK::authorize((C2DXPlatType)plat, authResultHandler);
}
C2DXShareSDKLua* getInstance(){
    if(!_instance){
        _instance = new C2DXShareSDKLua();
        _instance->retain();
    }
    return _instance;
}
void C2DXShareSDKLua::cancelAuthorize(int plat){
    C2DXShareSDK::cancelAuthorize((C2DXPlatType)plat);
}

bool C2DXShareSDKLua::hasAutorized(int plat){
    return C2DXShareSDK::hasAutorized((C2DXPlatType)plat);
}

void authResultHandler(C2DXResponseState state, C2DXPlatType platType, CCDictionary *error)
{
    switch (state) {
        case C2DXResponseStateSuccess:
            CCLog("授权成功");
            break;
        case C2DXResponseStateFail:
            CCLog("授权失败");
            break;
        default:
            break;
    }
    //执行 函数
}