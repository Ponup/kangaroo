#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <SDL.h>

#include "Surface.h"
#include "Point.h"

class Primitives {
	private:
		static void drawPoint(SDL_Surface * screen, const Point & point, const Color & color);
		
	public:
		static void drawPixel(Surface * surface, const Point & point, const Color & color);
		static void drawLine(Surface * surface, const Point & from, const Point & to, const Color & color);
};

#endif