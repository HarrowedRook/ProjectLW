#include "ObjectManager.h"



ObjectManager::ObjectManager(std::string filelocation)
{
	std::string path;
	path = filelocation + "/Materials/Metals/";
	for (auto & p : fs::directory_iterator(path))
	{
		CraftMaterial holder = LoadCraftMaterial(p);
		m_metal.insert(std::make_pair(holder.Name(), holder));
		m_metalList.push_back(holder.Name());
	}
	path = filelocation + "/Materials/Gems/";
	for (auto & p : fs::directory_iterator(path))
	{
		CraftMaterial holder = LoadCraftMaterial(p);
		m_gem.insert(std::make_pair(holder.Name(), holder));
		m_gemList.push_back(holder.Name());
	}
	path = filelocation + "/Materials/Cloths/";
	for (auto & p : fs::directory_iterator(path))
	{
		CraftMaterial holder = LoadCraftMaterial(p);
		m_cloth.insert(std::make_pair(holder.Name(), holder));
		m_clothList.push_back(holder.Name());
	}
	path = filelocation + "/Materials/Woods/";
	for (auto & p : fs::directory_iterator(path))
	{
		CraftMaterial holder = LoadCraftMaterial(p);
		m_wood.insert(std::make_pair(holder.Name(), holder));
		m_woodList.push_back(holder.Name());
	}
}

CraftMaterial ObjectManager::LoadCraftMaterial(const fs::directory_entry loc)
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
		std::vector<Element> elementTemp;
		int noOfElements = value["elements"]["no_of_elements"].asInt();
		if (noOfElements <= 0)
		{
			elementTemp.push_back(ELEMENT_PHYSICAL);
		}
		else
		{
			for (int i = 1; i < noOfElements + 1; i++)
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
		return metal;
	}
}
CraftMaterial * ObjectManager::Metal(std::string id)
{
	return &m_metal[id];
}
CraftMaterial * ObjectManager::Metal(int index)
{
	return &m_metal[m_metalList.at(index)];
}

CraftMaterial * ObjectManager::Gem(std::string id)
{
	return &m_gem[id];
}
CraftMaterial * ObjectManager::Gem(int index)
{
	return &m_metal[m_gemList.at(index)];
}

CraftMaterial * ObjectManager::Wood(std::string id)
{
	return &m_wood[id];
}
CraftMaterial * ObjectManager::Wood(int index)
{
	return &m_metal[m_woodList.at(index)];
}

CraftMaterial * ObjectManager::Cloth(std::string id)
{
	return &m_cloth[id];
}
CraftMaterial * ObjectManager::Cloth(int index)
{
	return &m_metal[m_clothList.at(index)];
}