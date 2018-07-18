#ifndef _EQUIPMENT_H
#define _EQUIPMENT_H

#include "BodyPart.h"
#include "Enchantment.h"

class Equipment
{
public:
	int Rating() { return m_value; };
	void Rating(int x) { m_rating = x; };
	int Durability() { return m_durability; }
	void Durability(int x) { m_durability = x; };
	int MaxDurability() { return m_maxDurability; }
	void MaxDurability(int x) { m_maxDurability = x; };

	int Value() { return m_value; };
	void Value(int x) { m_value = x; };

	int Weight() { return m_weight; };
	void Weight(int x) { m_weight = x; };

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

	std::string Description()
	{
		std::string descCopy = m_description;
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

protected:
	std::string m_name;
	std::string m_description;

	int m_rating;//Value for damage or armor
	int m_durability;
	int m_maxDurability;

	int m_value;

	float m_weight;

	CraftMaterial *m_primaryMaterial, *m_secondaryMaterial, *m_lesserMaterial;
	std::vector<Enchantment*> m_enchantments;
};
#endif