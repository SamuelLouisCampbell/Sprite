#include "Ship.h"

Ship::Ship(const Vec2& pos, int tileSize, const Surface& sfc, const RectI& bounds)
	:
	sprite(sfc),
	pos(pos),
	tileSize(tileSize), 
	bounds(bounds)
{
}

void Ship::Draw(Graphics& gfx) const
{
	gfx.DrawSprite(int(drawCentre.x), int(drawCentre.y), drawSelect, sprite, SpriteEffect::Chroma{ Colors::White }, false, false);
}

void Ship::Update(const Vec2& vel, float deltaTime)
{
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
	drawCentre = { pos.x - (tileSize / 2), pos.y - (tileSize / 2) };
	collisionRect = { pos.x - (tileSize / 4), pos.x + (tileSize / 4), pos.y - (tileSize / 4), pos.y + (tileSize / 4) };
	pos = pos_in;

	if (pos_in.x < bounds.left)
	{
		pos.x = bounds.left;
	}
	else if (pos_in.x > bounds.right)
	{
		pos.x = bounds.right;
	}
	if (pos_in.y < bounds.top)
	{
		pos.y = bounds.top;
	}
	else if (pos_in.y > bounds.bottom)
	{
		pos.y = bounds.bottom;
	}

	
}

Vec2 Ship::GetPos() const
{
	return pos;
}

RectF Ship::GetCollisionRect() const
{
	return collisionRect;
}
