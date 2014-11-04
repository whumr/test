#ifndef __HELLOLAYER_H__
#define __HELLOLAYER_H__

#include "cocos2d.h"
#include "ui/DL.h"
#include "npc/BossSprite.h"
USING_NS_CC;

class HelloLayer : public Layer
{
public:
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(Ref* pSender);

	bool onTouchBegan(Touch* touche, Event *event);
	    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloLayer);

private:
	BossSprite *boss;

};

#endif // __HELLOWORLD_SCENE_H__
