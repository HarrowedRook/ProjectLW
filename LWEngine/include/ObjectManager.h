#ifndef _OBJECTMANAGER_H
#define _OBJECTMANAGER_H

#include "CraftMaterial.h"
#include "WorldMaterial.h"

#include "Weapon.h"
#include "Character.h"
#include "PlayerCharacter.h"
#include "Enchantment.h"
#include "Status.h"
#include <filesystem>

namespace fs = std::filesystem;

class ObjectManager
{
public:
	ObjectManager(std::string filelocation);
	~ObjectManager() {};

	CraftMaterial * Metal(std::string id);
	CraftMaterial * Metal(int index);
	int NumberOfMetals() { return m_metalList.size(); };
	CraftMaterial * Gem(std::string id);
	CraftMaterial * Gem(int index);
	int NumberOfGems() { return m_gemList.size(); };
	CraftMaterial * Wood(std::string id);
	CraftMaterial * Wood(int index);
	int NumberOfWood() { return m_woodList.size(); };
	CraftMaterial * Cloth(std::string id);
	CraftMaterial * Cloth(int index);
	int NumberOfCloths() { return m_clothList.size(); };

	PlayerCharacter * PC(std::string id);
	PlayerCharacter * PC(int index);

	Character * NPC(std::string id);
	Character * NPC(int index);

	Weapon * Sword(std::string id);
	Weapon * Sword(int index);
	int NumberOfSwords() { return m_swordList.size(); };


private:

	CraftMaterial LoadCraftMaterial(const fs::directory_entry loc);

	Weapon LoadWeapon(const fs::directory_entry loc);

	//Materials
	std::map<std::string, CraftMaterial> m_metal;
	std::vector<std::string> m_metalList;
	std::map<std::string, CraftMaterial> m_gem;
	std::vector<std::string> m_gemList;
	
	std::map<std::string, CraftMaterial> m_wood;
	std::vector<std::string> m_woodList;
	
	std::map<std::string, CraftMaterial> m_cloth;
	std::vector<std::string> m_clothList;
	
	std::map<std::string, WorldMaterial> m_stone;
	std::vector<std::string> m_stoneList;
	std::map<std::string, WorldMaterial> m_liquid;
	std::vector<std::string> m_liquidList;
	std::map<std::string, WorldMaterial> m_gas;
	std::vector<std::string> m_gasList;

	std::map<std::string, Enchantment> m_enchantment;
	std::vector<std::string> m_enchantmentList;
	std::map<std::string, Status> m_status;
	std::vector<std::string> m_statusList;

	std::map<std::string, Weapon> m_sword;
	std::vector<std::string> m_swordList;

	//Characters
	std::map<std::string, PlayerCharacter> m_PC;
	std::vector<std::string> m_PC_List;

	//std::map<std::string, Character> m_NPC;
	//std::vector<std::string> m_NPC_List;
};
#endif
