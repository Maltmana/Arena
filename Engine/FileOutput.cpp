#include "FileOutput.h"
#include "cereal/types/memory.hpp"

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
	std::string filePath = "SavedGames\\" + m_saveFileTitle; // TODO : this really should be handled with concotanating savedGamesFolder

	if (CreateDirectory(m_saveGamesFolder, NULL) || ERROR_ALREADY_EXISTS == GetLastError())
	{
		std::ofstream ofs(filePath, std::ios::out | std::ios::trunc);
		if (ofs.is_open() != false) {
			cereal::XMLOutputArchive archive(ofs); // Choose binary format, writingdirection.
			int x = 0;
			for (auto & gwo : mainGWOContainer)
			{
				//gwo->serialize(archive);
				archive(CEREAL_NVP(*gwo));
			}
			//archive(CEREAL_NVP(5),
			//	CEREAL_NVP(20),
			//	CEREAL_NVP("turkey"),   // No NVP - cereal will automatically generate an enumerated name
			//	cereal::make_nvp("this_name_is_way_better", "gayNamedude")); // specify a name of your choosing
		}
	}
	else
	{
		// TODO : FAILED TO CREATE DIRECTORY ERROR MESG
	}
}
