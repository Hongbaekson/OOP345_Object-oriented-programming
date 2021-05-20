//(133181164 hongback Son)

#define _CRT_SECURE_NO_WARNINGS

#include "Timekeeper.h"
#include <chrono>
#include <cstring>
#include <iomanip>

using namespace std;

namespace sict
{
	Timekeeper::Timekeeper()
	{
		size = 0;
	}
	void Timekeeper::start()
	{
		startTime = chrono::steady_clock::now();
	}
	void Timekeeper::stop()
	{
		endTime = chrono::steady_clock::now();
	}
	void Timekeeper::recordEvent(const char* description)
	{
		record[size].message = description;
		// record[size].event = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
		record[size].event = endTime - startTime;
		size++;
	}
	void Timekeeper::report(std::ostream & os)
	{
		os << "\nExecution Times:" << endl;
		for(size_t i = 0; i < size; i++)
		{
			os << left << setw(20) << record[i].message << right << setw(4) << chrono::duration_cast<chrono::milliseconds>(record[i].event).count() << " seconds" << endl;
		}
	}
}