#pragma once
#include "Rect.h"
#include "Graphics.h"
#include "Colors.h"

class LifeLine
{
public:
	LifeLine(const RectF base_in, const Vei2 pos, const Color bc, const Color lc)
		:
		baseRect(base_in),
		lifeRect(base_in),
		pos(pos), 
		bc(bc),
		lc(lc)
	{}

	void Draw(Graphics& gfx)
	{

		gfx.DrawRect(baseRect, bc);
		gfx.DrawRect(lifeRect, lc);
	}
	void Update(const int life, const int maxLife)
	{
		fractional =  float(life) / float(maxLife);
		lifeRect.right = lifeRect.left + (baseRect.GetWidth() * fractional); 
	}
private:
	float fractional = 1.0f;
	Vei2 pos; 
	RectF baseRect;
	RectF lifeRect;
	Color bc;
	Color lc;
};

