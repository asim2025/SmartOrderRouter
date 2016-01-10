#ifndef VENUE_MANAGER_H
#define VENUE_MANAGER_H
#include <vector>
#include <map>
#include <string>
#include "Venue.h"
#include "Logger.h"
#include "Order.h"
#include "Execution.h"

class VenueManager
{
	public:
		explicit VenueManager(std::vector<Venue> & venues ) : Venues( venues ),  Log("VenueManager")
		{ init(); }

		
		void add_venue(const Venue & venue);
		void remove_venue(Venue & venue);
		std::vector<Venue> venues(const std::string & symbol);
		void send_order(const Venue & venue, const Order & order);
		void process_exec(const Execution & exec);
	private:
		std::vector<Venue> Venues;
		std::map<std::string, std::vector<Venue>> SymbolVenues;	
		Logger Log;
		void init();	


};
#endif
