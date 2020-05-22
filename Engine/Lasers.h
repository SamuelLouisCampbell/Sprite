#pragma once
#include "Animation.h"
#include "Surface.h"
#include "Rect.h"

class Lasers
{
public:
	Lasers(Vec2 pos_in); 
	void Draw(Graphics& gfx);
	void Update(const float dt);
	Vec2 GetPos()const;

private:
	RectF tileSize = { 0,8,0,8 };
	Surface sfc = { "Images\\Lasers_64x32.bmp" };
	Animation laserAnimintMain = { int(tileSize.left), int(tileSize.top + 8), int(tileSize.right), int(tileSize.bottom), 4, sfc, 0.10f, Colors::White };
	Animation laserAnimintSub0 = { int(tileSize.right * 4), int(tileSize.bottom + 8), int(tileSize.right), int(tileSize.bottom), 4, sfc, 0.08f, Colors::White };
	Vec2 pos;
	float hitBoxRadius = 4.0f;
	float speed = 300.0f;
	RectF hitBox;
	Vec2 drawCentre = { hitBoxRadius,hitBoxRadius };
	Vec2 vel = { 0.0f,0.0f };
};

