#ifndef _ENCHANTMENT_H
#define _ENCHANTMENT_H

#include "Status.h"

enum EnchantTypes{SELF, TARGET, AURA};

class Enchantment
{
public:
	Enchantment() {};
	~Enchantment() {};

private:

	EnchantTypes m_type;
	std::string m_enchantName;
	std::string m_description;
	std::vector<Status> m_statuses;
	//std::vector<Skill> m_skills;
	bool m_curse;

	//Status Chance
	float m_chance;

	//Damage
	std::vector<Element> m_dotElements;
	int m_damage;

};
#endif