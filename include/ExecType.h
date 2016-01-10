#ifndef ExEc_TYPE_H
#define ExEc_TYPE_H

enum class EXEC_TYPE : char
{
	NEW			=		'0',
	DONE			=		'3',
	CANCELLED	=		'4',
	TRADE			=		'F',
	REJECTED		=		'8',
	EXPIRED		=		'C'


};
#endif
