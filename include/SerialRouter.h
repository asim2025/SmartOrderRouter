#ifndef SERIAL_ROUTER_H
#define SERIAL_ROUTER_H

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
		SerialRouter() : log("SerialRouter", Logger::LEVEL::INFO)
		{ }

      void route(const Order & order);


	private:
		Logger log;
};


#endif
