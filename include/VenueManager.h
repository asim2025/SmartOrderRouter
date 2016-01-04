#ifndef VENUE_MANAGER_H
#define VENUE_MANAGER_H
#include <vector>
#include <map>
#include <string>
#include "Venue.h"
#include "Logger.h"

class VenueManager
{
	public:
		explicit VenueManager(std::vector<Venue> & venues ) : Venues( venues ),  Log("VenueManager", Logger::LEVEL::INFO)
		{ init(); }

		
		void add_venue(const Venue & venue);
		void remove_venue(Venue & venue);
		std::vector<Venue> get_venues(const std::string & symbol);

	private:
		std::vector<Venue> Venues;
		std::map<std::string, std::vector<Venue>> SymbolVenues;	
		Logger Log;
		void init();	


};
#endif
