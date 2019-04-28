/*#include "ObjectManager.h"



ObjectManager::ObjectManager(std::string filelocation)
{
	std::string path;
	path = filelocation + "/Materials/Metals/";
	for (auto & p : fs::directory_iterator(path))
	{
		Material holder = LoadMaterial(p);
		m_metal.insert(std::make_pair(holder.Name(), holder));
		m_metalList.push_back(holder.Name());
	}
}

Material ObjectManager::LoadMaterial(const fs::directory_entry loc)
{
	Json::CharReaderBuilder builder;
	std::ifstream file(loc);
	std::string text((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
	file.close();

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
	else
	{
		//Element Grabber
		Element elementTemp;

		std::string holder = value["element"].asString();
		if (holder == "AIR")
			elementTemp = ELEMENT_AIR;
		else if (holder == "FIRE")
			elementTemp = ELEMENT_FIRE;
		else if (holder == "WATER")
			elementTemp = ELEMENT_WATER;
		else if (holder == "LIGHT")
			elementTemp = ELEMENT_LIGHT;
		else
			elementTemp = ELEMENT_PHYSICAL;
		//SURFACE, SURFACE_WATER, UNDERGROUND, UNDERGROUND_WATER, ANYWHERE, VOID
		MaterialLocation locationTemp;
		holder = value["location"].asString();
		if (holder == "SURFACE")
			locationTemp = LOC_SURFACE;
		else if (holder == "SURFACE_WATER")
			locationTemp = LOC_SURFACE_WATER;
		else if (holder == "UNDERGROUND")
			locationTemp = LOC_UNDERGROUND;
		else if (holder == "UNDERGROUND_WATER")
			locationTemp = LOC_UNDERGROUND_WATER;
		else if (holder == "ANYWHERE")
			locationTemp = LOC_ANYWHERE;
		else
			locationTemp = LOC_VOID;
		Uint8 r = Uint8(value["color"]["r"].asInt());
		Uint8 g = Uint8(value["color"]["g"].asInt());
		Uint8 b = Uint8(value["color"]["b"].asInt());
		//std::string name, std::string desc, MaterialType type, SDL_Color color, float potential, float absorption, 
		//float affinity, float density, float weight, float temp_Resistance, int rarity, bool naturallyOccuring, Element element, MaterialLocation location
		//	SDL_Color
		Material material
		(
			value["name"].asString(),
			value["description"].asString(),
			MATERIAL_METAL,
			SDL_Color{ r, g, b },
			value["potential"].asDouble(),
			value["absorption"].asDouble(),
			value["affinity"].asDouble(),
			value["density"].asDouble(),
			value["weight"].asDouble(),
			value["temperature_reduction"].asDouble(),
			value["rarity"].asDouble(),
			value["naturally_occuring"].asBool(),
			elementTemp,
			locationTemp
		);
		return material;
	}
}

Material * ObjectManager::Metal(std::string id)
{
	return &m_metal[id];
}
Material * ObjectManager::Metal(int x)
{
	return &m_metal[m_metalList.at(x)];
}*/