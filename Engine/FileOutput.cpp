#include "FileOutput.h"

void FileOutput::Update()
{
	if (m_toSaveFlag)
	{
		SaveGame();
		m_toSaveFlag = false;
	}
}

void FileOutput::RequestSave()
{
	m_toSaveFlag = true;
}

void FileOutput::SaveGame() const
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
