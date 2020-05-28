#include "Enemy.h"

Enemy::Enemy(const Vec2& pos, const RectI& reboundRect)
	:
	pos(pos),
	reboundRect(reboundRect), 
	sfc("Images\\Enemy_1_128x32.bmp"), 
	animation({ int(size.left), int(size.top), int(size.right), int(size.bottom), 4, sfc, 0.08f, Colors::White })
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float> xDist(0, speed);
	std::uniform_real_distribution<float> yDist(0, speed);
	
	vec = { xDist(rng), yDist(rng) };
}

void Enemy::Draw(Graphics& gfx)
{
	if (HealthPoints > 0)
	{
		
		// if effect active, draw sprite replacing opaque pixels with red
		if (effectActive)
		{
			animation.DrawColor((Vei2)drawCentre, gfx, Colors::Red, false, false);
		}
		else
		{
			animation.Draw((Vei2)drawCentre, gfx, false, false);
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
	collisionRect = { pos.x - (tileSize / 4), pos.x + (tileSize / 4), pos.y - (tileSize / 4), pos.y + (tileSize / 4) };
	llPos = pos; 
	llPos.y += llY_off;
	ll.UpdatePos(llPos);
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
