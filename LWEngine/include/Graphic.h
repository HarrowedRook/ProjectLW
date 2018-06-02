#ifndef _GRAPHIC_H
#define _GRAPHIC_H
#include "UIElement.h"
class Graphic : public UIElement
{
public:
	Graphic() {};
	Graphic(SDL_Texture * texture, int x, int y, int offsetX, int offsetY);
	~Graphic() {};

	SDL_Texture * Texture() { return m_texture; };
	void Texture(SDL_Texture * t) { m_texture = t; };

	int X() { return m_x; };
	void X(int x) { m_x = x; };

	int Y() { return m_y; };
	void Y(int x) { m_y = x; };

	int OffsetX() { return m_offsetX; };
	void OffsetX(int x) { m_offsetX = x; };

	int OffsetY() { return m_offsetY; };
	void OffsetY(int x) { m_offsetY = x; };

	void Update();

	void Render(SDL_Renderer & r);

private:

	int m_x;
	int m_y;
	int m_offsetX;
	int m_offsetY;

	SDL_Texture * m_texture;
};
#endif

