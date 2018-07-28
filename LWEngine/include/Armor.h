#ifndef _ARMOR_H
#define _ARMOR_H

#include "Equipment.h"

enum ArmorType { SHIELD, HELMET, CHESTPLATE, GAUNTLET, GREAVES, BOOTS, OUTFIT, UPPER_UNDER, LOWER_UNDER, NECK, RING, EAR_PIERCING, TONGUE_PIERCING, NOSE_PIERCING, NIPPLE_PIERCING, VAGINA_PIERCING, PENIS_PIERCING, ANUS_PIERCING};

class Armor : public Equipment
{
public:
	Armor() {};
	Armor(std::string name, std::string descriptor, int quality, ArmorType type, float sharpness, float bluntness, float rating, int durability, float value, float weight, CraftMaterial * primary, CraftMaterial * secondary, CraftMaterial * lesser, bool sec, bool less, std::vector<Enchantment*> enchantments, int numberOfHands, float size)
	{
		m_name = name;
		m_description = descriptor;
		m_type = type;
		m_rating = rating;
		m_durability = durability;
		m_maxDurability = durability;
		m_value = value;
		m_weight = weight;
		m_primaryMaterial = primary;
		m_secondaryMaterial = secondary;
		m_lesserMaterial = lesser;
		m_enchantments = enchantments;
		m_secondaryMat = sec;
		m_lesserMat = less;
		m_size = size;
		m_quality = quality;
		CalculateBasicStats();
		CalculateResistance();
		StatModCalculation();
	};
	Armor(std::string name, std::string descriptor, ArmorType type, float sharpness, float bluntness, float rating, int durability, float value, float weight, bool sec, bool less, int numberOfHands, float size)
	{
		m_name = name;
		m_description = descriptor;
		m_type = type;
		m_rating = rating;
		m_durability = durability;
		m_maxDurability = durability;
		m_value = value;
		m_weight = weight;
		m_secondaryMat = sec;
		m_lesserMat = less;
		m_size = size;
	};

	~Armor() {};

	ArmorType Type() { return m_type; };

	float PhysicalResistance() { return m_physResistance; };
	float MagicResistance() { return m_magResistance; };

private:

	void CalculateResistance() 
	{
		float holderMagic;
		float holderPhys;
		int div;

		div = 0;
		holderMagic = m_primaryMaterial->MagicalDamage() * m_weight; div++;
		if (m_secondaryMat) { holderMagic += m_secondaryMaterial->MagicalDamage() * m_weight; div++; };
		if (m_lesserMat) { holderMagic += m_lesserMaterial->MagicalDamage() * m_weight; div++; };
		holderMagic /= div;

		div = 0;
		holderPhys = m_primaryMaterial->PhysicalDamage() * m_weight; div++;
		if (m_secondaryMat) { holderPhys += m_secondaryMaterial->PhysicalDamage() * m_weight; div++; };
		if (m_lesserMat) { holderPhys += m_lesserMaterial->PhysicalDamage() * m_weight; div++; };
		holderPhys /= div;

		float holderRatio = (holderMagic + holderPhys) / 100;
		holderPhys = holderPhys / holderRatio;
		holderMagic = holderMagic / holderRatio;

		m_magResistance = Round(holderMagic);
		m_physResistance = Round(holderPhys);

		m_rating = m_physResistance + m_physResistance;
	};

	float m_physResistance;
	float m_magResistance;

	ArmorType m_type;
};
#endif