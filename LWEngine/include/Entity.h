#ifndef _GRAPHIC_H
#define _GRAPHIC_H

#include "stdafx.h"
#include "Status.h"

class Entity
{
public:
	Entity();
	~Entity();
protected:

	//Basic Info
	std::string m_name;
	std::string m_race;

	//Resources
	Resources m_resources;

	//Primary Stats
	PrimaryStats m_stats;
	//Stat Mods
	PrimaryStats m_statMods; //Stat mods
	PrimaryStats m_modifiedStats; //Modified Stats

	//Secondary Stats
	float m_carryCapacity;
	int m_morality;
	int m_faith;
	std::string m_god;

	//Body
	int m_size;
};
#endif