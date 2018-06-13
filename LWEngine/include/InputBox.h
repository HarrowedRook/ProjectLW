#ifndef _INPUTBOX_H
#define _INPUTBOX_H
#include "UIElement.h"
#include "TextElement.h"
#include "EventListener.h"
#include "Panel.h"
class InputBox : public UIElement
{
public:
	InputBox();
	~InputBox();
	void Update();
	void Render(SDL_Renderer & r);
private:
	std::string m_string;
	EventListener * m_eventListener;
	Panel m_panel;
	TextElement m_textElement;
};
#endif
