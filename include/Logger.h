#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>


class Logger
{
	public:
		enum class LEVEL {DEBUG, INFO, WARN, ERROR};

		explicit Logger(const std::string & clz) : clazz(clz)
		{ }

		void info(const std::string & msg)
		{ log(LEVEL::INFO, msg); }


		void info(const std::string & msg, const std::string &x)
		{ log(LEVEL::INFO, msg, x); }


		void info(const std::string & msg, int v)
		{ log(LEVEL::INFO, msg, to_string(v)); }


		void info(const std::string & msg, double v)
		{ log(LEVEL::INFO, msg, to_string(v)); }

		void info(const std::string & msg, const std::vector<std::string> v)
		{ log(LEVEL::INFO, msg, to_string(v)); }


		void debug(const std::string & msg)
		{ log(LEVEL::DEBUG, msg); }
		

		void warn(const std::string & msg)
		{ log(LEVEL::DEBUG, msg); }


		void error(const std::string & msg)
		{ log(LEVEL::ERROR, msg); }

		void error(const std::string & msg, const std::string & s)
		{ log(LEVEL::ERROR, msg, s); }


	private:
		std::string		clazz;


		void log (const LEVEL level, const std::string & msg, const std::string & o1 = "")
		{
			switch( level )
			{
				case LEVEL::DEBUG:	
					std::cout << "[DEBUG]  "; break;
				case LEVEL::INFO:		
					std::cout << "[INFO]   "; break;
				case LEVEL::WARN:		
					std::cout << "[WARN]   "; break;
				case LEVEL::ERROR:	
					std::cout << "[ERROR]  "; break;
				default:					
					std::cout << "[NO LEVEL]";
			}

			std::cout << clazz << " - "  << msg << " " << o1 << std::endl;
		}

		// hack since std::to_string() not supported
		std::string to_string(int v)
		{
			std::ostringstream ss;
			ss << v;
			return ss.str();
		}

		std::string to_string(double v)
		{
			std::ostringstream ss;
			ss << v;
			return ss.str();
		}

		std::string to_string(std::vector<std::string> v)
		{
			std::ostringstream ss;
			for (auto i : v)
				ss << i << ",";
			return ss.str();
		}


};

#endif
