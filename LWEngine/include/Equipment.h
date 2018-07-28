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
		if (m_secondaryMat)
		{
			for (int i = 0; i < m_secondaryMaterial->Elements().size(); i++)
			{
				bool progress = true;
				for (int j = 0; j < holder.size() && progress; j++)
				{
					if (m_secondaryMaterial->Elements().at(i) == holder.at(j))
					{
						progress = false;
					}
				}
				if (progress)
				{
					holder.push_back(m_secondaryMaterial->Elements().at(i));
				}
			}
		}
		if (m_lesserMat)
		{
			for (int i = 0; i < m_lesserMaterial->Elements().size(); i++)
			{
				bool progress = true;
				for (int j = 0; j < holder.size() && progress; j++)
				{
					if (m_lesserMaterial->Elements().at(i) == holder.at(j))
					{
						progress = false;
					}
				}
				if (progress)
				{
					holder.push_back(m_lesserMaterial->Elements().at(i));
				}
			}
		}
		return holder;
	}

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

	void StatModCalculation()
	{
		PrimaryStats holder;

		holder = m_primaryMaterial->StatMods();
		if (m_secondaryMat) { holder.strength += (m_secondaryMaterial->StatMods().strength / 2);  };
		if (m_lesserMat) { holder.strength += (m_lesserMaterial->StatMods().strength / 3);  };

		if (m_secondaryMat) { holder.dexterity += (m_secondaryMaterial->StatMods().dexterity / 2);  };
		if (m_lesserMat) { holder.dexterity += (m_lesserMaterial->StatMods().dexterity / 3);  };

		if (m_secondaryMat) { holder.endurance += (m_secondaryMaterial->StatMods().endurance / 2);  };
		if (m_lesserMat) { holder.endurance += (m_lesserMaterial->StatMods().endurance / 3);  };

		if (m_secondaryMat) { holder.intelligence += (m_secondaryMaterial->StatMods().intelligence / 2);  };
		if (m_lesserMat) { holder.intelligence += (m_lesserMaterial->StatMods().intelligence / 3);  };

		if (m_secondaryMat) { holder.agility += (m_secondaryMaterial->StatMods().agility / 2);  };
		if (m_lesserMat) { holder.agility += (m_lesserMaterial->StatMods().agility / 3);  };

		if (m_secondaryMat) { holder.luck += (m_secondaryMaterial->StatMods().luck / 2);  };
		if (m_lesserMat) { holder.luck += (m_lesserMaterial->StatMods().luck / 3);  };

		if (m_secondaryMat) { holder.healthRegeneration += (m_secondaryMaterial->StatMods().healthRegeneration / 2);  };
		if (m_lesserMat) { holder.healthRegeneration += (m_lesserMaterial->StatMods().healthRegeneration / 3);  };

		if (m_secondaryMat) { holder.staminaRegeneration += (m_secondaryMaterial->StatMods().staminaRegeneration / 2);  };
		if (m_lesserMat) { holder.staminaRegeneration += (m_lesserMaterial->StatMods().staminaRegeneration / 3);  };

		if (m_secondaryMat) { holder.arousalRegeneration += (m_secondaryMaterial->StatMods().arousalRegeneration / 2);  };
		if (m_lesserMat) { holder.arousalRegeneration += (m_lesserMaterial->StatMods().arousalRegeneration / 3);  };

		if (m_secondaryMat) { holder.willpowerRegeneration += (m_secondaryMaterial->StatMods().willpowerRegeneration / 2);  };
		if (m_lesserMat) { holder.willpowerRegeneration += (m_lesserMaterial->StatMods().willpowerRegeneration / 3);  };

		if (m_secondaryMat) { holder.potionEffectiveness += (m_secondaryMaterial->StatMods().potionEffectiveness / 2);  };
		if (m_lesserMat) { holder.potionEffectiveness += (m_lesserMaterial->StatMods().potionEffectiveness / 3);  };

		m_statMods = holder;
	};

	void CalculateBasicStats()
	{
		float holder;
		int div;

		//Weight
		div = 0;
		holder = m_primaryMaterial->Density() * m_weight; div++;
		if (m_secondaryMat) { holder += m_secondaryMaterial->Density() * m_weight; div++;};
		if (m_lesserMat) { holder += m_lesserMaterial->Density() * m_weight; div++;};
		holder = holder / div;
		m_weight = holder * (m_size * 4);

		//Durability
		div = 0;
		holder = m_weight * m_durability;
		m_durability = holder * 100;
		m_durability *= (1 + (m_quality / 5));

		//Value
		div = 0;
		holder = m_primaryMaterial->Quality() * (m_weight); div++;
		if (m_secondaryMat) { holder += m_secondaryMaterial->Quality() * (m_weight); div++; };
		if (m_lesserMat) { holder += m_lesserMaterial->Quality() * (m_weight); div++; };
		holder = holder / 3;
		m_value = holder * 10;
		m_value *= (1 + (m_quality / 5));

		//Rating 
		m_rating = holder / 2;
		m_rating *= (1 + (m_quality / 5));

		m_weight = Round(m_weight);
		m_durability = Round(m_durability);
		m_value = Round(m_value);
		m_rating = Round(m_rating);
	};

	float StatMod(StatScaler m)
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
		holder = Round(holder);
		return holder;
	}

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
	}
};
#endif