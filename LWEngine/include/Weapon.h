#ifndef _WEAPON_H
#define _WEAPON_H

#include "Equipment.h"

enum WeaponType{SWORD, SPEAR, AXE, HAMMER, BOW, CROSSBOW, GUN, STAFF, WHIP, FIST};

class Weapon : public Equipment
{
public:

	Weapon() {};

	Weapon(std::string name, std::string descriptor, int quality, WeaponType type, float sharpness, float bluntness, float rating, int durability, float value, float weight, CraftMaterial * primary, CraftMaterial * secondary, CraftMaterial * lesser, bool sec, bool less, std::vector<Enchantment*> enchantments, int numberOfHands, float size)
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
		m_size = size;
		m_sharpness = sharpness;
		m_bluntness = bluntness;
		m_quality = quality;

		m_originalweight = m_weight;
		m_originalmaxDurability = m_durability;
		m_originalvalue = m_value;
		m_originalrating = m_rating;

		CalculateBasicStats();
		DamageRatio();
		StatModCalculation();

	};
	Weapon(std::string name, std::string descriptor, WeaponType type, float sharpness, float bluntness, float rating, int durability, float value, float weight, bool sec, bool less, int numberOfHands, float size)
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
		m_size = size;
		m_sharpness = sharpness;
		m_bluntness = bluntness;

		m_originalweight = m_weight;
		m_originalmaxDurability = m_durability;
		m_originalvalue = m_value;
		m_originalrating = m_rating;

	};
	~Weapon() {};

	void NumberOfHands(int x) { m_numberOfHandsRequired = x; };
	int NumberOfHands() { return m_numberOfHandsRequired; };

	void Type(WeaponType type) { m_type = type; };
	WeaponType Type() { return m_type; };

	float StrengthScale()
	{
		float Scale = StatMod(STRENGTH);
		switch (m_type)
		{
		case SWORD:
			Scale += 0.5;
			break;
		case SPEAR:
			Scale += 0.25;
			break;
		case AXE:
			Scale += 0.75;
			break;
		case HAMMER:
			Scale += 1.0;
			break;
		case BOW:
			Scale += 0.1;
			break;
		case CROSSBOW:
			Scale += 0.0;
			break;
		case GUN:
			Scale += 0.0;
			break;
		case STAFF:
			Scale += 0.0;
			break;
		case WHIP:
			Scale += 0.0;
			break;
		case FIST:
			Scale += 0.75;
			break;
		default:
			break;
		}
		return Scale;
	}
	float DexterityScale()
	{
		float Scale = StatMod(DEXTERITY);
		switch (m_type)
		{
		case SWORD:
			Scale += 0.5;
			break;
		case SPEAR:
			Scale += 0.75;
			break;
		case AXE:
			Scale += 0.25;
			break;
		case HAMMER:
			Scale += 0.0;
			break;
		case BOW:
			Scale += 0.75;
			break;
		case CROSSBOW:
			Scale += 0.25;
			break;
		case GUN:
			Scale += 0.0;
			break;
		case STAFF:
			Scale += 0.0;
			break;
		case WHIP:
			Scale += 1.0;
			break;
		case FIST:
			Scale += 0.5;
			break;
		default:
			break;
		}
		Scale /= 2;
		return Scale;
	}
	float EnduranceScale()
	{
		float Scale = StatMod(ENDURANCE);
		switch (m_type)
		{
		case SWORD:
			Scale += 0.0;
			break;
		case SPEAR:
			Scale += 0.0;
			break;
		case AXE:
			Scale += 0.1;
			break;
		case HAMMER:
			Scale += 0.5;
			break;
		case BOW:
			Scale += 0.1;
			break;
		case CROSSBOW:
			Scale += 0.0;
			break;
		case GUN:
			Scale += 0.0;
			break;
		case STAFF:
			Scale += 0.0;
			break;
		case WHIP:
			Scale += 0.0;
			break;
		case FIST:
			Scale += 0.1;
			break;
		default:
			break;
		}
		Scale /= 2;
		return Scale;
	}
	float IntelligenceScale()
	{
		float Scale = StatMod(INTELLIGENCE);
		switch (m_type)
		{
		case SWORD:
			Scale += 0.0;
			break;
		case SPEAR:
			Scale += 0.0;
			break;
		case AXE:
			Scale += 0.0;
			break;
		case HAMMER:
			Scale += 0.0;
			break;
		case BOW:
			Scale += 0.0;
			break;
		case CROSSBOW:
			Scale += 0.0;
			break;
		case GUN:
			Scale += 0.0;
			break;
		case STAFF:
			Scale += 1.0;
			break;
		case WHIP:
			Scale += 0.0;
			break;
		case FIST:
			Scale += 0.0;
			break;
		default:
			break;
		}
		Scale /= 2;
		return Scale;
	}
	float AgilityScale()
	{
		float Scale = StatMod(AGILITY);
		switch (m_type)
		{
		case SWORD:
			Scale += 0.0;
			break;
		case SPEAR:
			Scale += 0.05;
			break;
		case AXE:
			Scale += 0.0;
			break;
		case HAMMER:
			Scale += 0.0;
			break;
		case BOW:
			Scale += 0.25;
			break;
		case CROSSBOW:
			Scale += 0.25;
			break;
		case GUN:
			Scale += 0.0;
			break;
		case STAFF:
			Scale += 0.0;
			break;
		case WHIP:
			Scale += 0.0;
			break;
		case FIST:
			Scale += 0.05;
			break;
		default:
			break;
		}
		Scale /= 2;
		return Scale;
	}
	float LuckScale()
	{
		float Scale = StatMod(LUCK);
		switch (m_type)
		{
		case SWORD:
			Scale += 0.0;
			break;
		case SPEAR:
			Scale += 0.0;
			break;
		case AXE:
			Scale += 0.0;
			break;
		case HAMMER:
			Scale += 0.0;
			break;
		case BOW:
			Scale += 0.0;
			break;
		case CROSSBOW:
			Scale += 0.0;
			break;
		case GUN:
			Scale += 0.0;
			break;
		case STAFF:
			Scale += 0.0;
			break;
		case WHIP:
			Scale += 0.0;
			break;
		case FIST:
			Scale += 0.0;
			break;
		default:
			break;
		}
		Scale /= 2;
		return Scale;
	}

	float Sharpness() {  return m_sharpness; };
	float Bluntness() { return m_bluntness; };
	float Magic() { return m_magic; };

	Damage DamageCalculation(PrimaryStats x)
	{
		Damage holder;
		CalculateBasicStats();
		DamageRatio();
		StatModCalculation();

		float damHolder = 0;
		damHolder += (x.strength * StrengthScale());
		damHolder += (x.dexterity * DexterityScale());
		damHolder += (x.endurance * EnduranceScale());
		damHolder += (x.intelligence * IntelligenceScale());
		damHolder += (x.agility * AgilityScale());
		damHolder += (x.luck * LuckScale());

		damHolder /= 2;
		damHolder += m_rating;

		damHolder += ((rand() % 6) - 3);
		if (damHolder < 1)
		{
			damHolder = 1;
		}

		holder.sharp = damHolder * (m_sharpness/100);
		holder.blunt = damHolder * (m_bluntness/100);
		holder.magic = damHolder * (m_magic/100);

		//std::cout << StrengthScale() << "/" << DexterityScale() << "/" << EnduranceScale() << "/" << IntelligenceScale() << "/" << AgilityScale() << "/" << LuckScale() << "/" << std::endl;

		//std::cout << holder.sharp << "/" << holder.blunt << "/" << holder.magic << std::endl;

		return holder;
	}

private:
	void DamageRatio()
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

		m_magic = Round(holderMagic);

		float holder = m_sharpness + m_bluntness;
		holder /= holderPhys;
		m_sharpness = Round(m_sharpness / holder);
		m_bluntness = Round(m_bluntness / holder);
	}

	

	int m_numberOfHandsRequired;
	float m_sharpness, m_bluntness, m_magic;
	WeaponType m_type;
};

#endif