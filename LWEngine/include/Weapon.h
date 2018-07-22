#ifndef _WEAPON_H
#define _WEAPON_H

#include "Equipment.h"

enum WeaponType{SWORD, SPEAR, AXE, HAMMER, BOW, CROSSBOW, GUN, STAFF, WHIP, FIST};

class Weapon : public Equipment
{
public:

	Weapon() {};

	Weapon(std::string name, std::string descriptor, WeaponType type, float sharpness, float bluntness, float rating, int durability, float value, float weight, CraftMaterial * primary, CraftMaterial * secondary, CraftMaterial * lesser, bool sec, bool less, std::vector<Enchantment*> enchantments, int numberOfHands)
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
		m_numberOfHandsRequired = numberOfHands;
		m_secondaryMat = sec;
		m_lesserMat = less;
	};
	Weapon(std::string name, std::string descriptor, WeaponType type, float sharpness, float bluntness, float rating, int durability, float value, float weight, bool sec, bool less, int numberOfHands)
	{
		m_name = name;
		m_description = descriptor;
		m_type = type;
		m_rating = rating;
		m_durability = durability;
		m_maxDurability = durability;
		m_value = value;
		m_weight = weight;
		m_numberOfHandsRequired = numberOfHands;
		m_secondaryMat = sec;
		m_lesserMat = less;
	};
	~Weapon() {};

	void NumberOfHands(int x) { m_numberOfHandsRequired = x; };
	int NumberOfHands() { return m_numberOfHandsRequired; };

	void Type(WeaponType type) { m_type = type; };
	WeaponType Type() { return m_type; };

	float StrengthMod()
	{
		float mod = StatMod(STRENGTH);
		switch (m_type)
		{
		case SWORD:
			mod += 0.5;
			break;
		case SPEAR:
			mod += 0.25;
			break;
		case AXE:
			mod += 0.75;
			break;
		case HAMMER:
			mod += 1.0;
			break;
		case BOW:
			mod += 0.1;
			break;
		case CROSSBOW:
			mod += 0.0;
			break;
		case GUN:
			mod += 0.0;
			break;
		case STAFF:
			mod += 0.0;
			break;
		case WHIP:
			mod += 0.0;
			break;
		case FIST:
			mod += 0.75;
			break;
		default:
			break;
		}
		mod /= 2;
		return mod;
	}
	float DexterityMod()
	{
		float mod = StatMod(DEXTERITY);
		switch (m_type)
		{
		case SWORD:
			mod += 0.5;
			break;
		case SPEAR:
			mod += 0.75;
			break;
		case AXE:
			mod += 0.25;
			break;
		case HAMMER:
			mod += 0.0;
			break;
		case BOW:
			mod += 0.75;
			break;
		case CROSSBOW:
			mod += 0.25;
			break;
		case GUN:
			mod += 0.0;
			break;
		case STAFF:
			mod += 0.0;
			break;
		case WHIP:
			mod += 1.0;
			break;
		case FIST:
			mod += 0.5;
			break;
		default:
			break;
		}
		mod /= 2;
		return mod;
	}
	float EnduranceMod()
	{
		float mod = StatMod(ENDURANCE);
		switch (m_type)
		{
		case SWORD:
			mod += 0.0;
			break;
		case SPEAR:
			mod += 0.0;
			break;
		case AXE:
			mod += 0.1;
			break;
		case HAMMER:
			mod += 0.5;
			break;
		case BOW:
			mod += 0.1;
			break;
		case CROSSBOW:
			mod += 0.0;
			break;
		case GUN:
			mod += 0.0;
			break;
		case STAFF:
			mod += 0.0;
			break;
		case WHIP:
			mod += 0.0;
			break;
		case FIST:
			mod += 0.1;
			break;
		default:
			break;
		}
		mod /= 2;
		return mod;
	}
	float IntelligenceMod()
	{
		float mod = StatMod(INTELLIGENCE);
		switch (m_type)
		{
		case SWORD:
			mod += 0.0;
			break;
		case SPEAR:
			mod += 0.0;
			break;
		case AXE:
			mod += 0.0;
			break;
		case HAMMER:
			mod += 0.0;
			break;
		case BOW:
			mod += 0.0;
			break;
		case CROSSBOW:
			mod += 0.0;
			break;
		case GUN:
			mod += 0.0;
			break;
		case STAFF:
			mod += 1.0;
			break;
		case WHIP:
			mod += 0.0;
			break;
		case FIST:
			mod += 0.0;
			break;
		default:
			break;
		}
		mod /= 2;
		return mod;
	}
	float AgilityMod()
	{
		float mod = StatMod(AGILITY);
		switch (m_type)
		{
		case SWORD:
			mod += 0.0;
			break;
		case SPEAR:
			mod += 0.05;
			break;
		case AXE:
			mod += 0.0;
			break;
		case HAMMER:
			mod += 0.0;
			break;
		case BOW:
			mod += 0.25;
			break;
		case CROSSBOW:
			mod += 0.25;
			break;
		case GUN:
			mod += 0.0;
			break;
		case STAFF:
			mod += 0.0;
			break;
		case WHIP:
			mod += 0.0;
			break;
		case FIST:
			mod += 0.05;
			break;
		default:
			break;
		}
		mod /= 2;
		return mod;
	}
	float LuckMod()
	{
		float mod = StatMod(LUCK);
		switch (m_type)
		{
		case SWORD:
			mod += 0.0;
			break;
		case SPEAR:
			mod += 0.0;
			break;
		case AXE:
			mod += 0.0;
			break;
		case HAMMER:
			mod += 0.0;
			break;
		case BOW:
			mod += 0.0;
			break;
		case CROSSBOW:
			mod += 0.0;
			break;
		case GUN:
			mod += 0.0;
			break;
		case STAFF:
			mod += 0.0;
			break;
		case WHIP:
			mod += 0.0;
			break;
		case FIST:
			mod += 0.0;
			break;
		default:
			break;
		}
		mod /= 2;
		return mod;
	}

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
				holder.push_back(m_secondaryMaterial->Elements().at(i));
			}
		}
		if (m_lesserMat)
		{
			for (int i = 0; i < m_lesserMaterial->Elements().size(); i++)
			{
				holder.push_back(m_lesserMaterial->Elements().at(i));
			}
		}
		return holder;
	};

	float Sharpness() { return m_sharpness; };
	float Bluntness() { return m_bluntness; };

private:

	int m_numberOfHandsRequired;
	float m_sharpness, m_bluntness;
	WeaponType m_type;
};

#endif