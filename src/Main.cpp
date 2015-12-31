#include "Order.h"
#include "Venue.h"
#include "SerialRouter.h"
#include <iostream>
#include <vector>
using namespace std;


// forward declarations
void create_venues(); 

/*
 *	Main program
 * 
 * 
 *
 */
int main(void)
{

	// step 1 - setup venues
	create_venues();

	// step 2 - create order: BUY IBM 100 @ market DAY
	Order prnt(SIDE::BUY, "IBM", 100, ORDER_TYPE::MARKET, 0.0, TIME_IN_FORCE::DAY);


	// step 3 - route order (serial way)
	SerialRouter sr;
	sr.route( prnt );

	cout << "done." << endl;

}


void create_venues()
{
	vector<Venue> venues;
	Venue v1( "DPa", true, {"IBM", "GOOG"} );
	Venue v2( "DPb", true, {"IBM", "GOOG"} );
	Venue v3( "DPc", true, {"IBM", "GOOG"} );
	Venue v4( "DPd", true, {"IBM", "GOOG"} );
	venues.push_back( v1 );
	venues.push_back( v2 );
	venues.push_back( v3 );
	venues.push_back( v4 );
}

