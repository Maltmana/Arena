#pragma once
#include <windows.h>
#include <assert.h>

class Clock
{
public:

	Clock();
	void StartCounter();
	double GetCounterS();
	double GetCounterSinceLastS();
	double GetCounterMs();
	double GetCounterSinceLastMs();

	void TestClock(); // TODO : Make this a unit test

	double frameTime = 0.0;

private:
	double pcFreq = 0.0;
	__int64 counterStart = 0;
	__int64 prevCounter;






};
