#pragma once
#include "Animation.h"

class Lasers
{
public:
private:
	Animation laserAnim;
	Vec2 pos;
	float hitBoxRadius = 4.0f;
	float speed = 300.0f;
	Vec2 drawOffset = { hitBoxRadius,hitBoxRadius };
	Vec2 vel = { 0.0f,0.0f };
};

