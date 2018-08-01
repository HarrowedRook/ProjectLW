#ifndef _EQUIPMENT_H
#define _EQUIPMENT_H

#include "BodyPart.h"
#include "Enchantment.h"

enum StatScaler{STRENGTH, DEXTERITY, ENDURANCE, INTELLIGENCE, AGILITY, LUCK};

class Equipment
{
public:
	int Rating() { return m_rating; };
	void Rating(float x) { m_rating = x; };
	int Durability() { return m_durability; }
	void Durability(int x) { m_durability = x; };
	int MaxDurability() { return m_maxDurability; }
	void MaxDurability(float x) { m_maxDurability = x; };
	float Size() { return m_size; }
	void Size(float x) { m_size = x; };

	int Value() { return m_value; };
	void Value(float x) { m_value = x; };

	float Weight() { return m_weight; };
	void Weight(float x) { m_weight = x; };

	bool Equipped() { return m_equipped; };
	void Equipped(bool x) { m_equipped = x; };

	CraftMaterial* PrimaryMaterial() { return m_primaryMaterial; };
	void PrimaryMaterial(CraftMaterial * x) { m_primaryMaterial = x; };
	CraftMaterial* SecondaryMaterial() { return m_secondaryMaterial; };
	void SecondaryMaterial(CraftMaterial * x) { m_secondaryMaterial = x; };
	CraftMaterial* LesserMaterial() { return m_lesserMaterial; };
	void LesserMaterial(CraftMaterial * x) { m_lesserMaterial = x; };

	std::vector<Enchantment*>* Enchantments() { return &m_enchantments; };
	void AddEnchantment(Enchantment * x) { m_enchantments.push_back(x); };
	void RemoveEnchantment(Enchantment * x) 
	{
		for (int i = 0; i < m_enchantments.size(); i++)
		{
			if (m_enchantments.at(i) == x)
			{
				m_enchantments.erase(m_enchantments.begin() + (i - 1));
			}
		}
	}

	std::string Name()
	{
		return Parser(m_name);
	}

	std::string Description()
	{
		return Parser(m_description);
	};

	std::vector<Element> Elements();

	void SecondaryMaterialOn(bool x) { m_secondaryMat = x; };
	bool SecondaryMaterialOn() { return m_secondaryMat; };

	void LesserMaterialOn(bool x) { m_lesserMat = x; };
	bool LesserMaterialOn() { return m_lesserMat; };

	PrimaryStats PrimaryStatModifications() { return m_statMods; };

	std::string Quality()
	{
		std::string holder = "none";
		switch (m_quality)
		{
		case 0:
			holder = "Poor";
			break;
		case 1:
			holder = "Average";
			break;
		case 2:
			holder = "Fine";
			break;
		case 3:
			holder = "Good";
			break;
		case 4:
			holder = "Exquisite";
			break;
		case 5:
			holder = "Masterworks";
			break;
		default:
			if (m_quality < 0)
			{
				holder = "Miserable";
			}
			else
			{
				holder = "Artifact";
			}
			break;
		}
		return holder;
	}


protected:

	void StatModCalculation();

	void CalculateBasicStats();

	float StatMod(StatScaler m);

	std::string Parser(std::string x);

	std::string m_name;
	std::string m_description;

	int m_quality;

	float m_rating;//Value for damage or armor
	int m_durability;
	int m_maxDurability;

	float m_size;//Meters

	float m_value;

	float m_weight;

	bool m_secondaryMat;
	bool m_lesserMat;

	bool m_equipped;

	PrimaryStats m_statMods;

	CraftMaterial *m_primaryMaterial, *m_secondaryMaterial, *m_lesserMaterial;
	std::vector<Enchantment*> m_enchantments;

	float Round(float x)
	{
		float value = (int)(x * 100 + .5);
		return (float)value / 100;
	};

	float m_originalrating;//Value for damage or armor
	float m_originalvalue;
	float m_originalweight;
	int   m_originalmaxDurability;

};
#endif