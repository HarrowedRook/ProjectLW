#ifndef _BODYPART_H
#define _BODYPART_H

#include "CraftMaterial.h"
#include "WorldMaterial.h"
#include "Status.h"

enum LimbType{HEAD, UPPER_TORSO, LOWER_TORSO, ARM, LEG, HAND, FOOT, TAIL, BREAST, ASS, DICK, TESTICLE, CUNT, ANUS, FACE, EYE, NOSE, EAR, MOUTH, BRAIN, HAIR, WING, HORN, ARM_WING};
enum AttackType{NORMAL, BEAST, INSECT, CRUSTACEAN, TENTACLE};
enum SkinType{SKIN, FUR, CARAPICE, SCALES, FEATHERS};
enum LimbGender{FEMININE, MASCULINE, AMBIGUOUS};

class BodyPart
{
public:
	BodyPart(LimbType limbtype, SkinType skintype, AttackType attacktype, LimbGender gender, std::string race, std::string color, std::string description, std::string transformation, int health, float size, float volume, int damageReduction, bool amputatable, bool equipable, PrimaryStats bonus, std::vector<Status*> statuses)
	{
		m_limbType = limbtype;
		m_skinType = skintype;
		m_attackType = attacktype;
		m_limbGender = gender;
		m_race = race;
		m_color = color;
		m_description = description;
		m_transformation = transformation;
		m_health = health;
		m_maxHealth = m_health;
		m_size = size;
		m_volume = volume;
		m_naturalDamageReduction = damageReduction;
		m_amputatable = amputatable;
		m_amputated = false;
		m_equipable = equipable;
		m_bonuses = bonus;
		m_status = statuses;
		m_materialUsed = false;
	};
	BodyPart(LimbType limbtype, SkinType skintype, AttackType attacktype, LimbGender gender, std::string race, std::string color, std::string description, std::string transformation, int health, float size, float volume, int damageReduction, bool amputatable, bool equipable, Material* material, PrimaryStats bonus, std::vector<Status*> statuses)
	{
		m_limbType = limbtype;
		m_skinType = skintype;
		m_attackType = attacktype;
		m_limbGender = gender;
		m_race = race;
		m_color = color;
		m_description = description;
		m_transformation = transformation;
		m_health = health;
		m_maxHealth = m_health;
		m_size = size;
		m_volume = volume;
		m_naturalDamageReduction = damageReduction;
		m_amputatable = amputatable;
		m_amputated = false;
		m_equipable = equipable;
		m_bonuses = bonus;
		m_status = statuses;
		m_material = material;
		m_materialUsed = true;
	};
	~BodyPart() {};

	LimbType Limb_Type() { return m_limbType; };
	std::string Description()
	{
		//if (m_primaryMaterial != NULL)
		//{
		//	bool proceed = false;
		//	while (!proceed)
		//	{
		//		proceed = true;
		//		int holder = x.find("<pm>");
		//		if (holder > -1)
		//		{
		//			proceed = false;
		//			x.replace(holder, 4, m_primaryMaterial->Name());
		//		}
		//	}
		//	proceed = false;
		//	while (!proceed)
		//	{
		//		proceed = true;
		//		int holder = x.find("<sm>");
		//		if (holder > -1)
		//		{
		//			proceed = false;
		//			x.replace(holder, 4, m_secondaryMaterial->Name());
		//		}
		//	}
		//	proceed = false;
		//	while (!proceed)
		//	{
		//		proceed = true;
		//		int holder = x.find("<lm>");
		//		if (holder > -1)
		//		{
		//			proceed = false;
		//			x.replace(holder, 4, m_lesserMaterial->Name());
		//		}
		//	}
		//}
		std::string holderString = m_description;

		bool proceed = false;
		while (!proceed)
		{
			proceed = true;
			int holder = holderString.find("<material>");
			if (holder > -1)
			{
				proceed = false;
				holderString.replace(holder, 4, m_material->Name());
			}
		}
		proceed = false;
		while (!proceed)
		{
			proceed = true;
			int holder = holderString.find("<weight>");
			if (holder > -1)
			{
				proceed = false;
				holderString.replace(holder, 4, std::to_string(m_volume) + " kg");
			}
		}
		proceed = false;
		while (!proceed)
		{
			proceed = true;
			int holder = holderString.find("<size>");
			if (holder > -1)
			{
				proceed = false;
				std::string weightHolder;
				if (m_volume < 25)
				{

				}

				holderString.replace(holder, 4, std::to_string(m_size) + " meters");
			}
		}

		return holderString;
	};

private:

	SkinType m_skinType;
	LimbType m_limbType;
	AttackType m_attackType;
	LimbGender m_limbGender;
	std::string m_race;
	std::string m_color;
	std::string m_description;
	std::string m_transformation;
	int m_health;
	int m_maxHealth;
	float m_size;
	float m_volume;
	int m_naturalDamageReduction;
	bool m_amputated;
	bool m_amputatable;
	bool m_equipable;
	bool m_materialUsed;
	Material* m_material;

	//Bonuses
	PrimaryStats m_bonuses;
	std::vector<Status*> m_status;
	//Skill/Spell

};
#endif