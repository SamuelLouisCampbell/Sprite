#include "Background.h"

Background::Background(const std::string filename)
	:
	bg0(filename)
{
	startPos.y = bg0.GetRect().top - bg0.GetHeight();
	startPos.x = 0; 
}

void Background::Draw(Graphics& gfx)
{

	if (startPos.y < Graphics::ScreenHeight + (bg0.GetHeight()/2))
	{
		startPos.y += scrollSpeed;
	}
	else
	{
		startPos.y = bg0.GetRect().top - bg0.GetHeight();
	}
	gfx.DrawSprite(startPos.x,startPos.y, bg0, SpriteEffect::Copy{}, false, false);

	if (startPos.y > 0)
	{
	gfx.DrawSprite(startPos.x, startPos.y - bg0.GetHeight(), bg0, SpriteEffect::Copy{}, false, false);
	}
	else if (startPos.y < Graphics::ScreenHeight)
	{
		gfx.DrawSprite(startPos.x, startPos.y + bg0.GetHeight(), bg0, SpriteEffect::Copy{}, false, false);
	}

	
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
