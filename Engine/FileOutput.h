#pragma once
#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include "cereal/cereal.hpp"
#include <cereal/archives/json.hpp>
#include <cereal/archives/xml.hpp>
#include <sstream>
#include <Windows.h>

// Uses boolean flag to schedule saves which are executed during Update()
class FileOutput
{
public:
	void Update();
	void RequestSave(std::string saveFileTitle = "untitled.xml");
private:
	void SaveGame() const;

	std::string m_saveFileTitle = "untitled.xml";

	LPCWSTR m_saveGamesFolder = L"SavedGames";
	bool m_toSaveFlag = false;
};