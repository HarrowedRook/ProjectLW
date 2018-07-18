#ifndef _BODYPART_H
#define _BODYPART_H

#include "CraftMaterial.h"
#include "WorldMaterial.h"

enum LimbType{HEAD, UPPER_TORSO, LOWER_TORSO, ARM, LEG, HAND, FOOT, TAIL, BREAST, DICK, TESTICAL, EYE, NOSE, EAR, MOUTH, BRAIN, HAIR, WING, HORN, ARM_WING};

class BodyPart
{
public:
	BodyPart() {};
	~BodyPart() {};

private:

	LimbType m_limb;
	std::string m_race;
	int m_health;
	int m_size;
	int m_naturalDamageReduction;
	bool m_amputated;
	bool m_amputatable;
	bool m_equipable;
	std::string m_color;
	std::string m_description;
	std::string m_trasnformation;
	Material m_material;

	//Bonuses
	PrimaryStats m_bonuses;
	//Skill/Spell

};
#endif