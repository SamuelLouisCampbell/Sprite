#include "Background.h"

Background::Background(const std::string filename)
	:
	bg(filename)
{
}

void Background::Draw(Graphics& gfx) const
{
	gfx.DrawSprite(0, 0, bg, SpriteEffect::Copy{});
}

void Background::SetBgSpeeg(const float speed)
{
	scrollSpeed = speed;
}

float Background::GetBgSpeed() const
{
	return scrollSpeed;
}
