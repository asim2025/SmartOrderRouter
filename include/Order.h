#ifndef ORDER_H
#define ORDER_H
#include "Side.h"
#include "OrderType.h"
#include "OrderStatus.h"
#include "TimeInForce.h"
#include <string>
#include <iostream>


class Order
{
	public:
		explicit Order(SIDE side, int orderQty, TIME_IN_FORCE timeInForce, ORDER_TYPE orderType, double price) 
			: Side( side ), OrderQty( orderQty ), TimeInForce( timeInForce ), OrderType( orderType), Price( price )
		{ }

		int leavesQuantity() const
		{
			return OrderQty - CumQty;
		}


	private:
		// ---  fix fields ---
		SIDE				Side;							// 54=1 (buy), =2(sell)
		int				OrderQty;					// 38
		TIME_IN_FORCE	TimeInForce;				// 59=3 (IOC)
		ORDER_TYPE		OrderType;					// 40=1 (Mkt), 2(Limit)
		double			Price;						// 44

		std::string		Account;						// 1
		std::string		ClOrdID;						// 11
		std::string		MsgType;						// 35=D
		std::string		Symbol;						// 55
		std::string		Text;							// 58
		std::string		TransactTime;				// 60
		std::string		TradeDate;					// 75
		std::string		ExDestination;				// 100
		std::string		MinQty;						// 110

		// ---  instance fields ---
		int				CumQty;						// filled qty 
		ORDER_STATUS		OrdStatus;	
};
#endif

