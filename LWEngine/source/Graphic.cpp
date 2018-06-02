#include "Graphic.h"

Graphic::Graphic(SDL_Texture * texture, int x, int y, int offsetX, int offsetY)
{
	m_texture = texture;
	m_x = x;
	m_y = y;
	m_offsetX = offsetX;
	m_offsetY = offsetY;
}

void Graphic::Update()
{

}

void Graphic::Render(SDL_Renderer & r)
{
	SDL_Rect tempRect{ m_x, m_y , m_offsetX, m_offsetX };
	SDL_RenderCopy(&r, m_texture, NULL, &tempRect);
}