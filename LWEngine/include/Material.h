#ifndef _MATERIAL_H
#define _MATERIAL_H

#include "stdafx.h"

class Material
{
public:
	std::string Name() { return m_name; };
	std::string Description() { return m_description; };

	SDL_Color Color() { return SDL_Color{ m_colorR, m_colorG, m_colorB }; };

	float Quality() { return m_quality; };
	float Density() { return m_density; };
	float Conductivity() { return m_conductivity; };

	std::vector<Element> Elements() { return m_elements; };
	float PhysicalDamage() { return m_physical; };
	float MagicalDamage() { return m_magic; };

	std::string StatusAffliction() { return m_statusAffliction; };

protected:
	std::string m_name;
	std::string m_description;

	Uint8 m_colorR, m_colorG, m_colorB;

	float m_quality;//Damage/Armor/Potency 
	float m_density;//Weight
	float m_conductivity;//Level of enchants

	std::vector<Element> m_elements;
	float m_physical;
	float m_magic;

	std::string m_statusAffliction;
};
#endif