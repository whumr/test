#ifndef __DL_H__
#define __DL_H__

#include "cocos2d.h"

USING_NS_CC;

class DL : public LayerColor
{
public:

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
	void okMenuItemCallback(Ref *pSender);
    void cancelMenuItemCallback(Ref *pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(DL);
};

#endif
