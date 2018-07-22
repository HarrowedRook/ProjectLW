#ifndef _EQUIPMENT_H
#define _EQUIPMENT_H

#include "BodyPart.h"
#include "Enchantment.h"

enum StatModifier{STRENGTH, DEXTERITY, ENDURANCE, INTELLIGENCE, AGILITY, LUCK};

class Equipment
{
public:
	float Rating() { return m_value; };
	void Rating(float x) { m_rating = x; };
	int Durability() { return m_durability; }
	void Durability(int x) { m_durability = x; };
	float MaxDurability() { return m_maxDurability; }
	void MaxDurability(float x) { m_maxDurability = x; };

	float Value() { return m_value; };
	void Value(float x) { m_value = x; };

	float Weight() { return m_weight; };
	void Weight(float x) { m_weight = x; };

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
		std::string name = m_name;
		if (m_primaryMaterial != NULL)
		{
			bool proceed = false;
			while (!proceed)
			{
				proceed = true;
				int holder = name.find("<pm>");
				if (holder > -1)
				{
					proceed = false;
					name.replace(holder, 4, m_primaryMaterial->Name());
				}
			}
			proceed = false;
			while (!proceed)
			{
				proceed = true;
				int holder = name.find("<sm>");
				if (holder > -1)
				{
					proceed = false;
					name.replace(holder, 4, m_secondaryMaterial->Name());
				}
			}
			proceed = false;
			while (!proceed)
			{
				proceed = true;
				int holder = name.find("<lm>");
				if (holder > -1)
				{
					proceed = false;
					name.replace(holder, 4, m_lesserMaterial->Name());
				}
			}

		}
		return name;
	}

	std::string Description()
	{
		std::string descCopy = m_description;
		if (m_primaryMaterial != NULL)
		{
			bool proceed = false;
			while (!proceed)
			{
				proceed = true;
				int holder = descCopy.find("<pm>");
				if (holder > -1)
				{
					proceed = false;
					descCopy.replace(holder, 4, m_primaryMaterial->Name());
				}
			}
			proceed = false;
			while (!proceed)
			{
				proceed = true;
				int holder = descCopy.find("<sm>");
				if (holder > -1)
				{
					proceed = false;
					descCopy.replace(holder, 4, m_secondaryMaterial->Name());
				}
			}
			proceed = false;
			while (!proceed)
			{
				proceed = true;
				int holder = descCopy.find("<lm>");
				if (holder > -1)
				{
					proceed = false;
					descCopy.replace(holder, 4, m_lesserMaterial->Name());
				}
			}
		}

		return descCopy;
	};

	std::vector<Element> Elements()
	{
		std::vector<Element> holder;
		for (int i = 0; i < m_primaryMaterial->Elements().size(); i++)
		{
			holder.push_back(m_primaryMaterial->Elements().at(i));
		}
		for (int i = 0; i < m_secondaryMaterial->Elements().size(); i++)
		{
			holder.push_back(m_secondaryMaterial->Elements().at(i));
		}
		for (int i = 0; i < m_lesserMaterial->Elements().size(); i++)
		{
			holder.push_back(m_lesserMaterial->Elements().at(i));
		}
		return holder;
	}

	void SecondaryMaterialOn(bool x) { m_secondaryMat = x; };
	bool SecondaryMaterialOn() { return m_secondaryMat; };

	void LesserMaterialOn(bool x) { m_lesserMat = x; };
	bool LesserMaterialOn() { return m_lesserMat; };

protected:

	float StatMod(StatModifier m)
	{
		float holder = 0;
		int divider = 0;
		switch (m)
		{
		case STRENGTH:
			divider = 1;
			holder = m_primaryMaterial->StrengthMod();
			if (m_secondaryMat) { holder += m_secondaryMaterial->StrengthMod(); divider++; }
			if (m_lesserMat) { holder += m_lesserMaterial->StrengthMod(); divider++; }
			holder = holder / divider;
			break;
		case DEXTERITY:
			divider = 1;
			holder = m_primaryMaterial->DexterityMod();
			if (m_secondaryMat) { holder += m_secondaryMaterial->DexterityMod(); divider++; }
			if (m_lesserMat) { holder += m_lesserMaterial->DexterityMod(); divider++; }
			holder = holder / divider;
			break;
		case ENDURANCE:
			divider = 1;
			holder = m_primaryMaterial->EnduranceMod();
			if (m_secondaryMat) { holder += m_secondaryMaterial->EnduranceMod(); divider++; }
			if (m_lesserMat) { holder += m_lesserMaterial->EnduranceMod(); divider++; }
			holder = holder / divider;
			break;
		case INTELLIGENCE:
			divider = 1;
			holder = m_primaryMaterial->IntelligenceMod();
			if (m_secondaryMat) { holder += m_secondaryMaterial->IntelligenceMod(); divider++; }
			if (m_lesserMat) { holder += m_lesserMaterial->IntelligenceMod(); divider++; }
			holder = holder / divider;
			break;
		case AGILITY:
			divider = 1;
			holder = m_primaryMaterial->AgilityMod();
			if (m_secondaryMat) { holder += m_secondaryMaterial->AgilityMod(); divider++; }
			if (m_lesserMat) { holder += m_lesserMaterial->AgilityMod(); divider++; }
			holder = holder / divider;
			break;
		case LUCK:
			divider = 1;
			holder = m_primaryMaterial->LuckMod();
			if (m_secondaryMat) { holder += m_secondaryMaterial->LuckMod(); divider++; }
			if (m_lesserMat) { holder += m_lesserMaterial->LuckMod(); divider++; }
			holder = holder / divider;
			break;
		default:
			break;
		}
		holder = roundf(holder * 100) / 100;
		return holder;
	}

	std::string m_name;
	std::string m_description;

	float m_rating;//Value for damage or armor
	int m_durability;
	int m_maxDurability;

	float m_value;

	float m_weight;

	bool m_secondaryMat;
	bool m_lesserMat;

	CraftMaterial *m_primaryMaterial, *m_secondaryMaterial, *m_lesserMaterial;
	std::vector<Enchantment*> m_enchantments;
};
#endif