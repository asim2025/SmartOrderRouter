#include "SerialRouter.h"
#include "Logger.h"
#include "Venue.h"
#include "VenueManager.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


/*
 *
 *	Serial Router 
 * 
 *  Split parent order and send orders serially 
 *  to multiple venues.
 *
 */
void SerialRouter::route(const Order & order)
{
	Log.info("routing ...");

	if ( order.is_terminal() )
	{
		Log.error("order is in terminal state.");
		return;
	}
	
	int leavesQty = order.leavesQty();
	if ( leavesQty == 0 )
	{
		Log.error("order is fully filled.");
		return;
	}

	Log.info("leavesQty: ", leavesQty);

	string symbol = order.symbol();
	Log.info("symbol: ", symbol);

	vector<Venue> venues = VenueManager.venues( symbol );
	if (venues.empty())
	{
		Log.error("no venues found for symbol:", symbol);
		return;
	}

	for (auto i : venues)
		cout << "v: " << i << endl;


}




