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
	void SetPos(const Vei2& pos_in);
private:
	int tileSize;
	Surface sprite; 
	Vei2 pos;
	Vei2 drawCentre = { pos.x - (tileSize / 2), pos.y - (tileSize / 2) };
	Vec2 vel = { 0.0f, 0.0f };
	ShipType CurType = ShipType::lightCruiser;
	float speed = 110.0f;
	int healthPoints = 200;
	Vei2 topCorner = { 64,0 };
	Vei2 DrawReigonEnd = { topCorner.x + 64,topCorner.y + 64 };
	RectI drawSelect = {topCorner, DrawReigonEnd};
	RectI collisionRect;
	

	static constexpr float effectDuration = 0.045f;
	float effectTime = 0.0f;
	bool effectActive = false;

};


