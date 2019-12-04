#include "CalcSolarPanelsForDayPowerConsumption.h"

#include <stdexcept>
#include <cmath>

CalcSolarPanelsForDayPowerConsumption::CalcSolarPanelsForDayPowerConsumption(
	wHDay totalPowerConsumption,
	std::size_t numOfSunshineHours )
{
	if( numOfSunshineHours == 0 )
		throw std::invalid_argument( "Num of sunshine hours must be positive" );

	m_totalPowerConsumption = totalPowerConsumption;
	m_numOfSunshineHours = numOfSunshineHours;
}


size_t CalcSolarPanelsForDayPowerConsumption::getSolarPanelsCount( ) const
{
	return std::ceil( m_totalPowerConsumption / ( m_numOfSunshineHours * SolarPanel::POWER ) );
}


float CalcSolarPanelsForDayPowerConsumption::getNeededSquareForSolarPanels( ) const
{
	return getSolarPanelsCount( ) * SolarPanel::SQUARE;
}
