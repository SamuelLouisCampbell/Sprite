#pragma once
#include "Animation.h"
#include "Vec2.h"
#include "SoundEffect.h"

class Explosion
{
public:
	Explosion(const Vec2& pos, const Surface& sfc, const int tileSize, const int frames)
		:
		tileSize(tileSize),
		frames(frames),
		explosion(sfc),
		explode_animation(0,0,tileSize,tileSize,frames,explosion,0.02f, Colors::Black),
		pos(pos)
	{
			
	}
	void Draw(Graphics& gfx)
	{
	 
		if (playNow && !stopper)
		{
			Vec2 offset; 
			offset.x = pos.x - (tileSize / 2);
			offset.y = pos.y - (tileSize / 2); 
			explode_animation.DrawInvert((Vei2)offset, gfx, false, false);
			if(explode_animation.GetFrameCount() >= frames -1)
			{
				stopper = true; 
			}
		}
		
	}
	void Update(float dt, Vec2& pos_in)
	{
		pos = pos_in;
		explode_animation.Update(dt);
	}
	void SetPlay(bool set)
	{
		std::mt19937 rng = std::mt19937(std::random_device{}());
		playNow = set;
		sfx.Play(rng, 0.8f);
	}
	bool GetPlay() const
	{
		return playNow;
	}

private:
	int tileSize;
	int frames;
	bool playNow = false; 
	bool stopper = false; 
	SoundEffect sfx = SoundEffect({ L"Sounds\\impact.wav" }, true, 0.1f);
	Surface explosion;
	Animation explode_animation;
	Vec2 pos;
	Vec2 vel = { 0.0f,0.0f };
};

