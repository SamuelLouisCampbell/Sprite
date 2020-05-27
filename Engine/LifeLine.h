#pragma once
#include "Rect.h"
#include "Graphics.h"
#include "Colors.h"

class LifeLine
{
public:
	LifeLine(const RectF base_in, const Vei2 offset, const Color bc, const Color lc)
		:
		baseRect(base_in),
		lifeRect(base_in),
		offset(offset), 
		bc(bc),
		lc(lc)
	{}

	void Draw(Graphics& gfx)
	{
		gfx.DrawRect(baseRect, bc);
		gfx.DrawRect(lifeRect, lc);
	}
	void Update(const int life)
	{
		if (lifeRect.right > lifeRect.left)
		{
			lifeRect.right = lifeRect.left + life;
		}
	
	}
private:
	Vei2 offset;
	RectF baseRect;
	RectF lifeRect;
	Color bc;
	Color lc;
};

