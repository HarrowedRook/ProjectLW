#ifndef _CRAFTMATERIAL_H
#define _CRAFTMATERIAL_H

#include "Material.h"

class CraftMaterial : public Material
{
public:
	CraftMaterial(std::string name, std::string description, int colorR, int colorG, int colorB, float quality, float density, float conductivity, std::vector<Element> elements, DamType type, int flammability, int tempReduct, float strScaling, float dexScaling, float endScaling, float intScaling, float agiScaling, float lukScaling, int strMod, int dexMod, int endMod, int intMod, int agiMod, int lukMod, float potionMod, int healthMod, int staminaMod, int arousalMod, int willpowerMod, std::string statusAffliction)
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
		m_flammability = flammability;
		m_temperatureReduction = tempReduct;
		m_strScaling = strScaling;
		m_dexScaling = dexScaling;
		m_endScaling = endScaling;
		m_intScaling = intScaling;
		m_agiScaling = agiScaling;
		m_lukScaling = lukScaling;
		m_statMod.strength = strMod;
		m_statMod.dexterity = dexMod;
		m_statMod.endurance = endMod;
		m_statMod.intelligence = intMod;
		m_statMod.agility = agiMod;
		m_statMod.luck = lukMod;
		m_statMod.potionEffectiveness = potionMod;
		m_statMod.healthRegeneration = healthMod;
		m_statMod.staminaRegeneration = staminaMod;
		m_statMod.arousalRegeneration = arousalMod;
		m_statMod.willpowerRegeneration = willpowerMod;
		m_statusAffliction = statusAffliction;
	}
	CraftMaterial() {};

	~CraftMaterial() {};

	int Flammability() { return m_flammability; };
	int Temperature() { return m_temperatureReduction; };
					
	float StrengthScaling() { return m_strScaling; };
	float DexterityScaling() { return m_dexScaling; };
	float EnduranceScaling () { return m_endScaling; };
	float IntelligenceScaling() { return m_intScaling; };
	float AgilityScaling() { return m_agiScaling; };
	float LuckScaling() { return m_lukScaling; };

	float StrengthMod() { return m_statMod.strength; };
	float DexterityMod() { return m_statMod.dexterity; };
	float EnduranceMod() { return m_statMod.endurance; };
	float IntelligenceMod() { return m_statMod.intelligence; };
	float AgilityMod() { return m_statMod.agility; };
	float LuckMod() { return m_statMod.luck; };

	float PotionMod() { return m_statMod.potionEffectiveness; };

	int HealthMod() { return m_statMod.healthRegeneration; };
	int StaminaMod() { return  m_statMod.staminaRegeneration; };
	int ArousalMod() { return  m_statMod.arousalRegeneration; };
	int willpowerMod() {return m_statMod.willpowerRegeneration; };

private:

	int m_flammability;
	int m_temperatureReduction;

	//Weapon/Armor Scaling
	float m_strScaling;
	float m_dexScaling;
	float m_endScaling;
	float m_intScaling;
	float m_agiScaling;
	float m_lukScaling;

	//Extended Modifiers
	PrimaryStats m_statMod;
};
#endif
