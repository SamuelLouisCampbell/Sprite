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
	void Draw(Graphics& gfx) const;
	void SetBgSpeeg(const float speed);
	float GetBgSpeed() const;
private:
	Surface bg; 
	float scrollSpeed = 1.0f; 

};

