#include "Enemy.h"

Enemy::Enemy(const Vec2& pos)
	:
	pos(pos)
{
}

void Enemy::Draw(Graphics& gfx)
{
	// if effect active, draw sprite replacing opaque pixels with red
	if (effectActive)
	{
		animation.DrawColor((Vei2)pos, gfx, Colors::Red, false, true);
	}
	else
	{
		animation.Draw((Vei2)pos, gfx, false, true);
	}
}

void Enemy::Update(float dt)
{
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
}

void Enemy::ActivateEffect()
{
	effectActive = true;
	effectTime = 0.0f;
}
