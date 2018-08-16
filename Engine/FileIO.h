#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include "cereal/cereal.hpp"
#include <cereal/archives/json.hpp>
#include <cereal/archives/xml.hpp>
#include <sstream>
#include <Windows.h>

// we must connect the cereal archive to logicComponents seralize function.
//
//using namespace std;
//
//struct Human
//{
//	string name = "kevin";
//	int age = 22;
//	double BAC = 0.8;
//	string description = "kevin is an amazing bad ass dude whom many people enjoy being around, especially beautiful women.";
//	string hairColor = "blonde";
//
//	template<class Archive>
//	void serialize(Archive & archive)
//	{
//		archive(CEREAL_NVP(name), CEREAL_NVP(age), CEREAL_NVP(BAC), CEREAL_NVP(description));
//	}
//
//};
	/*	Human kevin;
		char x = 'x';
		int someInt;
		double d;
*/

class FileIO
{
public:
	void QuickSave()
	{
		SaveGame();
	}	

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
};