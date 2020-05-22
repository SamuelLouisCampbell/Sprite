#include "Lasers.h"

Lasers::Lasers(Vec2 pos_in)
	:
	pos(pos_in)
{
}

void Lasers::Draw(Graphics& gfx)
{
	laserAnimintMain.Draw((Vei2)drawCentre, gfx, false, false);
	laserAnimintSub0.Draw((Vei2)drawCentre, gfx, false, false);
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
