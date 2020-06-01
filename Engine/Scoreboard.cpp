#include "Scoreboard.h"

Scoreboard::Scoreboard(int hp)
	:
	hpCur(hp),
	hpMax(hp)
{
}

void Scoreboard::SetHp(int hp)
{
	hpCur = hp; 
}

void Scoreboard::UpdateScore(int score_in)
{
	score = score_in; 
}

void Scoreboard::DrawScore(Graphics& gfx, Vec2& pos) const
{
	std::string str = "Score: ";
	std::string s = std::to_string(score);
	theText.DrawText(str + s, Vei2(pos), Colors::Yellow, gfx);
}

void Scoreboard::DrawHP(Graphics& gfx, Vec2& pos) const 
{

	std::string str = std::to_string(score);
	theText.DrawText(str, Vei2(pos), Colors::Red, gfx);
}


