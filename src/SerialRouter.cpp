#include <algorithm>
#include <iostream>
#include "OrderStatus.h"
#include "TimeInForce.h"
#include "OrderType.h"
#include "Side.h"
#include "Order.h"
using namespace std;


/*
 *
 *	Serial Router 
 * 
 *  Split parent order and send orders serially 
 *  to multiple venues.
 *
 */
int main(void)
{

	// BUY 100 DAY MARKET PRICE
	Order prnt(SIDE::BUY, 100, TIME_IN_FORCE::DAY, ORDER_TYPE::MARKET, 0.0);

	cout << "starting..." << endl;

}


void serial_router(Order & prnt)
{



}

