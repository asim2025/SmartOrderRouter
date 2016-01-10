#ifndef EXECUTION_H
#define EXECUTION_H
#include "Side.h"
#include "OrderType.h"
#include "OrderStatus.h"
#include "TimeInForce.h"
#include "ExecType.h"
#include <string>
#include <iostream>


class Execution
{
	public:
		explicit Execution(std::string orderID, std::string execID, EXEC_TYPE execType, ORDER_STATUS ordStatus,
			std::string symbol, SIDE side, int leavesQty, int cumQty, double avgPx) :
				OrderID( orderID ),
				ExecID( execID ),
				ExecType( execType), 
				OrdStatus( ordStatus ),
				Symbol( symbol ), 
				Side( side ), 
				LeavesQty( leavesQty ),
				CumQty( cumQty ),
				AvgPx( avgPx )
		{ }


		int leavesQty() const
		{ return LeavesQty; }


		std::string symbol() const
		{ return Symbol; }

		std::string exec_id() const
		{ return ExecID; }

		std::string order_id() const
		{ return OrderID; }

		
	private:
		// ---  fix fields ---
		std::string		OrderID;						// 37
		std::string		ExecID;						// 17
		EXEC_TYPE		ExecType;					// 150
		ORDER_STATUS	OrdStatus;					// 39
		std::string		Symbol;						// 55
		SIDE				Side;							// 54=1 (buy), =2(sell)
		int				LeavesQty;					// 151
		int				CumQty;						// 14, filled qty 
		double			AvgPx;						// 6
};
#endif

