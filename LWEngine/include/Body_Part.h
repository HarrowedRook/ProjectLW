#ifndef _BODY_PART_H
#define _BODY_PART_H

#include "stdafx.h"

enum SKINTYPE {FLESH, HIDE, FUR, SCALE, CARAPACE, MOLUSK, SLIME, MATERIAL};

class Body_Part
{
public:
	Body_Part();
	~Body_Part();

private:
	Defense m_natural_defenses;
	PrimaryStats m_stat_mods;
	int m_heatResistance;
	int m_coldResistance;
	std::string m_description;
	std::string m_color;
	int m_size;
	int m_value_one;
	int m_value_two;
};
#endif
