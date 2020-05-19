#include "Background.h"

Background::Background(const std::string filename)
	:
	bg0(filename)
{
	bgSize = bg0.GetRect();
	startPos.y = bg0.GetRect().bottom;
	startPos.x = 0; 
}

void Background::Draw(Graphics& gfx)
{
	if (startPos.y < Graphics::ScreenHeight)
	{
		startPos.y += scrollSpeed;
	}
	else
	{
		startPos.y = -bgSize.GetHeight();
	}
	gfx.DrawSprite(startPos.x,startPos.y, bg0, SpriteEffect::Copy{}, false, false);
	gfx.DrawSprite(startPos.x,startPos.y + bgSize.GetHeight(), bg0, SpriteEffect::Copy{}, false, false);
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
