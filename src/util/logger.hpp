/**
	- В стиле какого паттерна проектирования написан этот класс?
	- Почему здесь использован этот паттерн?
	- Что такое LOG_INFO и для чего он сделан?
	- Зачем в классе КпоУ и деструктор сделаны private, а КК, КП, ОПК, ОПП удалены?
*/

#pragma once

#include <fstream>
#include <mutex>
#include <string>

#include "format.hpp"

#define LOG_INFO(...) sea::Logger::getInstance().log_info(sea::format_string(__VA_ARGS__))

namespace sea {
	class Logger {
		private:
			std::ofstream log_file;
			std::mutex log_mutex; 

			Logger();
			~Logger();

	public:
		Logger(const Logger&) = delete;
		Logger& operator=(const Logger&) = delete;
		
		Logger(Logger&&) = delete;
		Logger& operator=(Logger&&) = delete;

		static Logger& getInstance();

		void log_info(const std::string& message);
	};
}
