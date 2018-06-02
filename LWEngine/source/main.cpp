#define SDL_MAIN_HANDLED

#include "stdafx.h"
#include "ResourceManager.h"
#include "TextBox.h"
#include "ButtonElement.h"

int main()
{
	bool running = true;

	SDL_Window* gameWindow = SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	SDL_Renderer* gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_Event *e = new SDL_Event();

	EventListener * eventListener = new EventListener();
	InputHandler inputHandler = InputHandler(e, eventListener);

	ResourceManager* resources = new ResourceManager(gameRenderer, "../Resources");
	resources->AddFontPack("SSP", "SSP_NORMAL", "SSP/SourceSansPro-Regular.ttf", "SSP_B", "SSP/SourceSansPro-Bold.ttf", "SSP_I", "SSP/SourceSansPro-Italic.ttf", "SSP_BI", "SSP/SourceSansPro-BoldItalic.ttf");

	//TextBox t = TextBox(resources->GetFontPack("SSP"), Panel(0, 0, 400, 550, 5, SDL_Color{ 200,50,50 }, SDL_Color{ 150,25,25 }));
	//t.SetTextColor(SDL_Color{ 255,255,255,255 });
	//t.SetString("[i]Saya... If he- if Onkko- if I could have shown her how catalogues of possible futures found out from the moment[\\i] I could choose, could have chosen, to stay, none of them end, ended, well. [n] None, save one: this one. The one where I left. (sigh) [b]This future ends so well for her, for Konzu, for Cetus.[\\b] As evicerating a choice as it was, it was the only one I could live with. [n] Some day, I swear, this is- but- this was... this will be borne out. [bi]Speak of this no more. To be crushed by the singular excruciates[\\bi]. (sigh) What's done is done. Enough.");

	ButtonElement b = ButtonElement(eventListener, Panel(0, 0, 200, 100, 5, SDL_Color{ 200,50,50 }, SDL_Color{ 150,25,25 }), TextElement(resources->GetFontPack("SSP"), 34, false, 0, 0, 190, 90, SDL_Color{ 255,255,255,255 }), "Button", 5, 5);

	while (running)
	{
		b.Update();
		inputHandler.InputCheck();
		if (b.Activated())
		{
			b.GetPanel()->X(b.GetPanel()->X() + 1);
		}
		SDL_SetRenderDrawColor(gameRenderer, 0, 0, 0, 0);
		SDL_RenderClear(gameRenderer);
		//Draw Code Here
		b.Render(*gameRenderer);
		//
		SDL_RenderPresent(gameRenderer);
	}
	return 0;
}