#ifndef _EQUIPMENT_H
#define _EQUIPMENT_H

#include "stdafx.h"
#include "Material.h"
#include "Effect.h"

enum EQUIP_TYPE {WEAPON, ARMOR, ACCESSORY};
enum EQUIP_LOCATION {HELMET, FACE, FULL_HELMET, CHEST, GAUNTLETS, GREAVES, BOOTS, SHIELD, ONE_HANDED, TWO_HANDED, DUAL_HANDED, NECK, RING, WRIST, ANKLE};

class Equipment
{
public:
	Equipment(EQUIP_TYPE type, EQUIP_LOCATION location, std::string name, std::string description, Material* pm, Material* sm, Material* em, float weight, float rating, float value, float affinity, float quality) 
	{
		m_type = type;
		m_location_type = location;
		m_name = name;
		m_description = description;
		m_primaryMaterial = pm;
		m_secondaryMaterial = sm;
		m_embeddedMaterial = em;
		m_weight = weight;
		m_rating = rating;
		m_value = value;
		m_affinity = affinity;
		m_quality = quality;
		CalculateBasicStats();
	};
	~Equipment() {};

protected:

	void CalculateBasicStats()
	{
		//
		m_weight *= m_primaryMaterial->Weight();
		if (m_secondaryMaterial != NULL)
		{
			m_weight *= 0.75;
			m_weight += (m_secondaryMaterial->Weight() * 0.25);
		}
		if (m_embeddedMaterial != NULL)
		{
			m_weight *= 0.9;
			m_weight += (m_embeddedMaterial->Weight() * 0.1);
		}

		//
		if (m_embeddedMaterial != NULL)
		{
			m_element = m_embeddedMaterial->GetElement();
		}
		else
		{
			m_element = m_primaryMaterial->GetElement();
		}

		//
		m_affinity *= m_primaryMaterial->Affinity();
		if (m_secondaryMaterial != NULL)
		{
			m_affinity *= 0.75;
			m_affinity += (m_secondaryMaterial->Affinity() * 0.25);
		}
		if (m_embeddedMaterial != NULL)
		{
			m_affinity += (m_embeddedMaterial->Affinity() * 1.5);
			m_affinity /= 2;
		}
		m_affinity *= (m_quality / 100);

		//
		int holder = m_primaryMaterial->Rarity();
		if (holder > 10)
		{
			holder = 10;
		}
		else if (holder < 0)
		{
			holder = 0;
		}
		m_value = (holder * m_weight);
		m_value *= (m_quality / 100);

		//
		if (m_type == WEAPON)
		{
			m_rating *= m_primaryMaterial->Potential();
			if (m_secondaryMaterial != NULL)
			{
				m_rating *= 0.75;
				m_rating += (m_secondaryMaterial->Potential() * 0.25);
			}
			if (m_embeddedMaterial != NULL)
			{
				m_rating += (m_embeddedMaterial->Potential() * 1.2);
				m_rating /= 2;
			}
			m_rating *= (m_quality / 100);
		}
		else
		{
			m_rating *= m_primaryMaterial->Absorption();
			if (m_secondaryMaterial != NULL)
			{
				m_rating *= 0.75;
				m_rating += (m_secondaryMaterial->Absorption() * 0.25);
			}
			if (m_embeddedMaterial != NULL)
			{
				m_rating += (m_embeddedMaterial->Absorption() * 1.2);
				m_rating /= 2;
			}
			m_rating *= (m_quality / 100);
		}

		holder = m_name.find("%PM%");
		while (holder != std::string::npos)
		{
			m_name.replace(holder, 4, m_primaryMaterial->Name());
			m_description.replace(holder, 4, m_primaryMaterial->Name());
			holder = m_name.find("%PM%");
		}
		holder = m_description.find("%PM%");
		while (holder != std::string::npos)
		{
			m_description.replace(holder, 4, m_primaryMaterial->Name());
			holder = m_description.find("%PM%");
		}

		holder = m_name.find("%SM%");
		while (holder != std::string::npos)
		{
			m_name.replace(holder, 4, m_secondaryMaterial->Name());
			m_description.replace(holder, 4, m_secondaryMaterial->Name());
			holder = m_name.find("%SM%");
		}
		holder = m_description.find("%SM%");
		while (holder != std::string::npos)
		{
			m_description.replace(holder, 4, m_secondaryMaterial->Name());
			holder = m_description.find("%SM%");
		}

		holder = m_name.find("%EM%");
		while (holder != std::string::npos)
		{
			m_name.replace(holder, 4, m_embeddedMaterial->Name());
			m_description.replace(holder, 4, m_embeddedMaterial->Name());
			holder = m_name.find("%EM%");
		}
		holder = m_description.find("%EM%");
		while (holder != std::string::npos)
		{
			m_description.replace(holder, 4, m_embeddedMaterial->Name());
			holder = m_description.find("%EM%");
		}
	}

	std::string m_name;
	std::string m_description;
	
	Material* m_primaryMaterial;
	Material* m_secondaryMaterial;
	Material* m_embeddedMaterial;

	float m_weight;
	float m_rating;
	float m_value;
	float m_affinity;
	float m_quality;
	Element m_element;

	EQUIP_TYPE m_type;
	EQUIP_LOCATION m_location_type;
};
#endif

