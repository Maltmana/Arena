#include "FileOutput.h"

void FileOutput::Update(std::vector<std::unique_ptr<GWO>> const & mainGWOContainer)
{
	if (m_toSaveFlag)
	{
		SaveGame(mainGWOContainer);
		m_toSaveFlag = false;
	}
}

void FileOutput::RequestSave(std::string saveFileTitle)
{
	m_toSaveFlag = true;
	m_saveFileTitle = saveFileTitle;
}

void FileOutput::SaveGame(std::vector<std::unique_ptr<GWO>> const & mainGWOContainer) const
{
	std::string filePath = "SavedGames\\" + m_saveFileTitle; // TODO : this really should be handled with concotanating with m_savedGamesFolder 

	if (CreateDirectory(m_saveGamesFolder, NULL) || ERROR_ALREADY_EXISTS == GetLastError())
	{
		std::ofstream ofs(filePath, std::ios::out | std::ios::trunc);
		if (ofs.is_open() != false) {
			cereal::XMLOutputArchive archive(ofs);
			int x = 0;
			for (auto & gwo : mainGWOContainer)
			{
				archive(cereal::make_nvp(gwo->m_name, *gwo));
			}
		}
	}
	else
	{
		// TODO : FAILED TO CREATE DIRECTORY ERROR MESG
	}
}
