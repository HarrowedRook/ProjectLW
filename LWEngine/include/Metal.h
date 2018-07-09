#ifndef _Metal_H
#define _Metal_H

#include "Material.h"

class Metal : public Material
{
public:
	Metal(std::string name, std::string description, int colorR, int colorG, int colorB, float quality, float density, float conductivity, std::vector<Element> elements, DamType type, float strScaling, float dexScaling, float endScaling, float intScaling, float agiScaling, float lukScaling, int strMod, int dexMod, int endMod, int intMod, int agiMod, int lukMod, float potionMod, int healthMod, int staminaMod, int arousalMod, int willpowerMod, std::string statusAffliction)
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
		m_strScaling = strScaling;
		m_dexScaling = dexScaling;
		m_endScaling = endScaling;
		m_intScaling = intScaling;
		m_agiScaling = agiScaling;
		m_lukScaling = lukScaling;
		m_strMod = strMod;
		m_dexMod = dexMod;
		m_endMod = endMod;
		m_intMod = intMod;
		m_agiMod = agiMod;
		m_lukMod = lukMod;
		m_potionMod = potionMod;
		m_healthMod = healthMod;
		m_staminaMod = staminaMod;
		m_arousalMod = arousalMod;
		m_willpowerMod = willpowerMod;
		m_statusAffliction = statusAffliction;
	}
	~Metal() {};

	//std::string Name() { return m_name; };
	//std::string Description() { return m_description; };
	//
	//SDL_Color Color() { return SDL_Color{ m_colorR, m_colorG, m_colorB }; };
	//
	//float Quality() { return m_quality; };
	//float Desnity() { return m_density; };
	//float Conductivity() { return m_conductivity; };
					
	float StrengthScaling() { return m_strScaling; };
	float DexterityScaling() { return m_dexScaling; };
	float EnduranceScaling () { return m_endScaling; };
	float IntelligenceScaling() { return m_intScaling; };
	float AgilityScaling() { return m_agiScaling; };
	float LuckScaling() { return m_lukScaling; };

	float StrengthMod() { return m_strMod; };
	float DexterityMod() { return m_dexMod; };
	float EnduranceMod() { return m_endMod; };
	float IntelligenceMod() { return m_intMod; };
	float AgilityMod() { return m_agiMod; };
	float LuckMod() { return m_lukMod; };

	float PotionMod() { return m_potionMod; };

	int HealthMod() { return m_healthMod;};
	int StaminaMod() { return m_staminaMod;};
	int ArousalMod() { return m_arousalMod; };
	int willpowerMod() {return m_willpowerMod;};

	//std::string StatusAffliction() { return m_statusAffliction; };

private:

	//Weapon Scaling
	float m_strScaling;
	float m_dexScaling;
	float m_endScaling;
	float m_intScaling;
	float m_agiScaling;
	float m_lukScaling;

	//Extended Modifiers
	int m_strMod;
	int m_dexMod;
	int m_endMod;
	int m_intMod;
	int m_agiMod;
	int m_lukMod;

	float m_potionMod;

	int m_healthMod;
	int m_staminaMod;
	int m_arousalMod;
	int m_willpowerMod;
};
#endif
