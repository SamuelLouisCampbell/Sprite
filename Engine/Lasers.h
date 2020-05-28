#pragma once
#include "Animation.h"
#include "Vec2.h"
#include "SoundEffect.h"

class Lasers
{
public:

	Lasers(const Vec2& pos, const Vec2& dir)
		:
		laser("Images\\Lasers_64x32.bmp"),
		laser_animation(0,8,8,8,4,laser,0.02f,Colors::White),
		pos(pos),
		vel(dir)
	{
		sfx.Play(rng, 0.5f);
	}
	void Draw(Graphics& gfx) const
	{
		// calculate drawing base
		const auto draw_pos = pos + draw_offset;
		// draw the laser
		laser_animation.Draw((Vei2)draw_pos, gfx, false, false);
	}
	void Update(float dt)
	{
		pos += vel * dt;
		laser_animation.Update(dt);
	}
	const Vec2& GetPos() const
	{
		return pos;
	}
	RectF GetHitbox() const
	{
		return RectF::FromCenter(pos, hitbox_halfwidth, hitbox_halfheight);
	}
	Lasers(const Lasers& src)
		:
		laser(src.laser),
		laser_animation(0, 8, 8, 8, 4, laser, 0.02f, Colors::White),
		pos(src.pos),
		vel(src.vel)
	{}
	Lasers& operator=(const Lasers& rhs)
	{
		pos = rhs.pos;
		vel = rhs.vel;
		return *this;
	}
private:
	std::mt19937 rng = std::mt19937(std::random_device{}());
	SoundEffect sfx = SoundEffect({ L"Sounds\\Laser.wav"},true, 0.1f);
	Surface laser;
	Animation laser_animation;
	Vec2 pos;
	// hitbox dimensions
	float hitbox_halfwidth = 4.0f;
	float hitbox_halfheight = 4.0f;
	// laser speed
	float speed = 150.0f;
	// this value give the offset from the actual base of the
	// character to its drawing base
	Vec2 draw_offset = { -4.0f,-4.0f };
	Vec2 vel = { 0.0f,0.0f };
};

