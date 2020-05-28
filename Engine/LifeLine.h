#pragma once
#include "Rect.h"
#include "Graphics.h"
#include "Colors.h"

class LifeLine
{
public:
	LifeLine(const Vec2 size, const Vec2 pos, const Color bc, const Color lc)
		:
		tileSize(size),
		pos(pos), 
		bc(bc),
		lc(lc),
		lifeLeft(pos.x + (tileSize.x / 2))
	{}

	void Draw(Graphics& gfx)
	{
		gfx.DrawRect(baseRect, bc);
		gfx.DrawRect(lifeRect, lc);
	}
	void UpdatePos(Vec2& pos_in)
	{
		pos = pos_in; 
		baseRect = { pos.x - (tileSize.x / 2), pos.x + (tileSize.x / 2), pos.y - (tileSize.y / 2), pos.y + (tileSize.y / 2) };
		lifeRect = { 
			pos.x - (tileSize.x / 2), 
			pos.x - (tileSize.x / 2) + (baseRect.GetWidth() * fractional),
			pos.y - (tileSize.y / 2), 
			pos.y + (tileSize.y / 2) 
				};
		
		
	}
	void UpdateDraw(const int life, const int maxLife)
	{
		fractional =  float(life) / float(maxLife);
		//lifeLeft = lifeRect.left + (baseRect.GetWidth() * fractional); 
	}
private:
	float fractional = 1.0f;
	Vec2 pos; 
	Vec2 tileSize;
	RectF baseRect;
	RectF lifeRect;
	Color bc;
	Color lc;
	float lifeLeft;
	bool isInit = false;
};

