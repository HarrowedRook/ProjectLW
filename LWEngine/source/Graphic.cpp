#include "Graphic.h"

Graphic::Graphic(SDL_Texture * texture, SDL_Color color, int x, int y, int offsetX, int offsetY, int width, int height, int spriteX, int spriteY, int spriteWidth, int spriteHeight)
{
	m_texture = texture;
	m_x = x;
	m_y = y;
	m_offsetX = offsetX;
	m_offsetY = offsetY;
	m_width = width;
	m_height = height;
	m_color = color;
	m_sX = spriteX;
	m_sY = spriteY;
	m_sWidth = spriteWidth;
	m_sHeight = spriteHeight;
}

void Graphic::Update()
{

}

void Graphic::Render(SDL_Renderer & r)
{
	SDL_Rect holder{ m_sX * m_sWidth, m_sY * m_sHeight, m_sWidth, m_sHeight };
	//std::cout << m_sX * m_sWidth << ", " << m_sY * m_sHeight << ", " << m_sWidth << ", " << m_sHeight;
	SDL_Rect tempRect{ m_x + m_offsetX, m_y + m_offsetY, m_width, m_height };
	SDL_SetTextureColorMod(m_texture, m_color.r, m_color.g, m_color.b);
	SDL_RenderCopy(&r, m_texture, &holder, &tempRect);
}