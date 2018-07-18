#ifndef _STATUS_H
#define _STATUS_H

#include "CraftMaterial.h"
#include "WorldMaterial.h"

enum StatusEffect{ DOT, TOT, DEBUFF, RESTRICTION, WEAKNESS, WERESTATE };
enum ActionType{ MOVEMENT, ATTACK, SKILL, MAGIC, SEX_ACT, SPEECH };
enum Condition{ MORNING, DAY, EVENING, NIGHT, CONTACT};


class Status
{
public:
	Status() {};
	~Status() {};

private:

	std::string m_statusName;
	std::vector<StatusEffect> m_effects;
	int m_duration;
	bool m_beneficial;

	//DOT
	int m_damage;
	std::vector<Element> m_dotElements;

	//TOT
	//Transformation
	int m_timePerChange;

	//Debuff
	float m_strMod;
	float m_dexMod;
	float m_endMod;
	float m_intMod;
	float m_agiMod;
	float m_lukMod;

	//Restriction
	std::vector<ActionType> m_restrictions;

	//Weakness
	std::vector<Element> m_weaknessElements;
	int m_magnitude;

	//Werestate
	Condition m_condition;
	int m_werestateDuration;
	//Transformation
	//Original Form

};
#endif