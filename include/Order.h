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
		explicit Order(SIDE side, std::string symbol, int orderQty, ORDER_TYPE orderType, double price,
				 TIME_IN_FORCE timeInForce) :
				Side( side ), 
				Symbol( symbol ), 
				OrderQty( orderQty ), 
				OrderType( orderType ), 
				Price( price ),
				TimeInForce( timeInForce )
		{
				MinQty			=		orderQty; 
				CumQty			=		0 ;
				OrdStatus		=		ORDER_STATUS::NEW;
		}

		Order(const Order & o) : 
				Side( o.Side ),
            Symbol( o.Symbol ),
            OrderQty( o.OrderQty ),
            OrderType( o.OrderType ),
            Price( o.Price ),
            TimeInForce( o.TimeInForce )
		{
				MinQty			=		o.OrderQty;
				CumQty			=		o.CumQty;
				OrdStatus		=		ORDER_STATUS::NEW;
		}

		int leavesQty() const
		{
			return OrderQty - CumQty;
		}

		bool is_terminal() const
		{
			if ( leavesQty() == 0 )
				return true;

			return false;
		}

		std::string symbol() const
		{ return Symbol; }

		void set_qty(int qty)
		{ OrderQty = qty; }

		
	private:
		// ---  fix fields ---
		SIDE				Side;							// 54=1 (buy), =2(sell)
		std::string		Symbol;						// 55
		int				OrderQty;					// 38
		ORDER_TYPE		OrderType;					// 40=1 (Mkt), 2(Limit)
		double			Price;						// 44
		TIME_IN_FORCE	TimeInForce;				// 59=3 (IOC)

		std::string		Account;						// 1
		std::string		ClOrdID;						// 11
		std::string		MsgType;						// 35=D
		std::string		Text;							// 58
		std::string		TransactTime;				// 60
		std::string		TradeDate;					// 75
		std::string		ExDestination;				// 100
		std::string		MinQty;						// 110

		// ---  instance fields ---
		int				CumQty;						// filled qty 
		ORDER_STATUS	OrdStatus;	
};
#endif

