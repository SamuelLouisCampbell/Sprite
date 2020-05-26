#include "Animation.h"
#include "SpriteEffect.h"

Animation::Animation( int x,int y,int width,int height,int count,
					  const Surface& sprite,float holdTime,Color chroma )
	:
	sprite( &sprite ),
	holdTime( holdTime ),
	chroma( chroma )
{
	for( int i = 0; i < count; i++ )
	{
		frames.emplace_back( x + i * width,x + (i + 1) * width,y,y + height );
	}
}

void Animation::Draw( const Vei2& pos,Graphics& gfx, bool mirrorX, bool mirrorY) const
{
	gfx.DrawSprite(pos.x, pos.y, frames[iCurFrame], *sprite, SpriteEffect::Chroma{ chroma }, mirrorX, mirrorY);
}

void Animation::Draw( const Vei2& pos,Graphics& gfx,const RectI& clip, bool mirrorX, bool mirrorY) const
{
	gfx.DrawSprite(pos.x, pos.y, frames[iCurFrame], clip, *sprite, SpriteEffect::Copy{}, mirrorX, mirrorY);
}

void Animation::DrawColor( const Vei2& pos,Graphics& gfx,Color c, bool mirrorX, bool mirrorY) const
{
	gfx.DrawSprite(pos.x, pos.y, frames[iCurFrame], *sprite, SpriteEffect::Substitution{Colors::White, Colors::Red }, mirrorX, mirrorY);
}

void Animation::Update( float dt )
{
	curFrameTime += dt;
	while( curFrameTime >= holdTime )
	{
		Advance();
		curFrameTime -= holdTime;
	}
}

void Animation::Advance()
{
	if( ++iCurFrame >= frames.size() )
	{
		iCurFrame = 0;
	}
}
