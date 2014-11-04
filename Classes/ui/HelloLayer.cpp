#include "ui/HelloLayer.h"

bool HelloLayer::init()
{
    if ( !Layer::init() )
        return false;
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloLayer::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
	
	this->boss = BossSprite::getInstance();
	this->boss->createBoss();
	this->boss->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(this->boss);


	auto dispatcher = Director::getInstance()->getEventDispatcher();
    //´¥ÆÁÊÂ¼ş
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloLayer::onTouchBegan, this);
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}


void HelloLayer::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

	auto dialogLayer = DL::create();
	if(dialogLayer) {
		this->addChild(dialogLayer);
	}	
	Director::getInstance()->pause();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

int i = 0;

bool HelloLayer::onTouchBegan(Touch* touche, Event *event)
{
	i = (i + 1) % 9;
	switch (i)
	{
	case 0:
		this->boss->stand();
		break;
	case 6:
		this->boss->hurt();
		break;
	case 7:
		this->boss->walk();
		break;
	case 8:
		this->boss->dead();
		break;
	default:
		this->boss->attack(i);
	}
	return true;
}