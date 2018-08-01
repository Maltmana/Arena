#pragma once
#include <windows.h>

class Clock
{
public:

	Clock();
	void StartCounter();
	double GetCounterS();
	double GetCounterSinceLastS();
	double GetCounterMs();
	double GetCounterSinceLastMs();



private:
	double pcFreq = 0.0;
	__int64 counterStart = 0;
	__int64 prevCounter;




};
