#pragma once
#include <ostream>
#include <chrono>
#include <chrono>
#define MAX 10

using namespace std;

namespace sict
{
	class Timekeeper
	{
		size_t	numberOfRecords;
		chrono::steady_clock::time_point startTime;
		chrono::steady_clock::time_point endTime;
		struct {
			const char* message;
			const char* time;
			chrono::steady_clock::duration event;
		} record[MAX];
		size_t size;
		
	public:
		Timekeeper();
		void start();
		void stop();
		void recordEvent(const char* description);
		void report(std::ostream & os);
	};
}

