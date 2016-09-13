#include "Text.h"

#include <SDL.h>

#include "StringUtil.h"

#include <stdexcept>
using std::runtime_error;

Text::Text() {
	alpha = SDL_ALPHA_OPAQUE;
}

Text::Text(const string& text) {
	this->text = text;
	alpha = SDL_ALPHA_OPAQUE;
}

Text::Text(const string& text, Font *font) {
	this->text = text;
	this->font = font;
	alpha = SDL_ALPHA_OPAQUE;
}

Text::~Text() {
}

void Text::setText(const string& text) {
	this->text = text;
}

string Text::getText() const {
	return text;
}

void Text::setFont(Font *font) {
	this->font = font;
}

Font *Text::getFont() const {
	return font;
}

Dimension Text::getDimension() const {
	int width, height;
	if (TTF_SizeText(font->toSDL(), text.c_str(), &width, &height)) {
		throw runtime_error(TTF_GetError());
	}

	return Dimension(width, height);
}

void Text::setAlpha(int alpha) {
	this->alpha = alpha;
}

/*
void Text::draw(const Point &point, Surface *surface) {
	SDL_Surface *fontSurface = nullptr;
	Color color = font->getColor();
	switch (font->getStyle()) {
	case FontStyle::BLENDED:
		fontSurface
			= TTF_RenderUTF8_Blended(font->toSDL(), text.c_str(), color);
		break;
	case FontStyle::SOLID:
		fontSurface = TTF_RenderUTF8_Solid(font->toSDL(), text.c_str(), color);
		break;
	case FontStyle::SHADED:
	default: {
		SDL_Color bgColor = { 0, 0, 0 };
		fontSurface = TTF_RenderUTF8_Shaded(font->toSDL(), text.c_str(), color,
			bgColor);
	} break;
	}

	// @TODO
	if (fontSurface) {
		SDL_SetSurfaceAlphaMod(fontSurface, alpha);
		SDL_Rect dstRect = { point.x, point.y, 0, 0 };
		SDL_BlitSurface(fontSurface, nullptr, surface->toSDL(), &dstRect);
		SDL_FreeSurface(fontSurface);
	}
}
*/

SDL_Surface* Text::toSDL() {
	SDL_Surface *fontSurface = nullptr;
	Color color = font->getColor();
	switch (font->getStyle()) {
	case FontStyle::BLENDED:
		fontSurface
			= TTF_RenderUTF8_Blended(font->toSDL(), text.c_str(), color);
		break;
	case FontStyle::SOLID:
		fontSurface = TTF_RenderUTF8_Solid(font->toSDL(), text.c_str(), color);
		break;
	case FontStyle::SHADED:
	default: {
		SDL_Color bgColor = { 0, 0, 0 };
		fontSurface = TTF_RenderUTF8_Shaded(font->toSDL(), text.c_str(), color,
			bgColor);
	} break;
	}
	SDL_SetSurfaceAlphaMod(fontSurface, alpha);

	return fontSurface;
}

