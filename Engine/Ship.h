#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "SpriteEffect.h"
#include "Surface.h"

class Ship
{
private:
	enum class ShipType
	{
		lightCruiser,
		Cruiser,
		heavyCruiser,
		Gunner,
		fastGunner,
		Bomber,
		shieldedBomber
	};
public:
	Ship(const Vec2& pos, const std::string filename, int tileSize);
	void Draw(Graphics& gfx) const;
	void Update(const Vec2& vel, float deltaTime);
	void TakeDamage(int amount);
	void RegainHP(int amount); 
	bool isAlive() const;
	void SetPos(const Vec2& pos_in);
	Vec2 GetPos() const; 

	RectF GetCollisionRect() const; 
private:
	int tileSize;
	Surface sprite; 
	Vec2 pos;
	Vec2 drawCentre;
	Vec2 vel = { 0.0f, 0.0f };
	ShipType CurType = ShipType::lightCruiser;
	float speed = 110.0f;
	int healthPoints = 200;
	Vei2 topCorner = { tileSize,0 };
	Vei2 DrawReigonEnd = { topCorner.x + tileSize,topCorner.y + tileSize };
	RectI drawSelect = {topCorner, DrawReigonEnd};
	RectF collisionRect;

	static constexpr float effectDuration = 0.045f;
	float effectTime = 0.0f;
	bool effectActive = false;

};


