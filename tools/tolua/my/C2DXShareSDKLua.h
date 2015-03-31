//
//  C2DXShareSDKLua.h
//  arkanoid
//
//  Created by 郑少凯 on 14/12/31.
//  作为 c2dx 的 桥接
//

#ifndef __arkanoid__C2DXShareSDKLua__
#define __arkanoid__C2DXShareSDKLua__

#include <stdio.h>
#include "cocos2d.h"
#include "C2DXShareSDK.h"
using namespace cn::sharesdk;
using namespace cocos2d;
class C2DXShareSDKLua :public Ref{
public:
    void authorize(int plat,int luaHandle);
    void cancelAuthorize(int plat);
    bool hasAutorized(int plat);
    static C2DXShareSDKLua* getInstance();
    C2DXShareSDKLua();
private:
    int _authorizeHandle;
    
    //static C2DXShareSDKLua* _instance;
};
void authResultHandler(C2DXResponseState state, C2DXPlatType platType, CCDictionary *error);


#endif /* defined(__arkanoid__C2DXShareSDKLua__) */
