#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include "cereal/cereal.hpp"
#include <cereal/archives/json.hpp>
#include <cereal/archives/xml.hpp>
#include <sstream>
#include <Windows.h>
#include "GWO.h"

// Uses boolean flag to schedule saves which are executed during Update()
class FileOutput
{
public:
	// When RequestSave() is called, Update() will use the reference to const GWO container to serialize all objects in container
	void Update(std::vector<std::unique_ptr<GWO>> const & mainGWOContainer);
	void RequestSave(std::string saveFileTitle = "untitled.xml");
private:
	void SaveGame(std::vector<std::unique_ptr<GWO>> const & mainGWOContainer) const;

	std::string m_saveFileTitle = "untitled.xml";

	LPCWSTR m_saveGamesFolder = L"SavedGames";
	bool m_toSaveFlag = false;
};