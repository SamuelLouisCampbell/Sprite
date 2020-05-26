#include "Enemy.h"

Enemy::Enemy(const Vec2& pos)
	:
	pos(pos)
{
}

void Enemy::Draw(Graphics& gfx)
{
	if (HealthPoints > 0)
	{
		// if effect active, draw sprite replacing opaque pixels with red
		if (effectActive)
		{
			animation.DrawColor((Vei2)drawCentre, gfx, Colors::Red, false, true);
		}
		else
		{
			animation.Draw((Vei2)drawCentre, gfx, false, true);
		}
	}
}

void Enemy::Update(float dt)
{
	drawCentre = { pos.x - (tileSize / 2), pos.y - (tileSize / 2) };
	pos += vec * dt;
	animation.Update(dt);
	// update effect time if active
	if (effectActive)
	{
		effectTime += dt;
		// deactivate effect if duration exceeded
		if (effectTime >= effectDuration)
		{
			effectActive = false;
		}
	}
	collisionRect = { pos.x - (tileSize / 4), pos.x + (tileSize / 4), pos.y - (tileSize / 4), pos.y + (tileSize / 4) };
}

void Enemy::ActivateEffect()
{
	effectActive = true;
	effectTime = 0.0f;
}

RectF Enemy::GetCollisionRect() const
{
	return collisionRect;
}

void Enemy::TakeDamageOnHit(int damage_amount)
{
		HealthPoints -= damage_amount; 
		ActivateEffect();
}

bool Enemy::IsAlive() const
{
	return HealthPoints > 0; 
}
