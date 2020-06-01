#pragma once

#include "Colors.h"
#include <string>
#include "Rect.h"
#include <memory>

class Surface
{
public:
	Surface( const std::string& filename); 
	Surface( int width,int height );
	Surface( const Surface& rhs);
	Surface(Surface&& rhs) = default;
	Surface& operator=( const Surface& rhs);
	Surface& operator=(Surface&& rhs) = default;
	void PutPixel( int x,int y,Color c );
	Color GetPixel( int x,int y ) const;
	int GetWidth() const;
	int GetHeight() const;
	RectI GetRect() const;
private:
	std::unique_ptr<Color[]> pPixels;     
	int width;
	int height;
};