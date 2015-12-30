#ifndef FIX_MESSAGE_H
#define FIX_MESSAGE_H
#include <algorithm>
#include <string>
#include <iostream>

class FixMessage
{
	public:
		explicit FixMessage( )
		{ }

		void parse(const std::string & msg)
		{
			raw_msg = msg;
			std::cout << "printing..." << std::endl;
			for (unsigned int i = 0; i < msg.length(); ++i)
			{
				if (msg[i] == '\001')
					std::cout << "delemiter found" << std::endl;
				std::cout << i << ":" << msg[ i ] << std::endl;
			}
			std::cout << "end." << std::endl;
		}


		std::string create() 
		{
			char * arr = new char[100];
			arr[0] = '8'; arr[1] = '='; arr[2]='F';
			arr[3] = 'I'; arr[4] = 'X'; arr[5]='\001';
			arr[6] = '\0';
			std::cout << "create " << arr << std::endl;
			std::string s(arr);
			return s;
		}

		void addTag(std::string tag, std::string value)
		{ }

		void print( ) const
		{
			std::cout << raw_msg << std::endl;
		}

	private:
		std::string raw_msg;
};
#endif

