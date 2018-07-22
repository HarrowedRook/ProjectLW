#ifndef _WORLDMATERIAL_H
#define _WORLDMATERIAL_H

#include "Material.h"

class WorldMaterial : public Material
{
public:
	WorldMaterial(std::string name, std::string description, int colorR, int colorG, int colorB, float quality, float density, float conductivity, std::vector<Element> elements, float physical, float magic, std::string statusAffliction)
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
		m_physical = physical;
		m_magic = magic;
		m_statusAffliction = statusAffliction;
	};
	WorldMaterial() {};
	~WorldMaterial() {};
};
#endif