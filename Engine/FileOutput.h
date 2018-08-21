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
	void Update()
	{
		if (m_toSaveFlag)
		{
			SaveGame();
			m_toSaveFlag = false;
		}
	}

	void RequestSave()
	{
		m_toSaveFlag = true;
	}

private:
	void SaveGame()
	{
		if (CreateDirectory(m_saveGamesFolder, NULL) || ERROR_ALREADY_EXISTS == GetLastError())
		{
			std::ofstream ofs(m_ofFilePath, std::ios::out | std::ios::trunc);
			if (ofs.is_open() != false) {
				cereal::XMLOutputArchive archive(ofs); // Choose binary format, writingdirection.
				archive(CEREAL_NVP(5),
					CEREAL_NVP(20),
					CEREAL_NVP("turkey"),   // No NVP - cereal will automatically generate an enumerated name
					cereal::make_nvp("this_name_is_way_better", "gayNamedude")); // specify a name of your choosing
			}
		}
		else
		{
			// TODO : FAILED TO CREATE DIRECTORY ERROR MESG
		}
	}

	std::string m_ofFilePath = "SavedGames\\Quicksave.XML"; // TODO : this really should be handled with concotanating savedGamesFolder
	LPCWSTR m_saveGamesFolder = L"SavedGames";
	bool m_toSaveFlag = false;
};