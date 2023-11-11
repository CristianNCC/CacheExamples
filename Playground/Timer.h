#pragma once

#include <iostream>
#include <chrono>

class cTimer;
#define TIMER_FROM_NOW cTimer t

class cTimer
{
public:

	cTimer()
	{
		m_start = std::chrono::steady_clock::now();
	}

	~cTimer()
	{
		auto end = std::chrono::steady_clock::now();
		auto duration = end - m_start;

		auto durationMs = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
		std::cout << "Time (milliseconds): " << durationMs.count() << std::endl;

		auto durationNs = std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
		std::cout << "Time (nanoseconds): " << durationNs.count() << std::endl;
	}

private:
	std::chrono::time_point<std::chrono::steady_clock> m_start = std::chrono::steady_clock::now();
};