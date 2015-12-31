#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>
#include <sstream>


class Logger
{
	public:
		enum class LEVEL {DEBUG, INFO, WARN, ERROR};

		explicit Logger(const std::string & clz, const LEVEL lvl) : clazz(clz), level(lvl) 
		{ }

		void info(const std::string & msg)
		{ log(msg); }


		void info(const std::string & msg, const std::string &x)
		{ log(msg, x); }


		void info(const std::string & msg, int v)
		{ log(msg, to_string(v)); }


		void info(const std::string & msg, double v)
		{ log(msg, to_string(v)); }


		void debug(const std::string & msg)
		{ log(msg); }
		

		void warn(const std::string & msg)
		{ log(msg); }


		void error(const std::string & msg)
		{ log(msg); }


	private:
		std::string		clazz;
		LEVEL				level;


		void log (const std::string & msg, const std::string & o1 = "")
		{
			switch( level )
			{
				case LEVEL::DEBUG:	
					std::cout << "[DEBUG]  " << clazz << " - "  << msg << " " << o1 << std::endl;  
					break;
				case LEVEL::INFO:		
					std::cout << "[INFO]   " << clazz << " - " << msg << " " << o1 << std::endl; 
					break;
				case LEVEL::WARN:		
					std::cout << "[WARN]   " << clazz << " - " << msg << " " << o1 << std::endl; 
					break;
				case LEVEL::ERROR:	
					std::cout << "[ERROR]  " << clazz << " - " << msg << " " << o1 << std::endl; 
					break;
				default:					
					std::cout << "No level specified." << msg << " " << o1 << std::endl;
			}
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


};

#endif
