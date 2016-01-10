#ifndef VENUE_H
#define VENUE_H
#include "VenueRank.h"
#include <string>
#include <map>
#include <vector>
#include <iostream>

/*
 * 
 *  A Venue is either an Exchange or a Dark Pool
 *
 *
*/
class Venue
{
	public:
		explicit Venue(std::string name, bool available, std::vector<std::string> symbols) 
			: Name( name ), Available( available ), Symbols( symbols ), Probability( 0.0 )
		{ }

		std::string name() const
		{ return Name; }

		bool available() const
		{ return Available; }

		std::vector<std::string> symbols() const
		{ return Symbols; }

		VenueRank ranking(const std::string & symbol) 
		{ return SymbolRankings[ symbol ]; }

		void update_rank(const std::string & symbol, const VenueRank & rank)
		{ SymbolRankings[ symbol ] = rank; }

		void set_exec_prob(double p)
		{ Probability = p; }

		const double exec_prob()
		{ return Probability; }

	private:
		std::string						Name;											// venue name
		bool								Available;									// venue availablility flag
		std::vector<std::string>	Symbols;										// symbols supported by venue
		std::map<std::string, VenueRank> SymbolRankings;					// symbol ranking
		double							Probability;								// execution probability

		friend std::ostream& operator<< (std::ostream & os, const Venue & v)
		{
			os << "Venue: [" << v.name() << "," << v.available() << "," ;
			for (auto i : v.symbols())
				os << i << ",";
			os << "]";
			return os;
		}
};
#endif
