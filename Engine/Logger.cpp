#include "Logger.h"

Logger & Logger::GetInstance()
{
	static Logger instance;
	return instance;
}
