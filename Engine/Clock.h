#pragma once
#include <windows.h>
#include <assert.h>

class Clock
{
public: // TODO : set up debug asserts or unit tests if even possible for this...

	Clock();
	void StartCounter();
	double GetCounterS();
	double GetCounterSinceLastS();
	double GetCounterMs();
	double GetCounterSinceLastMs();

	void TestClock();



private:
	double pcFreq = 0.0;
	__int64 counterStart = 0;
	__int64 prevCounter;




};
