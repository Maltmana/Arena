#include "CoordinateTransformer.h"

CoordinateTransformer::CoordinateTransformer(Graphics & gfx)
	:
	gfx{ gfx }
{}

void CoordinateTransformer::Draw(Drawable & drawable) const
{
	const Vec2 offset{ float(gfx.ScreenWidth / 2), float(gfx.ScreenHeight / 2) };
	drawable.ConvertTranslationFromWindowsYCoordToCartesianYCoord();
	//drawable.ScaleIndependent(1.f, -1.f); this just flips the object upside down...
	drawable.Translate(offset);
	drawable.Render(gfx);
}

