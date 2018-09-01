#define SDL_MAIN_HANDLED

#include "stdafx.h"
#include "ResourceManager.h"
#include "TextBox.h"
#include "SliderElement.h"
#include "InputBox.h"
#include "ProgressBarElement.h"
#include "Equipment.h"

#include "ObjectManager.h"
#include "Character.h"
#include "CraftMaterial.h"
#include "WorldMaterial.h"

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
	//t.SetString("[i]Saya... If he- if Onkko- if I could have shown her how catalogues of possible futures found out from the moment[\\i] I could choose, could have chosen, to stay, none of them end, ended, well. [n] None, save one: this one. The one where I left. (sigh) [b]This future ends so well for her, for Konzu, for Cetus.[\\b] As evicerating a choice as it was, it was the only one I could live with. [n] Some day, I swear, this is- but- this was... this will be borne out. [bi]Speak of this no more. To be crushed by the singular excruciates[\\bi]. (sigh) What's done is done. Enough.[i]Saya... If he- if Onkko- if I could have shown her how catalogues of possible futures found out from the moment[\\i] I could choose, could have chosen, to stay, none of them end, ended, well. [n] None, save one: this one. The one where I left. (sigh) [b]This future ends so well for her, for Konzu, for Cetus.[\\b] As evicerating a choice as it was, it was the only one I could live with. [n] Some day, I swear, this is- but- this was... this will be borne out. [bi]Speak of this no more. To be crushed by the singular excruciates[\\bi]. (sigh) What's done is done. Enough.[i]Saya... If he- if Onkko- if I could have shown her how catalogues of possible futures found out from the moment[\\i] I could choose, could have chosen, to stay, none of them end, ended, well. [n] None, save one: this one. The one where I left. (sigh) [b]This future ends so well for her, for Konzu, for Cetus.[\\b] As evicerating a choice as it was, it was the only one I could live with. [n] Some day, I swear, this is- but- this was... this will be borne out. [bi]Speak of this no more. To be crushed by the singular excruciates[\\bi]. (sigh) What's done is done. Enough.");

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

	ObjectManager m("data/config_data");

	//

	srand(time(NULL));

	//begin weapon test

	//CraftMaterial * matOne;
	//CraftMaterial * matTwo;
	//CraftMaterial * matThree;

	//int rando = rand() % 3;
	//if (rando == 0)
	//{
	//	matOne = m.Metal(rand() % m.NumberOfMetals());
	//}
	//else if (rando == 1)
	//{
	//	matOne = m.Wood(rand() % m.NumberOfWood());
	//}
	//else
	//{
	//	matOne = m.Gem(rand() % m.NumberOfGems());
	//}

	//rando = rand() % 3;
	//if (rando == 0)
	//{
	//	matTwo = m.Metal(rand() % m.NumberOfMetals());
	//}
	//else if (rando == 1)
	//{
	//	matTwo = m.Wood(rand() % m.NumberOfWood());
	//}
	//else
	//{
	//	matTwo = m.Gem(rand() % m.NumberOfGems());
	//}

	//matThree = m.Gem(rand() % m.NumberOfGems());

	//Weapon * swordHolder = m.Sword(rand() % m.NumberOfSwords());

	//int rating = swordHolder->Rating();

	//std::vector<Enchantment*> x;

	//Weapon sword(
	//	swordHolder->Name(),
	//	swordHolder->Description(),
	//	rand() % 7,
	//	swordHolder->Type(),
	//	swordHolder->Sharpness(),
	//	swordHolder->Bluntness(),
	//	swordHolder->Rating(),
	//	swordHolder->Durability(),
	//	swordHolder->Value(),
	//	swordHolder->Weight(),
	//	matOne,
	//	matTwo,
	//	matThree,
	//	swordHolder->SecondaryMaterialOn(),
	//	swordHolder->LesserMaterialOn(),
	//	x,
	//	swordHolder->NumberOfHands(),
	//	swordHolder->Size()
	//);

	//std::string weight;

	//std::stringstream stream;
	//stream << std::fixed << std::setprecision(2) << sword.Weight();
	//weight = stream.str();
	//stream.str("");

	//std::string output = sword.Name() + ": " + sword.Description() + "[n]Damage: " + std::to_string(sword.Rating()) + "[n]Weight: " + weight + " kg[n]Durability: " + std::to_string(sword.Durability()) + "[n]Value: " + std::to_string(sword.Value()) + " Gold" + "[n]Quality: " + sword.Quality();

	//stream << std::fixed << std::setprecision(2) << sword.Sharpness();
	//output += "[n]Sharp/Blunt/Magic: " + stream.str();
	//stream.str("");
	//stream << std::fixed << std::setprecision(2) << sword.Bluntness();
	//output += "/" + stream.str();
	//stream.str("");
	//stream << std::fixed << std::setprecision(2) << sword.Magic();
	//output += "/" + stream.str();
	//stream.str("");
	//
	//output += "[n]Elements: ";

	//Element element = sword.Elements().at(0);
	//switch (element)
	//{
	//case ELEMENT_PHYSICAL:
	//	output += "Physical";
	//	break;
	//case ELEMENT_FIRE:
	//	output += "Fire";
	//	break;
	//case ELEMENT_AIR:
	//	output += "Air";
	//	break;
	//case ELEMENT_EARTH:
	//	output += "Earth";
	//	break;
	//case ELEMENT_WATER:
	//	output += "Water";
	//	break;
	//case ELEMENT_DARK:
	//	output += "Dark";
	//	break;
	//case ELEMENT_LIGHT:
	//	output += "Light";
	//	break;
	//case ELEMENT_EXOTIC:
	//	output += "Exotic";
	//	break;
	//default:
	//	break;
	//}

	//for (int i = 1; i < sword.Elements().size(); i++)
	//{
	//	element = sword.Elements().at(i);
	//	switch (element)
	//	{
	//	case ELEMENT_PHYSICAL:
	//		output += ", Physical";
	//		break;
	//	case ELEMENT_FIRE:
	//		output += ", Fire";
	//		break;
	//	case ELEMENT_AIR:
	//		output += ", Air";
	//		break;
	//	case ELEMENT_EARTH:
	//		output += ", Earth";
	//		break;
	//	case ELEMENT_WATER:
	//		output += ", Water";
	//		break;
	//	case ELEMENT_DARK:
	//		output += ", Dark";
	//		break;
	//	case ELEMENT_LIGHT:
	//		output += ", Light";
	//		break;
	//	case ELEMENT_EXOTIC:
	//		output += ", Exotic";
	//		break;
	//	default:
	//		break;
	//	}
	//}

	//t.SetString(output);

	//PrimaryStats jingo{ 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
	//sword.DamageCalculation(jingo);



	//////////////End Weapon test

	//////////////Begin Character test

//	std::string name, std::string descriptor, std::vector<BodyPart> bodyParts, Size size, Gender gender, PrimaryRace primaryRace, Weight weight)

	PlayerCharacter * characterHolder = new PlayerCharacter;


	Gender* pGender = &characterHolder->m_gender;

	int rando = rand() % 3;
	if (rando == 0)
	{
		*pGender = cgAMBIGUOUS;
	}
	else if (rando == 1)
	{
		*pGender = cgMASCULINE;
	}
	else
	{
		*pGender = cgFEMININE;
	}

	PrimaryRace* pRace = &characterHolder->m_race;

	rando = rand() % 4;
	if (rando == 0)
	{
		*pRace = crHUMAN;
	}
	else if (rando == 1)
	{
		*pRace = crSHARK;
	}
	else if (rando == 2)
	{
		*pRace = crRABBIT;
	}
	else
	{
		*pRace = crDEMON;
	}


	std::vector<BodyPart*> bodyParts = characterHolder->BodyParts();

	//std::vector<Enchantment*> x;

	//PlayerCharacter Jimmy();
	

	std::string weight;

	/*std::stringstream stream;
	stream
	weight = stream.str();
	stream.str("");
	
	
*/
	std::string output = characterHolder->m_characterName + ": " + characterHolder->m_description + "[n]Desc: " + std::to_string(characterHolder->m_gender) + "[n]race: " + std::to_string(characterHolder->m_race) + "[n]size: " + std::to_string(characterHolder->m_size) + "[n]weight: " + std::to_string(characterHolder->m_weight);

	

	t.SetString(output);



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