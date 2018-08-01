#pragma once

struct Resources
{
	int health;
	int maxHealth;
	int stamina;
	int staminaSoftcap;
	int maxStamina;
	int arousal;
	int maxArousal;
	int willpower; //Willingness to comply at any moment.
	int maxWillpower; //Max willpower.
};

struct PrimaryStats
{
	int strength; //Stamina used per melee attack + carry capacity
	int dexterity; //Hit Rate
	int endurance; //Max Health + Stamina
	int intelligence; //Stamina used per spell (Elemental)
	int agility; //Turn order
	int luck; //Crit;

	int healthRegeneration;
	int staminaRegeneration;
	int arousalRegeneration;
	int willpowerRegeneration;

	float potionEffectiveness;
};

struct Damage
{
	int sharp;
	int blunt;
	int magic;
};
