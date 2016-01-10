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
void SerialRouter::route(const Order & prnt)
{
	Log.info("routing ...");

	if ( prnt.is_terminal() )
	{
		Log.error("order is in terminal state.");
		return;
	}
	
	int leavesQty = prnt.leavesQty();
	if ( leavesQty == 0 )
	{
		Log.error("order is fully filled.");
		return;
	}

	Log.info("leavesQty: ", leavesQty);

	string symbol = prnt.symbol();
	Log.info("symbol: ", symbol);

	vector<Venue> venues = VenueManager.venues( symbol );
	if (venues.empty())
	{
		Log.error("no venues found for symbol:", symbol);
		return;
	}

	for (auto v : venues)
	{
		int child_qty = leavesQty * v.exec_prob();
		cout << "v: " << v << ", prob:" << v.exec_prob() << ", child_qty: " << child_qty << endl;
		Order child( prnt );
		child.set_qty( child_qty );
		VenueManager.send_order( v, child);
	}
}


