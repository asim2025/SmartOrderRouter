#ifndef VENUE_H
#define VENUE_H
#include "VenueRank.h"
#include <string>
#include <map>
#include <vector>

/*
 * 
 *  A Venue is either an Exchange or a Dark Pool
 *
 *
*/
class Venue
{
	public:
		explicit Venue(std::string name, bool available, std::vector<std::string> symbols) 
			: Name( name ), Available( available ), Symbols( symbols )
		{ }

		std::string name() const
		{ return Name; }

		bool available() const
		{ return Available; }


	private:
		std::string						Name;											// venue name
		bool								Available;									// venue availablility flag
		std::vector<std::string>	Symbols;										// symbols supported by venue
		std::map<std::string, VenueRank> Rankings;							// symbol ranking
};
#endif
