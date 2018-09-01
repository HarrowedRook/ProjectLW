#pragma once
#include "Character.h"

class PlayerCharacter : public Character
{
public:

	
	PlayerCharacter() {};

	PlayerCharacter(std::string name, std::string descriptor, std::vector<BodyPart*> bodyParts, Size size,  Gender gender, PrimaryRace primaryRace, Weight weight)
	{
		m_characterName = name;
		m_description = descriptor;
		m_BodyParts = bodyParts;
		m_size = size;
		m_gender = gender;
		m_race = primaryRace;
		m_weight = weight;
		
		//StatModCalculation();

	};

	void update()
	{
		//update things
	}

	void printDescription()
	{
		//print description of pc
	}
	

};