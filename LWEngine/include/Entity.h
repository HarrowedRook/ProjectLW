#ifndef _GRAPHIC_H
#define _GRAPHIC_H

#include "stdafx.h"

class Entity
{
public:
	Entity();
	~Entity();
protected:

	//Basic Info
	std::string m_name;
	std::string m_race;

	//Seen Stats
	int m_health;
	int m_maxHealth;
	int m_stamina;
	int m_staminaSoftcap;
	int m_maxStamina;
	int m_arousal;
	int m_maxArousal;

	//Primary Stats
	int m_strength; //Stamina used per melee attack + carry capacity
	int m_dexterity; //Hit Rate
	int m_endurance; //Max Health + Stamina
	int m_intelligence; //Stamina used per spell (Elemental)
	int m_agility; //Turn order
	int m_luck; //Crit

	//Secondary Stats
	int m_morality;
	int m_faith;
	std::string m_god;
	int m_carryCapacity;

	//Unseen Stats
	int m_willpower; //Willingness to comply at any moment.
	int m_maxWillpower; //Max willpower.

	//Body
	int m_size;

	//Extended Stats
	int m_strMod;
	int m_dexMod;
	int m_endMod;
	int m_intMod;
	int m_agiMod;
	int m_lukMod;

	float m_potionEffectiveness;

	int m_healthRegeneration;
	int m_staminaRegeneration;
	int m_arousalRegeneration;
	int m_willpowerRegeneration;
};
#endif