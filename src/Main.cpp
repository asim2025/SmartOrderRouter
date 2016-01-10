#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "Order.h"
#include "VenueManager.h"
#include "Venue.h"
#include "SerialRouter.h"
#include "Logger.h"
using namespace std;


// forward declarations
VenueManager create_venue_manager(); 

/*
 *
 *	Main program
 *
 */
int main(void)
{
	Logger Log("Main");

	// step 1 - create venue manager 
	VenueManager vm = create_venue_manager();

	
	// step 2 - create order: BUY IBM 100 @ market DAY
	Order prnt(SIDE::BUY, "IBM", 100, ORDER_TYPE::MARKET, 0.0, TIME_IN_FORCE::DAY);


	// step 3 - route order (serial way)
	SerialRouter sr(vm);

	// step 4 - time slice strategy
	int ncount = 0;
   while ( ! prnt.is_terminal() )
   {
		Log.info("=======================================");
		Log.info("timeslice:", ++ncount);
		sr.route( prnt );
		Log.info("=======================================");
      std::this_thread::sleep_for(std::chrono::milliseconds( 5 * 1000 ));
   }


	Log.info("done.");
}

/*
*	Create Venue Manager
*/
VenueManager create_venue_manager()
{
	VenueRank vr1(0.1, 0.5, 0.1, 0.5, 0.5);
	VenueRank vr2(0.2, 0.5, 0.3, 0.4, 0.2);
	VenueRank vr3(0.3, 0.5, 0.5, 0.3, 0.2);
	VenueRank vr4(0.4, 0.5, 0.4, 0.2, 0.1);

	vector<Venue> venues;

	Venue v1( "DPa", true, {"IBM", "GOOG"} );
	v1.update_rank("IBM", vr1);
	v1.update_rank("GOOG", vr2);
	venues.push_back( v1 );

	Venue v2( "DPb", true, {"IBM", "GOOG"} );
	v2.update_rank("IBM", vr3);
	v2.update_rank("GOOG", vr4);
	venues.push_back( v2 );

	Venue v3( "DPc", true, {"IBM", "GOOG"} );
	v3.update_rank("IBM", vr3);
	v3.update_rank("GOOG", vr3);
	venues.push_back( v3 );

	Venue v4( "DPd", true, {"IBM", "GOOG", "MSFT"} );
	v4.update_rank("IBM", vr3);
	v4.update_rank("GOOG", vr2);
	v4.update_rank("MSFT", vr1);
	venues.push_back( v4 );

	VenueManager vm( venues );
	return vm;
}

