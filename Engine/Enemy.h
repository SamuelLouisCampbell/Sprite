#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Surface.h"
#include "Rect.h"
#include "Animation.h"


class Enemy
{
public:
	Enemy(const Vec2& pos);
	void Draw(Graphics& gfx);
	void Update(float dt);
	void ActivateEffect();
	RectF GetCollisionRect() const;

private:
	Vec2 pos;
	Vec2 drawCentre;
	RectF size = { 0,32,0,31 };
	int tileSize = size.right;
	Vec2 vec = { 0,0 };
	Surface sfc = { "Images\\Enemy_1_128x32.bmp" };
	Animation animation = { int(size.left), int(size.top), int(size.right), int(size.bottom), 4, sfc, 0.08f, Colors::White };
	float speed = 110.0f;
	static constexpr float effectDuration = 0.045f;
	float effectTime = 0.0f;
	bool effectActive = false;
	int HealthPoints = 100; 
	RectF collisionRect;

};

