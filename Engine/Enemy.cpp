#include "Enemy.h"

Enemy::Enemy(const Vec2& pos, const RectI& reboundRect, const Surface& sfc)
	:
	pos(pos),
	reboundRect(reboundRect), 
	sfc(sfc),
	animation({ int(size.left), int(size.top), int(size.right), int(size.bottom), 4, sfc, 0.08f, Colors::White }),
	collisionRect({ pos.x - (tileSize / 2), pos.x + (tileSize / 2), pos.y - (tileSize / 2), pos.y + (tileSize / 2) })
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float> xDist(-speed, speed);
	std::uniform_real_distribution<float> yDist(-speed, speed);
	
	vec = { xDist(rng), yDist(rng) };
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
		if (HealthPoints < maxHP)
		{
		ll.Draw(gfx);
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
	collisionRect = { pos.x - (tileSize / 2), pos.x + (tileSize / 2), pos.y - (tileSize / 2), pos.y + (tileSize / 2) };
	llPos = pos; 
	llPos.y += llY_off;
	ll.UpdatePos(llPos);

	if (collisionRect.left <= reboundRect.left)
	{
		vec.x = -vec.x;
	}
	else if (collisionRect.right >= reboundRect.right)
	{
		vec.x = -vec.x;
	}
	if (collisionRect.top <= reboundRect.top)
	{
		vec.y = -vec.y;
	}
	else if (collisionRect.bottom >= reboundRect.bottom)
	{
		vec.y = -vec.y;
	}
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
		ll.UpdateDraw(HealthPoints, maxHP);
		ActivateEffect();
}

bool Enemy::IsAlive() const
{
	return HealthPoints > 0; 
}

int Enemy::GetHP() const
{
	return HealthPoints;
}
