#pragma once
#ifndef _CHARACTER_H
#define _CHARACTER_H

#include "BodyPart.h"
;
enum Gender { cgFEMININE, cgMASCULINE, cgAMBIGUOUS };
enum PrimaryRace { crHUMAN, crDEMON, crRABBIT, crSHARK};
enum Size {csMiniscule, csSmall, csAverage, csTall, csMassive};
enum Weight {cwFeatherweight, cwLight, cwAverage, cwHeavy, cwElephantine};
// add stats etc
//is leveling a thing or just stats?
class Character
{
public:
	Character() {}
	virtual ~Character() {}
	virtual void update() = 0;

	std::vector<BodyPart*> m_BodyParts;
	std::vector<BodyPart*> BodyParts() { return m_BodyParts; }; //get a character's body parts
	void Rating(BodyPart* incomingPart, int index) { m_BodyParts.at(index) = incomingPart; }; //change an indexed body part of a character


	PrimaryRace m_race;
	void Racing(PrimaryRace race) { m_race = race; }; //set a character's primary race
	PrimaryRace Racing() { return m_race; }; //get a character's primary race
	
	Gender m_gender;
	void Gendering(Gender gender) { m_gender = gender; }; //set a character's primary gender
	Gender Gendering() { return m_gender; }; //get a character's primary gender

	Size m_size;
	void Sizing(Size size) { m_size = size; }; //set a character's  size
	Size Sizing() { return m_size; }; //get a character's  size

	Weight m_weight;
	void Weighting(Weight weight) { m_weight = weight; }; //set a character's  weight
	Weight Weighting() { return m_weight; }; //get a character's  weight

	std::string m_characterName;
	void Name(std::string characterName) { m_characterName = characterName; }; //set a character's name
	std::string Name() { return m_characterName; }; //get a character's name


	std::string m_description;
	void Description(std::string description) { m_description = description; }; //set a character's description
	std::string Description() { return m_description; }; //get a character's description


	   /* You have a <gender_attribute> physique, with <size> <hair_type> hair accentuating your <gender_attribute> <skin_colour> <race_type> face. 
		Your face is held up by your <gender_attribute> neck, and is home to a <size> <nose_type> nose, as well as a human mouth with <mouth_type> lips, 
		containing <race_type> teeth and a <race_type> tongue.You have two <race_type> <eye_type> eyes and two <race_type> <size> ears.
		Your <muscle_type> torso is adorned by your <muscle_type> pecs, each sporting one <race_type> nipple that protrudes <arousal_level>. 
		Your <muscle_type> <race_type> waist gives your body a <muscle_type> figure.Under your waist lies a <ass_type>, <muscle_type> <race_type> ass,
		as well as a <genital_property> <race_type> <genital>, currently <arousal_level>.
		Your <height>, <muscle_type> <race_type> legs end with two <foot_size> <race_size> feet, <muscle_type> on the ground.*/
};
#endif