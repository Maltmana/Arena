#pragma once

class Logger
{
public:
	static Logger & GetInstance();
private:
	Logger() {};
	static Logger instance;

public:
	Logger(Logger const&) = delete;
	void operator=(Logger const&) = delete;
	// Note: Scott Meyers mentions in his Effective Modern
	//       C++ book, that deleted functions should generally
	//       be public as it results in better error messages
	//       due to the compilers behavior to check accessibility
	//       before deleted status
};