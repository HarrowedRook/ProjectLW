#ifndef _WORLDMATERIAL_H
#define _WORLDMATERIAL_H

#include "Material.h"

class WorldMaterial : public Material
{
	WorldMaterial(std::string name, std::string description, int colorR, int colorG, int colorB, float quality, float density, float conductivity, std::vector<Element> elements, DamType type, std::string statusAffliction)
	{
		m_name = name;
		m_description = description;
		m_colorR = colorR;
		m_colorG = colorG;
		m_colorB = colorB;
		m_quality = quality;
		m_density = density;
		m_conductivity = conductivity;
		m_elements = elements;
		m_damageType = type;
		m_statusAffliction = statusAffliction;
	};
	~WorldMaterial() {};
};
#endif