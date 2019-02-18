#ifndef _MATERIAL_H
#define _MATERIAL_H

#include "stdafx.h"
#include "Effect.h"

enum MaterialLocation {LOC_SURFACE, LOC_SURFACE_WATER, LOC_UNDERGROUND, LOC_UNDERGROUND_WATER, LOC_ANYWHERE, LOC_VOID};
enum MaterialType {MATERIAL_STONE, MATERIAL_METAL, MATERIAL_GEM, MATERIAL_CLOTH, MATERIAL_WOOD, MATERIAL_GAS, MATERIAL_LIQUID};

class Material
{
public:
	Material()
	{
		m_name = "WIP";
		m_description = "WIP";
		m_type = MATERIAL_STONE;
		m_color = SDL_Color{0,0,0};
		m_potential = 1;
		m_absorption = 1;
		m_affinity = 1;
		m_density = 1;
		m_weight = 1;
		m_temperature_resistance = 0;
		m_rarity = 1;
		m_naturallyOccuring = false;
		m_element = ELEMENT_PHYSICAL;
		m_location = LOC_VOID;
	}
	Material(std::string name, std::string desc, MaterialType type, SDL_Color color, float potential, float absorption, float affinity, float density, float weight, float temp_Resistance, int rarity, bool naturallyOccuring, Element element, MaterialLocation location)
	{
		m_name = name;
		m_description = desc;
		m_type = type;
		m_color = color;
		m_potential = potential;
		m_absorption = absorption;
		m_affinity = affinity;
		m_density = density;
		m_weight = weight;
		m_temperature_resistance = temp_Resistance;
		m_rarity = rarity;
		m_naturallyOccuring = naturallyOccuring;
		m_element = element;
		m_location = location;
	};
	~Material() {};

	std::string Name() { return m_name; };
	std::string Description() { return m_description; };
	SDL_Color Color() { return m_color; };
	
	int Rarity() { return m_rarity; };

	float Potential() { return m_potential; };
	float Absorption() { return m_absorption; };
	float Affinity() { return m_affinity; };
	float Density() { return m_density; };
	float Weight() { return m_weight; };
	float Temperature_Resistance() { return m_temperature_resistance; };

	Element GetElement() { return m_element; };
	MaterialLocation Location() { return m_location; };

	MaterialType Type() { return m_type; };
	
	void AddEffect(Effect * effect)
	{
		m_effects.push_back(effect);
	};
	Effect * GetEffect(int index) 
	{ 
		return m_effects.at(index); 
	};
	int NumberOfEffects()
	{
		return m_effects.size();
	};

private:
	MaterialType m_type;

	bool m_naturallyOccuring;

	SDL_Color m_color;
	Element m_element;
	MaterialLocation m_location;

	float m_potential;
	float m_absorption;
	float m_affinity;
	float m_density;
	float m_weight;

	float m_temperature_resistance;

	int m_rarity;

	std::string m_description;
	std::string m_name;

	std::vector<Effect*> m_effects;
};
#endif