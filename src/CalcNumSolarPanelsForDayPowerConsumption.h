#ifndef CalcNumSolarPanelsForDayPowerConsumption_H
#define CalcNumSolarPanelsForDayPowerConsumption_H

#include <cstddef>

class CalcNumSolarPanelsForDayPowerConsumption
{
public:
	using wHDay = float;
	using W = float;

	CalcNumSolarPanelsForDayPowerConsumption(
		wHDay totalPowerConsumption,
		std::size_t numOfSunshineHours );

public:
	size_t getSolarPanelsCount( ) const;
	float getNeededSquareForSolarPanels( ) const;

private:
	struct SolarPanel
	{
		static constexpr W POWER = 250.f;
		static constexpr auto SQUARE = 2.f;
	};

	wHDay m_totalPowerConsumption;
	std::size_t m_numOfSunshineHours;
};

#endif
