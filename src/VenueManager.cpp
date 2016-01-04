#include "Venue.h"
#include "VenueManager.h"
#include <string>
#include <vector>
#include <map>
using namespace std;

void VenueManager::add_venue(const Venue & venue)
{
	Log.info("adding venue:", venue.name());
	Venues.push_back( venue );
}


void VenueManager::remove_venue(Venue & venue)
{
	Log.info("removing venue:", venue.name());
	if (Venues.empty())
		return;

	for ( auto it = Venues.begin(); it != Venues.end(); )
	{
		Venue v = *it;
		if ( v.name() == venue.name() )
		{
			it = Venues.erase( it );
			Log.info("removed:", v.name());
		}
		else
			++it;
	}
}


vector<Venue> VenueManager::get_venues(const string & symbol)
{
	return SymbolVenues[ symbol ];
}


void VenueManager::init()
{
	for ( auto it1 = Venues.begin(); it1 != Venues.end(); ++it1 )
	{
		Venue v = *it1;
		Log.info("v:", v.name());

		vector<string> symbols = v.symbols();
		for ( auto it2 = symbols.begin(); it2 != symbols.end(); ++it2 )
		{
			string symbol = *it2;
			vector<Venue> venues = SymbolVenues[ symbol ];
			Log.info("adding to symbol:", symbol);
			venues.push_back( v );
		}
	}
	
}

