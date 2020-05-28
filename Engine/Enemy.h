#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Surface.h"
#include "Rect.h"
#include "Animation.h"
#include "Lasers.h"
#include "LifeLine.h"


class Enemy
{
public:
	Enemy(const Vec2& pos);
	void Draw(Graphics& gfx);
	void Update(float dt);
	RectF GetCollisionRect() const;
	void TakeDamageOnHit(int damage_amount);
	bool IsAlive() const;
	int GetHP()const;

private:
	void ActivateEffect();
private:
	Vec2 pos;
	Vec2 drawCentre;
	RectF size = { 0,32,0,31 };
	int tileSize = int(size.right);
	Vec2 vec = { 50.0f,0 };
	Surface sfc = { "Images\\Enemy_1_128x32.bmp" };
	Animation animation = { int(size.left), int(size.top), int(size.right), int(size.bottom), 4, sfc, 0.08f, Colors::White };
	float speed = 110.0f;
	static constexpr float effectDuration = 0.045f;
	float effectTime = 0.0f;
	bool effectActive = false;
	static constexpr int maxHP = 200; 
	int HealthPoints = maxHP;
	RectF collisionRect;
	Vec2 llPos; 
	float llY_off = -25.0f; 
	LifeLine ll = { {30, 2},pos,Colors::Black,Colors::Red };

};

