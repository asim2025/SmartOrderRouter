#include "Venue.h"
#include "VenueManager.h"
#include "Order.h"
#include "Execution.h"
#include <string>
#include <vector>
#include <map>
using namespace std;

/*
*	Add a venue
*/
void VenueManager::add_venue(const Venue & venue)
{
	Log.info("adding venue:", venue.name());
	Venues.push_back( venue );
}


/*
*	Remove a venue
*/
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


/*
*	Return a list of Venues and execution probability that 
*	can execute incoming order
*/
vector<Venue> VenueManager::venues(const string & symbol)
{
	vector<Venue> venues = SymbolVenues[ symbol ];
	if (venues.empty())
		return venues;

	vector<Venue> rankings;
	double totalRank = 0.0;

	for (auto v : venues)
	{
		VenueRank vr = v.ranking( symbol );
		totalRank += vr.rank();
	}

	for (auto v : venues)
	{
		VenueRank vr = v.ranking( symbol );
		double probability = vr.rank() / totalRank;
		v.set_exec_prob( probability );
		Log.info("add ranking for venue:", v.name());
		rankings.push_back(v);
	}	

	return rankings;
}


/*
*	Internally segregate Venues by symbol
*/
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
			SymbolVenues[ symbol ] = venues;
		}
	}
}


/*
*	Send Order to a Venue (Market)
*/
void VenueManager::send_order(const Venue & venue, const Order & order)
{
	Log.info("order sent to venue:", venue.name());
}

/*
*	Process Ack/Fill from Venue (Market)
*/
void VenueManager::process_exec(const Execution & exec)
{
	Log.info("recevied exec:", exec.exec_id());
}
