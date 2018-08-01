#ifndef _SKILL_H
#define _SKILL_H

#include "stdafx.h"
#include "Status.h"

class Skill
{
public:
	Skill() {};
	~Skill() {};

private:

	std::string m_name;
	std::string m_description;
	std::string m_attackDescription;
	std::vector<StatusEffect> m_effects;
	bool m_self;
	int m_damage;
	float m_magicDamage;
	float m_sharpDamage;
	float m_bluntDamage;

};
#endif