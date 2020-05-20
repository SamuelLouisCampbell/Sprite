#include "Background.h"

Background::Background(const std::string filename)
	:
	bg0(filename)
{
	startPos0.y = -bg0.GetHeight();
	startPos0.x = 0; 
	startPos1.y = 0;
	startPos1.x = 0;
}

void Background::Draw(Graphics& gfx)
{
	startPos0.y += scrollSpeed;
	startPos1.y += scrollSpeed;
	if (startPos0.y == 0)
	{
		startPos1.y = -bg0.GetHeight();
	}
	if (startPos1.y == 0)
	{
		startPos0.y = -bg0.GetHeight();
	}
	gfx.DrawSprite(startPos0.x, startPos0.y, bg0, SpriteEffect::Copy{}, false, false);
	gfx.DrawSprite(startPos1.x, startPos1.y, bg0, SpriteEffect::Copy{}, false, false);
}

void Background::Update()
{
	
}

void Background::SetBgSpeeg(const float speed)
{
	scrollSpeed = speed;
}

float Background::GetBgSpeed() const
{
	return scrollSpeed;
}
