#include "Equipment.h"

void Equipment::StatModCalculation()
{
	PrimaryStats holder;

	holder = m_primaryMaterial->StatMods();
	if (m_secondaryMat) { holder.strength += (m_secondaryMaterial->StatMods().strength / 2); };
	if (m_lesserMat) { holder.strength += (m_lesserMaterial->StatMods().strength / 3); };

	if (m_secondaryMat) { holder.dexterity += (m_secondaryMaterial->StatMods().dexterity / 2); };
	if (m_lesserMat) { holder.dexterity += (m_lesserMaterial->StatMods().dexterity / 3); };

	if (m_secondaryMat) { holder.endurance += (m_secondaryMaterial->StatMods().endurance / 2); };
	if (m_lesserMat) { holder.endurance += (m_lesserMaterial->StatMods().endurance / 3); };

	if (m_secondaryMat) { holder.intelligence += (m_secondaryMaterial->StatMods().intelligence / 2); };
	if (m_lesserMat) { holder.intelligence += (m_lesserMaterial->StatMods().intelligence / 3); };

	if (m_secondaryMat) { holder.agility += (m_secondaryMaterial->StatMods().agility / 2); };
	if (m_lesserMat) { holder.agility += (m_lesserMaterial->StatMods().agility / 3); };

	if (m_secondaryMat) { holder.luck += (m_secondaryMaterial->StatMods().luck / 2); };
	if (m_lesserMat) { holder.luck += (m_lesserMaterial->StatMods().luck / 3); };

	if (m_secondaryMat) { holder.healthRegeneration += (m_secondaryMaterial->StatMods().healthRegeneration / 2); };
	if (m_lesserMat) { holder.healthRegeneration += (m_lesserMaterial->StatMods().healthRegeneration / 3); };

	if (m_secondaryMat) { holder.staminaRegeneration += (m_secondaryMaterial->StatMods().staminaRegeneration / 2); };
	if (m_lesserMat) { holder.staminaRegeneration += (m_lesserMaterial->StatMods().staminaRegeneration / 3); };

	if (m_secondaryMat) { holder.arousalRegeneration += (m_secondaryMaterial->StatMods().arousalRegeneration / 2); };
	if (m_lesserMat) { holder.arousalRegeneration += (m_lesserMaterial->StatMods().arousalRegeneration / 3); };

	if (m_secondaryMat) { holder.willpowerRegeneration += (m_secondaryMaterial->StatMods().willpowerRegeneration / 2); };
	if (m_lesserMat) { holder.willpowerRegeneration += (m_lesserMaterial->StatMods().willpowerRegeneration / 3); };

	if (m_secondaryMat) { holder.potionEffectiveness += (m_secondaryMaterial->StatMods().potionEffectiveness / 2); };
	if (m_lesserMat) { holder.potionEffectiveness += (m_lesserMaterial->StatMods().potionEffectiveness / 3); };

	m_statMods = holder;
};

void Equipment::CalculateBasicStats()
{
	float holder;
	int div;

	m_rating = m_originalrating;
	m_maxDurability = m_originalmaxDurability;
	m_value = m_originalvalue;
	m_weight = m_originalweight;


	//Weight
	div = 0;
	holder = m_primaryMaterial->Density() * m_weight; div++;
	if (m_secondaryMat) { holder += m_secondaryMaterial->Density() * m_weight; div++; };
	if (m_lesserMat) { holder += m_lesserMaterial->Density() * m_weight; div++; };
	holder = holder / div;
	m_weight = holder * (m_size * 4);

	//Durability
	div = 0;
	holder = m_weight * m_durability;
	m_maxDurability = holder * 100;
	m_maxDurability *= (1 + (m_quality / 5));

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
	m_value = Round(m_value);
	m_rating = Round(m_rating);

	if (m_durability > m_maxDurability)
	{
		m_durability = m_maxDurability;
	}

};

float Equipment::StatMod(StatScaler m)
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
	if (holder < 0)
	{
		holder = 0;
	}
	return holder;
}

std::vector<Element> Equipment::Elements()
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

std::string Equipment::Parser(std::string x)
{
	if (m_primaryMaterial != NULL)
	{
		bool proceed = false;
		while (!proceed)
		{
			proceed = true;
			int holder = x.find("<pm>");
			if (holder > -1)
			{
				proceed = false;
				x.replace(holder, 4, m_primaryMaterial->Name());
			}
		}
		proceed = false;
		while (!proceed)
		{
			proceed = true;
			int holder = x.find("<sm>");
			if (holder > -1)
			{
				proceed = false;
				x.replace(holder, 4, m_secondaryMaterial->Name());
			}
		}
		proceed = false;
		while (!proceed)
		{
			proceed = true;
			int holder = x.find("<lm>");
			if (holder > -1)
			{
				proceed = false;
				x.replace(holder, 4, m_lesserMaterial->Name());
			}
		}
	}

	return x;
}