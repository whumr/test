#include "ui/DL.h"

// on "init" you need to initialize your instance
bool DL::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B(0, 0, 0, 125)) )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object

	auto *okMenuItem = MenuItemFont::create("OK", CC_CALLBACK_1(DL::okMenuItemCallback,this));
    okMenuItem->setPosition(Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2 - 50));
    
    auto *cancelMenuItem = MenuItemFont::create("Cancel", CC_CALLBACK_1(DL::cancelMenuItemCallback,this));
    cancelMenuItem->setPosition(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2 - 50)); 

    // create menu, it's an autorelease object
    auto menu = Menu::create(okMenuItem, cancelMenuItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
	    
    return true;
}

void DL::okMenuItemCallback(Ref *pSender)
{  
	CCLOG("okMenuItemCallback");
	this->removeFromParentAndCleanup(false);
    // 点击确定就退出（拷贝的原有方法）
	Director::getInstance()->end();
}

void DL::cancelMenuItemCallback(Ref *pSender)
{	   
	CCLOG("cancelMenuItemCallback");
    this->removeFromParentAndCleanup(false);
	Director::getInstance()->resume();
}
