#pragma once
#include "Font.h"
class Scoreboard
{
public:
	Scoreboard(int hp);
	void SetHp(int hp);
	void UpdateScore(int add);
	void DrawScore(Graphics& gfx, Vec2& pos) const;
	void DrawHP(Graphics& gfx, Vec2& pos) const;

private:
	int score = 0; 
	int hpMax;
	int hpCur;
	Font theText = { "Images\\Fixedsys16x28.bmp" };
};

