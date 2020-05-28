/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )

{
	bgSound.Play(1.0f, 0.5f);

}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
#ifdef NDEBUG
	float dt = ft.Mark();
#else
	const float dt = 1.0f / 60.0f;
#endif

	if (launchEnemyWave)
	{
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_real_distribution<float> xDist(gfx.GetScreenRect().left, gfx.GetScreenRect().right);
		std::uniform_real_distribution<float> yDist(gfx.GetScreenRect().top, gfx.GetScreenRect().bottom);
		
		for (int i = 0; i < 2; i++)
		{
			int a = 32; 
			Vec2 pos = {float(200 + a), float(200)};
			enemies.emplace_back(pos , gfx.GetScreenRect());
			a += 32;
		}
		launchEnemyWave = false; 
	}

	const auto e = wnd.mouse.Read();
	if (e.GetType() == Mouse::Event::Type::LPress)
	{
		Vec2 lasVec = { 0.0f, -300.0f };
		lasers.emplace_back(ship.GetPos(),lasVec);
	}
	for (auto& l : lasers)
	{
		l.Update(dt);
	}

	ship.SetPos(wnd.mouse.GetPosF());
	ship.Update({ 0,0 }, dt);
	for (auto& e : enemies)
	{
		e.Update(dt);
	
		const auto enemy_hitbox = e.GetCollisionRect();
		for (size_t i = 0u; i < lasers.size(); )
		{
			if (lasers[i].GetHitbox().IsOverlappingWith(enemy_hitbox) && e.IsAlive())
			{
				e.TakeDamageOnHit(25);
				remove_element(lasers, i);
				continue;
			}
			else if (lasers[i].GetHitbox().bottom < gfx.GetScreenRect().top)
			{
				remove_element(lasers, i);
				continue;
			}
			i++;
		}
	}

}

void Game::ComposeFrame()
{
	//bg.Draw(gfx); //draw bg first...
	ship.Draw(gfx);
	for (auto& e : enemies)
	{
		e.Draw(gfx);
	}
	
	for (auto& l : lasers)
	{
		l.Draw(gfx);
		//gfx.DrawBorder(l.GetHitbox(), 1, Colors::Green);
	}
	
	//gfx.DrawBorder(ship.GetCollisionRect(), 1, Colors::Cyan);
	//gfx.DrawBorder(enemy.GetCollisionRect(), 1, Colors::Red);
}
