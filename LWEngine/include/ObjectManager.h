#ifndef _OBJECTMANAGER_H
#define _OBJECTMANAGER_H

#include "Material.h"

#include <filesystem>

namespace fs = std::filesystem;

class ObjectManager
{
public:
	ObjectManager(std::string filelocation);
	~ObjectManager() {};

	Material * Metal(std::string id);
	Material * Metal(int index);
	int NumberOfMetals() { return m_metal.size(); };


private:

	Material LoadMaterial(const fs::directory_entry loc);

	//Materials
	std::map<std::string, Material> m_metal;
	std::vector<std::string> m_metalList;

};
#endif
