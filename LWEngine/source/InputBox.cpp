#include "InputBox.h"



InputBox::InputBox(EventListener * e, Panel panel, FontPack * font, int offsetX, int offsetY)
{
	m_color = SDL_Color{ 255,255,255,255 };
	m_textElement = TextElement(font, 18, true, 0, 0, 0, 0, m_color);
	m_panel = panel;
	m_eventListener = e;
	m_textOffsetX = offsetX;
	m_textOffsetY = offsetY;
	m_colorA = m_panel.BodyColor();
	m_colorB = m_panel.MarginColor();
	m_timer = m_timerMax;
	m_lineAppear = false;
	m_text = "_";
	SDL_Point holder = StringSize(m_textElement.GetFontPack()->fonts.at(m_textElement.GetFontSize())->Normal, m_text);
	m_maxNumberOfLetters = ((m_panel.Width() - (m_panel.Margin() * 2)) / holder.x) - 1;
	m_text = "";
}

InputBox::~InputBox()
{
}

void InputBox::Update()
{
	m_selected = false;
	int x, y;
	SDL_GetMouseState(&x, &y);
	SDL_Rect holderA{ m_panel.X(), m_panel.Y(), m_panel.Width(), m_panel.Height() };
	SDL_Rect holderB{ x, y, 1, 1 };
	if (SDL_HasIntersection(&holderA, &holderB))
	{
		m_selected = true;
		if (m_eventListener->LeftClick)
		{
			m_activated = true;
		}
	}
	else if (m_eventListener->LeftClick)
	{
		m_activated = false;
	}

	if (m_selected)
	{
		//Adjusts border color if highlighted over. If it surpasses 255 it will be locked to 255, as having any of the colors beyond 255 will make it pure white. SDL is weird?
		Uint8 r = int(m_colorB.r) + 50;
		if (r > 255) { r = 255; }
		Uint8 g = int(m_colorB.g) + 50;
		if (g > 255) { g = 255; }
		Uint8 b = int(m_colorB.b) + 50;
		if (b > 255) { b = 255; }
		m_panel.BodyColor(m_colorA);
		m_panel.MarginColor(SDL_Color{ r, g, b, m_colorB.a });
	}
	else
	{
		m_panel.MarginColor(m_colorB);
		m_panel.BodyColor(m_colorA);
		m_colorA = m_panel.BodyColor();
		m_colorB = m_panel.MarginColor();
	}

	m_textElement.SetString(m_text);
	if (m_activated)
	{
		TextInputs();
		if (m_timer > 0)
		{
			m_timer--;
		}
		else
		{
			m_timer = m_timerMax;
			m_lineAppear = !m_lineAppear;
		}

		if (m_lineAppear)
		{
			m_textElement.SetString(m_text + "|");
		}
	}

	m_textElement.X(m_panel.X() + m_textOffsetX);
	m_textElement.Y(m_panel.Y() + m_textOffsetY);
}

void InputBox::Render(SDL_Renderer & r)
{
	m_panel.Render(r);
	m_textElement.Render(r);
}

void InputBox::TextInputs()
{
	int temp = m_text.size();
	if (m_inputTimer <= 0)
	{
		if (m_text.size() < m_maxNumberOfLetters)
		{
			if (m_eventListener->Shift)
			{
				if (m_eventListener->A) { m_text += "A"; m_eventListener->A = false; }
				else if (m_eventListener->B){ m_text += "B"; m_eventListener->B = false; }
				else if (m_eventListener->C){ m_text += "C"; m_eventListener->C = false; }
				else if (m_eventListener->D){ m_text += "D"; m_eventListener->D = false; }
				else if (m_eventListener->E){ m_text += "E"; m_eventListener->E = false; }
				else if (m_eventListener->F){ m_text += "F"; m_eventListener->F = false; }
				else if (m_eventListener->G){ m_text += "G"; m_eventListener->G = false; }
				else if (m_eventListener->H){ m_text += "H"; m_eventListener->H = false; }
				else if (m_eventListener->I){ m_text += "I"; m_eventListener->I = false; }
				else if (m_eventListener->J){ m_text += "J"; m_eventListener->J = false; }
				else if (m_eventListener->K){ m_text += "K"; m_eventListener->K = false; }
				else if (m_eventListener->L){ m_text += "L"; m_eventListener->L = false; }
				else if (m_eventListener->M){ m_text += "M"; m_eventListener->M = false; }
				else if (m_eventListener->N){ m_text += "N"; m_eventListener->N = false; }
				else if (m_eventListener->O){ m_text += "O"; m_eventListener->O = false; }
				else if (m_eventListener->P){ m_text += "P"; m_eventListener->P = false; }
				else if (m_eventListener->Q){ m_text += "Q"; m_eventListener->Q = false; }
				else if (m_eventListener->R){ m_text += "R"; m_eventListener->R = false; }
				else if (m_eventListener->S){ m_text += "S"; m_eventListener->S = false; }
				else if (m_eventListener->T){ m_text += "T"; m_eventListener->T = false; }
				else if (m_eventListener->U){ m_text += "U"; m_eventListener->U = false; }
				else if (m_eventListener->V){ m_text += "V"; m_eventListener->V = false; }
				else if (m_eventListener->W){ m_text += "W"; m_eventListener->W = false; }
				else if (m_eventListener->X){ m_text += "X"; m_eventListener->X = false; }
				else if (m_eventListener->Y){ m_text += "Y"; m_eventListener->Y = false; }
				else if (m_eventListener->Z){ m_text += "Z"; m_eventListener->Z = false; }
				else if (m_eventListener->Zero){ m_text += ")"; m_eventListener->Zero = false; }
				else if (m_eventListener->One){ m_text += "!"; m_eventListener->One = false; }
				else if (m_eventListener->Two){ m_text += '"'; m_eventListener->Two = false; }
				else if (m_eventListener->Three){ m_text += "£"; m_eventListener->Three = false; }
				else if (m_eventListener->Four) { m_text += "$"; m_eventListener->Four = false; }
				else if (m_eventListener->Five) { m_text += "%"; m_eventListener->Five = false; }
				else if (m_eventListener->Six) { m_text += "^"; m_eventListener->Six = false; }
				else if (m_eventListener->Seven) { m_text += "&"; m_eventListener->Seven = false; }
				else if (m_eventListener->Eight) { m_text += "*"; m_eventListener->Eight = false; }
				else if (m_eventListener->Nine) { m_text += "("; m_eventListener->Nine = false; }
				else if (m_eventListener->Minus) { m_text += "_"; m_eventListener->Minus = false; }
				else if (m_eventListener->Equals) { m_text += "+"; m_eventListener->Equals = false; }
			}
			else
			{
				if (m_eventListener->A) { m_text += "a"; m_eventListener->A = false; }
				else if (m_eventListener->B) { m_text += "b"; m_eventListener->B = false; }
				else if (m_eventListener->C) { m_text += "c"; m_eventListener->C = false; }
				else if (m_eventListener->D) { m_text += "d"; m_eventListener->D = false; }
				else if (m_eventListener->E) { m_text += "e"; m_eventListener->E = false; }
				else if (m_eventListener->F) { m_text += "f"; m_eventListener->F = false; }
				else if (m_eventListener->G) { m_text += "g"; m_eventListener->G = false; }
				else if (m_eventListener->H) { m_text += "h"; m_eventListener->H = false; }
				else if (m_eventListener->I) { m_text += "i"; m_eventListener->I = false; }
				else if (m_eventListener->J) { m_text += "j"; m_eventListener->J = false; }
				else if (m_eventListener->K) { m_text += "k"; m_eventListener->K = false; }
				else if (m_eventListener->L) { m_text += "l"; m_eventListener->L = false; }
				else if (m_eventListener->M) { m_text += "m"; m_eventListener->M = false; }
				else if (m_eventListener->N) { m_text += "n"; m_eventListener->N = false; }
				else if (m_eventListener->O) { m_text += "o"; m_eventListener->O = false; }
				else if (m_eventListener->P) { m_text += "p"; m_eventListener->P = false; }
				else if (m_eventListener->Q) { m_text += "q"; m_eventListener->Q = false; }
				else if (m_eventListener->R) { m_text += "r"; m_eventListener->R = false; }
				else if (m_eventListener->S) { m_text += "s"; m_eventListener->S = false; }
				else if (m_eventListener->T) { m_text += "t"; m_eventListener->T = false; }
				else if (m_eventListener->U) { m_text += "u"; m_eventListener->U = false; }
				else if (m_eventListener->V) { m_text += "v"; m_eventListener->V = false; }
				else if (m_eventListener->W) { m_text += "w"; m_eventListener->W = false; }
				else if (m_eventListener->X) { m_text += "x"; m_eventListener->X = false; }
				else if (m_eventListener->Y) { m_text += "y"; m_eventListener->Y = false; }
				else if (m_eventListener->Z) { m_text += "z"; m_eventListener->Z = false; }
				else if (m_eventListener->Zero) { m_text += "0"; m_eventListener->Zero = false; }
				else if (m_eventListener->One) { m_text += "1"; m_eventListener->One = false; }
				else if (m_eventListener->Two) { m_text += '2'; m_eventListener->Two = false; }
				else if (m_eventListener->Three) { m_text += "3"; m_eventListener->Three = false; }
				else if (m_eventListener->Four) { m_text += "4"; m_eventListener->Four = false; }
				else if (m_eventListener->Five) { m_text += "5"; m_eventListener->Five = false; }
				else if (m_eventListener->Six) { m_text += "6"; m_eventListener->Six = false; }
				else if (m_eventListener->Seven) { m_text += "7"; m_eventListener->Seven = false; }
				else if (m_eventListener->Eight) { m_text += "8"; m_eventListener->Eight = false; }
				else if (m_eventListener->Nine) { m_text += "9"; m_eventListener->Nine = false; }
				else if (m_eventListener->Minus) { m_text += "-"; m_eventListener->Minus = false; }
				else if (m_eventListener->Equals) { m_text += "="; m_eventListener->Equals = false; }
			}
		}
		if (m_eventListener->Backspace && m_text.size() > 0)
		{
			m_eventListener->Backspace = false;
			m_text.pop_back();
		}
		else if(m_eventListener->Space)
		{
			m_eventListener->Space = false;
			m_text += " ";
		}

	}
	else
	{
		m_inputTimer--;
	}
}