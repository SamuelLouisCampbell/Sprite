#pragma once
#include "Animation.h"
#include "Surface.h"
#include "Rect.h"

class Lasers
{
public:
	Lasers(Vec2 pos_in, Surface& sfc); 
	~Lasers(); 
	void Draw(Graphics& gfx);
	void Update(const float dt);
	Vec2 GetPos()const;
	RectF GetHitBox() const;
	bool LaserHasHit() const; 
	void SetHitTrue();

private:
	RectF tileSize = { 0,8,0,8 };
	Surface& sfc;
	Animation laserAnimintMain = { int(tileSize.left), int(tileSize.top + 8), int(tileSize.right), int(tileSize.bottom), 4, sfc, 0.10f, Colors::White };
	Animation laserAnimintSub0 = { int(tileSize.right * 4), int(tileSize.bottom + 8), int(tileSize.right), int(tileSize.bottom), 4, sfc, 0.08f, Colors::White };
	Vec2 pos;
	float hitBoxRadius = 4.0f;
	float speed = 300.0f;
	RectF hitBox = { pos.x - hitBoxRadius, pos.x + hitBoxRadius, pos.y - hitBoxRadius, pos.y + hitBoxRadius };
	Vec2 drawCentre = { hitBoxRadius,hitBoxRadius };
	Vec2 vel = { 0.0f,0.0f };
	bool hasHit = false; 
};

