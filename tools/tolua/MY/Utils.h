//
//  Utils.h
//  arkanoid
//
//  Created by 郑少凯 on 15/4/10.
//
//

#ifndef __arkanoid__Utils__
#define __arkanoid__Utils__

#include <stdio.h>
#include "cocos2d.h"
#include <string>
using namespace cocos2d;
using namespace std;
class MyUtils:public cocos2d::Ref{
public:
    static MyUtils* getInstance();
    /**
     *only for rgba 8888
     */
    Color4B getPixelColor(Image* image,Point pt,bool upside = true);
    static void renderNow();
private:
    static MyUtils* _instance;
};
#endif /* defined(__arkanoid__Utils__) */
