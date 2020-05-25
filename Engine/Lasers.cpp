#include "Lasers.h"

Lasers::Lasers(Vec2 pos_in, Surface& sfc)
	:
	pos(pos_in),
	sfc(sfc)
{

}

Lasers::~Lasers()
{
}

void Lasers::Draw(Graphics& gfx)
{
	if(!hasHit)
	{ 
		laserAnimintMain.Draw((Vei2)drawCentre, gfx, false, false);
		laserAnimintSub0.Draw((Vei2)drawCentre, gfx, false, false);
	}
}

void Lasers::Update(const float dt)
{
	drawCentre = { pos.x - (tileSize.right / 2), pos.y - (tileSize.right / 2) };
	laserAnimintMain.Update(dt);
	laserAnimintSub0.Update(dt);
	pos.y -= speed * dt;
	hitBox = { pos.x - hitBoxRadius, pos.x + hitBoxRadius, pos.y - hitBoxRadius, pos.y + hitBoxRadius};
}


Vec2 Lasers::GetPos() const
{
	return pos;
}

RectF Lasers::GetHitBox() const
{
	return hitBox;
}

bool Lasers::LaserHasHit() const
{
	return hasHit;
}

void Lasers::SetHitTrue()
{
	hasHit = true;	
}
