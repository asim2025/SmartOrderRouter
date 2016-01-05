#ifndef SERIAL_ROUTER_H
#define SERIAL_ROUTER_H
#include "VenueManager.h"
#include "OrderStatus.h"
#include "TimeInForce.h"
#include "OrderType.h"
#include "Side.h"
#include "Order.h"
#include "Logger.h"


/*
 *
 * Serial Router
 *
 *  Split parent order and send orders serially
 *  to multiple venues.
 *
 */
class SerialRouter
{
   public:
		SerialRouter(const VenueManager & vm) : VenueManager( vm ), Log("SerialRouter")
		{ }

      void route(const Order & order);


	private:
		VenueManager	VenueManager;
		Logger			Log;
};


#endif
