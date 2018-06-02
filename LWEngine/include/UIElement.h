#ifndef _UIELEMENT_H
#define _UIELEMENT_H

#include "stdafx.h"

class UIElement
{
public:

	virtual void Update() = 0;
	virtual void Render(SDL_Renderer & r) = 0;

};
#endif