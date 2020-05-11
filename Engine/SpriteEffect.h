#pragma once
#include "Colors.h"
#include "Graphics.h"

namespace SpriteEffect
{
	class Chroma
	{
	public:
		Chroma(Color c)
			:
			chroma(c)
		{}
		void operator()(Color cSrc, int xDest, int yDest, Graphics& gfx) const
		{
			if(cSrc != chroma)
			{
					gfx.PutPixel(xDest, yDest, cSrc);
			}
		}
	private:
		Color chroma; 
	};

	class Substitution
	{
	public:
		Substitution(Color c, Color s)
			:
			chroma(c),
			sub(s)
		{}
		void operator()(Color cSrc, int xDest, int yDest, Graphics& gfx) const
		{
			if (cSrc != chroma)
			{
				gfx.PutPixel(xDest, yDest, sub);
			}
		}
	private:
		Color chroma = Colors::Magenta;
		Color sub; 
	};
	class Copy
	{
	public:
		void operator()(Color cSrc, int xDest, int yDest, Graphics& gfx) const
		{
				gfx.PutPixel(xDest, yDest, cSrc);
		}
	};
	class Ghost
	{
	public:
		Ghost(Color c)
			:
			chroma(c)
		{}
		void operator()(Color cSrc, int xDest, int yDest, Graphics& gfx) const
		{
			if (cSrc != chroma)
			{
				const Color dest = gfx.GetPixel(xDest, yDest);
				const Color blend = {
					unsigned char((cSrc.GetR() + dest.GetR()) / 2),
					unsigned char((cSrc.GetG() + dest.GetG()) / 2),
					unsigned char((cSrc.GetB() + dest.GetB()) / 2)
				};
				gfx.PutPixel(xDest, yDest, blend);
			}
		}
	private:
		Color chroma;
	};
	class RotateBRG 
	{
	public:
		RotateBRG(Color c)
			:
			chroma(c)
		{}
		void operator()(Color cSrc, int xDest, int yDest, Graphics& gfx) const
		{
			if (cSrc != chroma)
			{
				const Color inv = {
					unsigned char(cSrc.GetB()),
					unsigned char(cSrc.GetR()),
					unsigned char(cSrc.GetG())
				};
				gfx.PutPixel(xDest, yDest, inv);
			}
		}
	private:
		Color chroma;
	};
	class RotateGBR
	{
	public:
		RotateGBR(Color c)
			:
			chroma(c)
		{}
		void operator()(Color cSrc, int xDest, int yDest, Graphics& gfx) const
		{
			if (cSrc != chroma)
			{
				const Color inv = {
					unsigned char(cSrc.GetG()),
					unsigned char(cSrc.GetB()),
					unsigned char(cSrc.GetR())
				};
				gfx.PutPixel(xDest, yDest, inv);
			}
		}
	private:
		Color chroma;
	};
	class Invert
	{
	public:
		Invert(Color c)
			:
			chroma(c)
		{}
		void operator()(Color cSrc, int xDest, int yDest, Graphics& gfx) const
		{
			if (cSrc != chroma)
			{
				const Color inv = {
					unsigned char((cSrc.GetB() + cSrc.GetG()) / 2),
					unsigned char((cSrc.GetR() + cSrc.GetB()) / 2),
					unsigned char((cSrc.GetG() + cSrc.GetR()) / 2),
				};
				gfx.PutPixel(xDest, yDest, inv);
			}
		}
	private:
		Color chroma;
	};

}