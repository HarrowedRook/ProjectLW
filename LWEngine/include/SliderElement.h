#ifndef _SLIDERELEMENT_H
#define _SLIDERELEMENT_H

#include "UIElement.h"
#include "ButtonElement.h"
class SliderElement : public UIElement
{
public:
	SliderElement(EventListener * e, int noOfLines, int noOfLinesPerPage, Panel background, SDL_Texture * downArrow, SDL_Texture * upArrow);
	~SliderElement();

	void Update();
	void Render(SDL_Renderer & r);

private:

	Panel m_panel;
	ButtonElement m_upButton, m_downButton, m_sliderButton;
	int m_numberOfLines, m_visibleLines, m_currentTopLine;
	bool m_buttonHeld;
	int m_mousePositionY, m_mouseDifference;
	int m_timer;
	const int TIMER = 5;
};
#endif

