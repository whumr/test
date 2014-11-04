#include "npc/BossSprite.h"

static BossSprite* shareBossSprite = nullptr;

BossSprite* BossSprite::getInstance(){
	if(shareBossSprite == NULL){
		shareBossSprite = new BossSprite();
		if(!shareBossSprite->init()){
			delete(shareBossSprite);
			shareBossSprite = NULL;
			CCLOG("ERROR: Could not init shareBossSprite");
		}
	}
	return shareBossSprite;
}

bool BossSprite::init() {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Boss7.plist", "Boss7.png");
	
	auto ac = AnimationCache::getInstance();

	auto walk_animation = this->createAnimation("Boss7Walk%d.png", 1, 16, 10);
	ac->addAnimation(walk_animation, "walk");
	
	auto attack1_animation = this->createAnimation("Boss7Attack1_%d.png", 1, 11, 10);
	ac->addAnimation(attack1_animation, "attack1");

	auto attack2_animation = this->createAnimation("Boss7Attack2_%d.png", 1, 9, 10);
	ac->addAnimation(attack2_animation, "attack2");

	auto attack3_animation = this->createAnimation("Boss7Attack3_%d.png", 1, 12, 10);
	ac->addAnimation(attack3_animation, "attack3");

	auto attack4_animation = this->createAnimation("Boss7Attack4_%d.png", 1, 11, 10);
	ac->addAnimation(attack4_animation, "attack4");

	auto attack5_animation = this->createAnimation("Boss7Attack5_%d.png", 1, 17, 10);
	ac->addAnimation(attack5_animation, "attack5");

	auto dead_animation = this->createAnimation("Boss7Dead%d.png", 1, 18, 10);
	ac->addAnimation(dead_animation, "dead");

	auto hurt_animation = this->createAnimation("Boss7Hurt%d.png", 1, 10, 10);
	ac->addAnimation(hurt_animation, "hurt");

	auto stand_animation = this->createAnimation("Boss7Stand%d.png", 1, 16, 10);
	ac->addAnimation(stand_animation, "stand");

	return true;
}

bool BossSprite::createBoss() {
	this->initWithSpriteFrameName("Boss7Stand1.png");
	return true;
}

void BossSprite::walk() {	
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation("walk"))));
}

void BossSprite::dead() {	
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation("dead"))));
}

void BossSprite::stand() {	
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation("stand"))));
}

void BossSprite::hurt() {	
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation("hurt"))));
}

void BossSprite::attack(int i) {
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(AnimationCache::getInstance()->
		getAnimation(String::createWithFormat("attack%d",i)->getCString()))));
}

Animation* BossSprite::createAnimation(const char *fmt, int start, int end, float fps) {
	auto spriteFrameCache = SpriteFrameCache::getInstance();
    auto animation = Animation::create();
    animation->setDelayPerUnit(1/fps);
	for (int i = start; i <= end; i++){
		const char *filename = String::createWithFormat(fmt, i)->getCString();
		auto frame = spriteFrameCache->getSpriteFrameByName(filename);
		animation->addSpriteFrame(frame);
	}
	return animation;
}