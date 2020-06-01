#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Surface.h"
#include "Rect.h"
#include "Animation.h"
#include "Lasers.h"
#include "LifeLine.h"
#include "Explosion.h"
#include <memory>


class Enemy
{
public:
	Enemy(const Vec2& pos, const RectI& reboundRect, const Surface& sfc, const Surface& explosion_sfc);
	void Draw(Graphics& gfx);
	void Update(float dt);
	RectF GetCollisionRect() const;
	void TakeDamageOnHit(int damage_amount);
	bool IsAlive() const;
	int GetHP()const;
	Vec2 GetPos()const;


private:
	void ActivateEffect();
private:
	RectF size = { 0,32,0,31 };
	Surface sfc;
	Animation animation;
	RectI reboundRect; 
	Vec2 pos;
	Vec2 drawCentre;
	int tileSize = int(size.right);
	Vec2 vec = { 200,200 };
	float speed = 100.0f;
	static constexpr float effectDuration = 0.045f;
	float effectTime = 0.0f;
	bool effectActive = false;
	static constexpr int maxHP = 100; 
	int HealthPoints = maxHP;
	RectF collisionRect;
	Vec2 llPos; 
	float llY_off = -25.0f; 
	LifeLine ll = { {30, 2},pos,Colors::Black,Colors::Red };
	std::unique_ptr<Explosion> exp;

};

