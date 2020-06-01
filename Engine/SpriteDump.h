#pragma once
#include "Surface.h"

struct SpriteDump
{
public:
	const Surface enemySurface0 = ("Images\\Enemy_1_128x32.bmp");
	static constexpr int enemy0Tile = 32;
	static constexpr int enemy0Frames = 4;

	const Surface laserSurface0 = ("Images\\Lasers_64x32.bmp");
	static constexpr int laser0Tile = 8;
	static constexpr int laser0Frames = 4;

	const Surface shipSurface0 = ("Images\\Shipwithparts_512x256.bmp");
	static constexpr int ship0Tile = 64;
	static constexpr int ship0Frames = 1;

	const Surface explosionSurface0 = ("Images\\explosion-1_512x64.bmp");
	static constexpr int exp0Tile = 64;
	static constexpr int exp0Frames = 8;

	const Surface explosionSurface1 = ("Images\\explosion-6.bmp");
	static constexpr int exp1Tile = 32;
	static constexpr int exp1Frames = 8;

};

