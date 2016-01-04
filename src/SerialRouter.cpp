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

	if (! order.is_terminal() )
	{
		int leavesQty = order.leavesQty();
		Log.info("leavesQty: ", leavesQty);


		// std::vector<Venue>
	}
}




