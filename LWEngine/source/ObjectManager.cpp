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
	

	path = filelocation + "/Objects/Weapons/";
	for (auto & p : fs::directory_iterator(path))
	{
		Weapon holder = LoadWeapon(p);
		switch (holder.Type())
		{
		case SWORD:
			m_sword.insert(std::make_pair(holder.Name(), holder));
			m_swordList.push_back(holder.Name());
			break;
		case SPEAR:
			m_sword.insert(std::make_pair(holder.Name(), holder));
			m_swordList.push_back(holder.Name());
			break;
		case HAMMER:
			m_sword.insert(std::make_pair(holder.Name(), holder));
			m_swordList.push_back(holder.Name());
			break;
		case BOW:
			m_sword.insert(std::make_pair(holder.Name(), holder));
			m_swordList.push_back(holder.Name());
			break;
		case CROSSBOW:
			m_sword.insert(std::make_pair(holder.Name(), holder));
			m_swordList.push_back(holder.Name());
			break;
		case GUN:
			m_sword.insert(std::make_pair(holder.Name(), holder));
			m_swordList.push_back(holder.Name());
			break;
		case STAFF:
			m_sword.insert(std::make_pair(holder.Name(), holder));
			m_swordList.push_back(holder.Name());
			break;
		case FIST:
			m_sword.insert(std::make_pair(holder.Name(), holder));
			m_swordList.push_back(holder.Name());
			break;
		default:
			break;
		}
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
					elementTemp.push_back(ELEMENT_FIRE);
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

		CraftMaterial material
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
			value["damage_physical"].asDouble(),
			value["damage_magic"].asDouble(),
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
		return material;
	}
}
Weapon ObjectManager::LoadWeapon(const fs::directory_entry loc)
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
		//Damage Type
		WeaponType wepType = SWORD;
		if (value["type"].asString() == "SPEAR")
		{
			wepType = SPEAR;
		}
		else if (value["type"].asString() == "AXE")
		{
			wepType = AXE;
		}
		else if (value["type"].asString() == "HAMMER")
		{
			wepType = HAMMER;
		}
		else if (value["type"].asString() == "BOW")
		{
			wepType = BOW;
		}
		else if (value["type"].asString() == "CROSSBOW")
		{
			wepType = CROSSBOW;
		}
		else if (value["type"].asString() == "GUN")
		{
			wepType = GUN;
		}
		else if (value["type"].asString() == "WHIP")
		{
			wepType = WHIP;
		}
		else if (value["type"].asString() == "STAFF")
		{
			wepType = STAFF;
		}
		else if (value["type"].asString() == "FIST")
		{
			wepType = FIST;
		}

		Weapon wep
		(
			value["name"].asString(),
			value["description"].asString(),
			wepType,
			value["sharpness"].asDouble(),
			value["bluntness"].asDouble(),
			value["rating_multiplier"].asDouble(),
			value["durability_multiplier"].asDouble(),
			value["value_multiplier"].asDouble(),
			value["weight_multiplier"].asDouble(),
			value["secondary_material"].asBool(),
			value["lesser_material"].asBool(),
			value["number_of_hands"].asInt(),
			value["size"].asDouble()
		);
		return wep;
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
	return &m_gem[m_gemList.at(index)];
}

CraftMaterial * ObjectManager::Wood(std::string id)
{
	return &m_wood[id];
}
CraftMaterial * ObjectManager::Wood(int index)
{
	return &m_wood[m_woodList.at(index)];
}

CraftMaterial * ObjectManager::Cloth(std::string id)
{
	return &m_cloth[id];
}
CraftMaterial * ObjectManager::Cloth(int index)
{
	return &m_cloth[m_clothList.at(index)];
}

Weapon * ObjectManager::Sword(std::string id)
{
	return &m_sword[id];
}
Weapon * ObjectManager::Sword(int index)
{
	return &m_sword[m_swordList.at(index)];
}