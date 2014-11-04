#ifndef __BossSprite_H__
#define __BossSprite_H__

#include "cocos2d.h"
USING_NS_CC;

class BossSprite : public Sprite {
public:
	/**
	 * Get instance
	 */
	static BossSprite* getInstance();

	/**
	* Cocos2d construct
	*/
	bool virtual init();

	bool createBoss();

	void walk();
	
	void attack(int i);

	void dead();

	void hurt();

	void stand();

private:

	static Animation *createAnimation(const char *fmt, int start, int end, float fps);
};

#endif