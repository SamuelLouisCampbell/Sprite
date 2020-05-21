#include "Ship.h"

Ship::Ship(const Vec2& pos,const std::string filename, int tileSize)
	:
	pos(pos),
	sprite(filename),
	tileSize(tileSize)
{
}

void Ship::Draw(Graphics& gfx) const
{
	gfx.DrawSprite(int(drawCentre.x), int(drawCentre.y), drawSelect, sprite, SpriteEffect::Chroma{ Colors::White }, false, false);
}

void Ship::Update(const Vec2& vel, float deltaTime)
{
	collisionRect = {pos.x - (tileSize/4), pos.x + (tileSize/4), pos.y - (tileSize/4), pos.y+ (tileSize /4) };
}

void Ship::TakeDamage(int amount)
{
	healthPoints -= amount;
}

void Ship::RegainHP(int amount)
{
	healthPoints += amount; 
}

bool Ship::isAlive() const
{
	return healthPoints > 0; 
}

void Ship::SetPos(const Vec2& pos_in)
{
	pos = pos_in;
	drawCentre = { pos.x - (tileSize / 2), pos.y - (tileSize / 2) };
}

RectF Ship::GetCollisionRect() const
{
	return collisionRect;
}
