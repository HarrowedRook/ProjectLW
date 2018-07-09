#define SDL_MAIN_HANDLED

#include "stdafx.h"
#include "ResourceManager.h"
#include "TextBox.h"
#include "SliderElement.h"
#include "InputBox.h"
#include "ProgressBarElement.h"
#include "json/json.h"

#include "CraftMaterial.h"


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
	resources->AddTexture("DownArrow", "arrow_down.png");
	resources->AddTexture("UpArrow", "arrow_up.png");

	TextBox t = TextBox(eventListener, resources->GetFontPack("SSP"), Panel(0, 0, 400, 550, 5, SDL_Color{ 75, 50 ,75 }, SDL_Color{ 50, 25 ,50 }), resources->GetTexture("DownArrow"), resources->GetTexture("UpArrow"));
	t.SetTextColor(SDL_Color{ 255,255,255,255 });
	t.SetString("[i]Saya... If he- if Onkko- if I could have shown her how catalogues of possible futures found out from the moment[\\i] I could choose, could have chosen, to stay, none of them end, ended, well. [n] None, save one: this one. The one where I left. (sigh) [b]This future ends so well for her, for Konzu, for Cetus.[\\b] As evicerating a choice as it was, it was the only one I could live with. [n] Some day, I swear, this is- but- this was... this will be borne out. [bi]Speak of this no more. To be crushed by the singular excruciates[\\bi]. (sigh) What's done is done. Enough.[i]Saya... If he- if Onkko- if I could have shown her how catalogues of possible futures found out from the moment[\\i] I could choose, could have chosen, to stay, none of them end, ended, well. [n] None, save one: this one. The one where I left. (sigh) [b]This future ends so well for her, for Konzu, for Cetus.[\\b] As evicerating a choice as it was, it was the only one I could live with. [n] Some day, I swear, this is- but- this was... this will be borne out. [bi]Speak of this no more. To be crushed by the singular excruciates[\\bi]. (sigh) What's done is done. Enough.[i]Saya... If he- if Onkko- if I could have shown her how catalogues of possible futures found out from the moment[\\i] I could choose, could have chosen, to stay, none of them end, ended, well. [n] None, save one: this one. The one where I left. (sigh) [b]This future ends so well for her, for Konzu, for Cetus.[\\b] As evicerating a choice as it was, it was the only one I could live with. [n] Some day, I swear, this is- but- this was... this will be borne out. [bi]Speak of this no more. To be crushed by the singular excruciates[\\bi]. (sigh) What's done is done. Enough.");

	InputBox b = InputBox(eventListener, Panel(0, 0, 500, 40, 5, SDL_Color{ 200,50,50 }, SDL_Color{ 150,25,25 }), resources->GetFontPack("SSP"), 5, 5);

	ProgressBarElement p = ProgressBarElement(Panel(0, 0, 200, 200, 5, SDL_Color{ 200,50,50 }, SDL_Color{ 150,25,25 }), 100, SDL_Color{ 25, 25, 25 }, RIGHT);
	p.CurrentValue(76);

	//ButtonElement b = ButtonElement(eventListener, Panel(0, 0, 200, 100, 5, SDL_Color{ 200,50,50 }, SDL_Color{ 150,25,25 }), TextElement(resources->GetFontPack("SSP"), 34, false, 0, 0, 190, 90, SDL_Color{ 255,255,255,255 }), "Button", 5, 5);

	//SliderElement b = SliderElement(eventListener, 5, 30, Panel(0, 0, 25, 400, 3, SDL_Color{ 200,50,50 }, SDL_Color{ 150,25,25 }), resources->GetTexture("DownArrow"), resources->GetTexture("UpArrow"));


	//std::ifstream myfile("test.json");
	//std::string text((std::istreambuf_iterator<char>(myfile)), (std::istreambuf_iterator<char>()));
	//
	//Json::CharReaderBuilder builder;
	//Json::CharReader * reader = builder.newCharReader();
 	//
	//Json::Value root;
	//std::string errors;
	//
	//bool parsingSuccessful = reader->parse(text.c_str(), text.c_str() + text.size(), &root, &errors);
	//delete reader;
	//
	//if (!parsingSuccessful)
	//{
	//	std::cout << text << std::endl;
	//	std::cout << errors << std::endl;
	//}
	//
	////for (Json::Value::const_iterator outer = root.begin(); outer != root.end(); outer++)
	////{
	////	std::cout << outer.key() << ": " << *outer << std::endl;
	////	for (Json::Value::const_iterator inner = (*outer).begin(); inner != (*outer).end(); inner++)
	////	{
	////		std::cout << inner.key() << ": " << *inner << std::endl;
	////	}
	////
	////}
	//std::cout << root["Data"]["Name"];
	//myfile.close();
	//
	//std::ofstream outFile("testo.json");
	//
	//Json::StreamWriterBuilder styledbuilder;
	//Json::StreamWriter * styledwriter = styledbuilder.newStreamWriter();
	//
	//Json::Value writeRoot;
	//writeRoot["Data"]["Name"] = "Gregory";
	//
	//styledwriter->write(writeRoot, &outFile);
	//outFile.close();

	std::ifstream file("data/config_data/Materials/Metals/iron.json");
	std::string text((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
	file.close();

	Json::CharReaderBuilder builder;
	Json::CharReader * reader = builder.newCharReader();

	Json::Value value;
	std::string errors;

	bool parsingSuccessful = reader->parse(text.c_str(), text.c_str() + text.size(), &value, &errors);
	delete reader;

	if (!parsingSuccessful)
	{
		std::cout << text << std::endl;
		std::cout << errors << std::endl;
	}
	
	//Element Grabber
	std::vector<Element> elementTemp;
	int noOfElements = value["elements"]["no_of_elements"].asInt();
	if (noOfElements <= 0)
	{
		elementTemp.push_back(ELEMENT_PHYSICAL);
	}
	else
	{
		for (int i = 0; i < noOfElements; i++)
		{
			std::string holder = value["elements"][std::to_string(i)].asString();
			if (holder == "PHYSICAL")
				elementTemp.push_back(ELEMENT_PHYSICAL);
			else if (holder == "EARTH")
				elementTemp.push_back(ELEMENT_EARTH);
			else if (holder == "AIR")
				elementTemp.push_back(ELEMENT_AIR);
			else if (holder == "FIRE")
				elementTemp.push_back(ELEMENT_EARTH);
			else if (holder == "WATER")
				elementTemp.push_back(ELEMENT_WATER);
			else if (holder == "LIGHT")
				elementTemp.push_back(ELEMENT_LIGHT);
			else if (holder == "DARK")
				elementTemp.push_back(ELEMENT_DARK);
			else
				elementTemp.push_back(ELEMENT_EXOTIC);
		}
	}
	
	//Damage Type
	DamType damageTemp = PHYSICAL_DAMAGE;
	if (value["damage_type"].asString() == "MAGIC")
	{
		damageTemp = MAGIC_DAMAGE;
	}
	else if (value["damage_type"].asString() == "SPLIT")
	{
		damageTemp = SPLIT_DAMAGE;
	}
	
	CraftMaterial metal
	(
		value["name"].asString(),
		value["description"].asString(),
		value["color"]["r"].asInt(),
		value["color"]["g"].asInt(),
		value["color"]["b"].asInt(),
		value["quality"].asDouble(),
		value["density"].asDouble(),
		value["conductivity"].asDouble(),
		elementTemp,
		damageTemp,
		value["flammability"].asInt(),
		value["temperature_reduction"].asInt(),
		value["scaling"]["strength"].asDouble(),
		value["scaling"]["dexterity"].asDouble(),
		value["scaling"]["endurance"].asDouble(),
		value["scaling"]["intelligence"].asDouble(),
		value["scaling"]["agility"].asDouble(),
		value["scaling"]["luck"].asDouble(),
		value["mod"]["strength"].asInt(),
		value["mod"]["dexterity"].asInt(),
		value["mod"]["endurance"].asInt(),
		value["mod"]["intelligence"].asInt(),
		value["mod"]["agility"].asInt(),
		value["mod"]["luck"].asInt(),
		value["mod"]["potion_effectiveness"].asDouble(),
		value["mod"]["health"].asDouble(),
		value["mod"]["stamnina"].asDouble(),
		value["mod"]["arousal"].asDouble(),
		value["mod"]["willpower"].asDouble(),
		value["status_affliction"].asString()
	);

	t.SetString(metal.Name() + " : " + metal.Description());

	while (running)
	{
		t.Update();
		inputHandler.InputCheck();
		SDL_SetRenderDrawColor(gameRenderer, 0, 0, 0, 0);
		SDL_RenderClear(gameRenderer);
		//Draw Code Here
		t.Render(*gameRenderer);
		//
		SDL_RenderPresent(gameRenderer);
	}
	return 0;
}