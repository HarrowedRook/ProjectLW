#ifndef _WEAPON_H
#define _WEAPON_H

#include "Equipment.h"
class Weapon : public Equipment
{
public:
	Weapon(std::string name, std::string descriptor, int rating, int durability, int value, int weight, CraftMaterial * primary, CraftMaterial * secondary, CraftMaterial * lesser, std::vector<Enchantment*> enchantments, int numberOfHands)
	{
		m_name = name;
		m_description = descriptor;
		m_rating = rating;
		m_durability = durability;
		m_maxDurability = durability;
		m_value = value;
		m_weight = weight;
		m_primaryMaterial = primary;
		m_secondaryMaterial = secondary;
		m_lesserMaterial = lesser;
		m_enchantments = enchantments;
		m_numberOfHandsRequired = numberOfHands;
	}
	~Weapon() {};

	void NumberOfHands(int x) { m_numberOfHandsRequired = x; };
	int NumberOfHands() { return m_numberOfHandsRequired; };

private:

	int m_numberOfHandsRequired;

};

#endif