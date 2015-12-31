#include "SerialRouter.h"
#include "Logger.h"
#include "Venue.h"
#include <algorithm>
#include <iostream>
#include <chrono>
#include <thread>
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
	log.info("starting...");

	while (! order.is_terminal() )
	{
		int leavesQty = order.leavesQty();
		log.info("leavesQty: ", leavesQty);


		// std::vector<Venue>
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}




