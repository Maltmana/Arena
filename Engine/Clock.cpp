#include "Clock.h"



Clock::Clock()
{
		StartCounter();
}

void Clock::StartCounter()
{
	LARGE_INTEGER currentCount;

		QueryPerformanceFrequency(&currentCount);

		pcFreq = currentCount.QuadPart;

		QueryPerformanceCounter(&currentCount); // WARNING : reuses currentCount variable address

		counterStart = currentCount.QuadPart;
		prevCounter = counterStart;
}

double Clock::GetCounterS()
{

	LARGE_INTEGER currentCount;
	QueryPerformanceCounter(&currentCount);
	double result = (currentCount.QuadPart - counterStart) / pcFreq; // this is why pcfreq must be a decimal number. if it is an integer we will lose everything after the decimal during division
																	 // to test change PCFreq to a long long and check result
	prevCounter = currentCount.QuadPart;

	return double(result);

}

double Clock::GetCounterSinceLastS()
{
	LARGE_INTEGER currentCount;
	QueryPerformanceCounter(&currentCount);
	double result = (currentCount.QuadPart - prevCounter) / pcFreq;

	prevCounter = currentCount.QuadPart;

	return result;
}

double Clock::GetCounterMs()
{
	double milliMult = 1000.0;
	double result = GetCounterS();
	return result * milliMult;

}

double Clock::GetCounterSinceLastMs()
{
	double milliMult = 1000.0;
	double result = GetCounterSinceLastS();
	return result * milliMult;
}


