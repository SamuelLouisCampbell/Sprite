#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Surface.h"
#include "Rect.h"
#include "SpriteEffect.h"

class Background
{
public:
	Background(const std::string filename);
	void Draw(Graphics& gfx);
	void Update();
	void SetBgSpeeg(const float speed);
	float GetBgSpeed() const;
private:
	Surface bg0;
	float scrollSpeed = 3.0f;
	Vec2 startPos0;
	Vec2 startPos1;
};

