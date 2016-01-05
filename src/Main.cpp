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

   while ( ! prnt.is_terminal() )
   {
		sr.route( prnt );
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
   }


	Log.info("done.");

}


VenueManager create_venue_manager()
{
	vector<Venue> venues;
	Venue v1( "DPa", true, {"IBM", "GOOG"} );
	Venue v2( "DPb", true, {"IBM", "GOOG"} );
	Venue v3( "DPc", true, {"IBM", "GOOG"} );
	Venue v4( "DPd", true, {"IBM", "GOOG", "MSFT"} );
	venues.push_back( v1 );
	venues.push_back( v2 );
	venues.push_back( v3 );
	venues.push_back( v4 );
	VenueManager vm( venues );
	return vm;
}

