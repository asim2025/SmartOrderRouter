#ifndef ORDER_STATUS_H
#define ORDER_STATUS_H

enum class ORDER_STATUS : char
{
	NEW			=		'0',
	PARTIAL		=		'1',
	FILLED		=		'2',
	CANCELLED	=		'4',
	REJECTED		=		'8',
	EXPIRED		=		'C'


};
#endif
