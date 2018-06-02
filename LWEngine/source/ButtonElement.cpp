#include "ButtonElement.h"

ButtonElement::ButtonElement(EventListener * e, Panel p, Graphic g)
{
	m_eventlistener = e;
	m_typeGraphic = true;
	m_graphic = g;
	m_panel = p;
	m_graphic.X(m_panel.X());
	m_graphic.Y(m_panel.Y());
	m_colorA = m_panel.BodyColor();
	m_colorB = m_panel.MarginColor();
}

ButtonElement::ButtonElement(EventListener * e, Panel p, TextElement t, std::string text, int offsetX, int offsetY)
{
	m_text = text;
	m_eventlistener = e;
	m_typeGraphic = false;
	m_textElement = t;
	m_textElement.SetString(m_text);
	m_textOffsetX = offsetX;
	m_textOffsetY = offsetY;
	m_panel = p;
	m_textElement.X(m_panel.X() + m_textOffsetX);
	m_textElement.Y(m_panel.Y() + m_textOffsetY);
	m_colorA = m_panel.BodyColor();
	m_colorB = m_panel.MarginColor();
}

ButtonElement::~ButtonElement()
{

}

void ButtonElement::Update()
{
	m_selected = false;
	int x, y;
	SDL_GetMouseState(&x, &y);
	SDL_Rect holderA{ m_panel.X(), m_panel.Y(), m_panel.Width(), m_panel.Height() };
	SDL_Rect holderB{ x, y, 1, 1 };
	if (SDL_HasIntersection(&holderA, &holderB))
	{
		m_selected = true;
		if (!m_activated)
		{
			Uint8 r = int(m_colorB.r) + 50;
			if (r > 255)
			{
				r = 255;
			}
			Uint8 g = int(m_colorB.g) + 50;
			if (g > 255)
			{
				g = 255;
			}
			Uint8 b = int(m_colorB.b) + 50;
			if (b > 255)
			{
				b = 255;
			}
			m_panel.MarginColor(SDL_Color{ r, g, b, m_colorB.a });
		}
		if (m_eventlistener->LeftClick && m_timer <= 0)
		{
			m_activated = true;
			m_timer = 5;
			m_panel.MarginColor(m_colorB);
			m_panel.BodyColor(m_colorA);
		}
	}

	if (m_timer <= 0 && m_activated)
	{
		m_activated = false;
	}
	else if (m_activated)
	{
		m_timer--;
		m_panel.MarginColor(m_colorA);
		m_panel.BodyColor(m_colorB);
	}
	else if(!m_selected)
	{
		m_panel.MarginColor(m_colorB);
		m_panel.BodyColor(m_colorA);
		if (m_typeGraphic)
		{
			m_graphic.X(m_panel.X());
			m_graphic.Y(m_panel.Y());
			m_colorA = m_panel.BodyColor();
			m_colorB = m_panel.MarginColor();
		}
		else
		{
			m_textElement.X(m_panel.X() + m_textOffsetX);
			m_textElement.Y(m_panel.Y() + m_textOffsetY);
			m_colorA = m_panel.BodyColor();
			m_colorB = m_panel.MarginColor();
		}
	}
}

void ButtonElement::Render(SDL_Renderer & r)
{
	m_panel.Render(r);
	if (m_typeGraphic)
	{
		m_graphic.Render(r);
	}
	else
	{
		m_textElement.Render(r);
	}
}