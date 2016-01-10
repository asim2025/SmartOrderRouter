#ifndef VENUE_RANK_H
#define VENUE_RANK_H

class VenueRank
{
	
	public:
		explicit VenueRank() : VenueTradingCost(0.0), RouterHistTradingVolume(0.0),
			MarketHistTradingVolume(0.0), ImmediateTradingActivity(0.0), PriceImprovementIndicator(0.0)
		{ }

		explicit VenueRank(double vtc, double rhtv, double mhtv, double ita, double pii) : 
			VenueTradingCost( vtc ), RouterHistTradingVolume( rhtv ), MarketHistTradingVolume( mhtv ), 
			ImmediateTradingActivity( ita ), PriceImprovementIndicator( pii )
		{ }

		void update_trading_cost(double v)
		{ 
			VenueTradingCost = v;
		}

		void update_router_hist_trading_volume(double v)
		{
			RouterHistTradingVolume += v;
		}

		void update_market_hist_trading_volume(double v)
		{
			MarketHistTradingVolume += v;
		}

		void update_immediate_trading_activity(double v)
		{
			ImmediateTradingActivity += v;
		}

		void update_price_improvement_indicator(double v)
		{
			PriceImprovementIndicator += v;
		}

		double rank() const
		{
			return (VenueTradingCost * 0.15) +
					 (RouterHistTradingVolume * 0.2) +
					 (MarketHistTradingVolume * 0.1) +
					 (PriceImprovementIndicator * 0.15) +
					 (ImmediateTradingActivity * 0.4);
		}

	private:
		double			VenueTradingCost;				// in basis points
		double			RouterHistTradingVolume;	// rHTV
		double			MarketHistTradingVolume;	// mHTV
		double			ImmediateTradingActivity;	// ITA
		double			PriceImprovementIndicator;	// PII

};
#endif
