#pragma once

struct Resources
{
	int health;
	int stamina;
	int arousal;
};

struct PrimaryStats
{
	int strength;
	int dexterity;
	int endurance;
	int intelligence;
	int agility;
	int luck;
};

struct SecondaryStats
{
	int libido;
	int faith;
};

struct Damage
{
	int physical;
	int fire;
	int wind;
	int water;
	int light;
};

struct Defense
{
	int physical;
	int fire;
	int wind;
	int water;
	int light;
};

struct Affinity
{
	int fire;
	int water;
	int wind;
	int light;
};