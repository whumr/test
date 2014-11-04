#include "HelloWorldScene.h"
#include "ui/HelloLayer.h"

bool HelloWorld::init()
{
    if ( !Scene::init() )
        return false;
    
	auto hello = HelloLayer::create();
	this->addChild(hello);
    return true;
}