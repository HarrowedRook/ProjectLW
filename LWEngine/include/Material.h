#ifndef _Material_H
#define _Material_H

#include "stdafx.h"

enum DamType { PHYSICAL_DAMAGE, MAGIC_DAMAGE, SPLIT_DAMAGE};
enum Element { ELEMENT_PHYSICAL, ELEMENT_FIRE, ELEMENT_AIR, ELEMENT_EARTH, ELEMENT_WATER, ELEMENT_DARK, ELEMENT_LIGHT, ELEMENT_EXOTIC };

class Material
{
public:
	std::string Name() { return m_name; };
	std::string Description() { return m_description; };

	SDL_Color Color() { return SDL_Color{ m_colorR, m_colorG, m_colorB }; };

	float Quality() { return m_quality; };
	float Desnity() { return m_density; };
	float Conductivity() { return m_conductivity; };

	std::vector<Element> Elements() { return m_elements; };
	DamType DamageType() { return m_damageType; };

	std::string StatusAffliction() { return m_statusAffliction; };

protected:
	std::string m_name;
	std::string m_description;

	Uint8 m_colorR, m_colorG, m_colorB;

	float m_quality;//Damage/Armor/Potency 
	float m_density;//Weight
	float m_conductivity;//Level of enchants

	std::vector<Element> m_elements;
	DamType m_damageType;

	std::string m_statusAffliction;
};
#endif