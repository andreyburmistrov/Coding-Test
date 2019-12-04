#include "CalcNumSolarPanelsForDayPowerConsumption.h"

#include <stdexcept>
#include <cmath>

CalcNumSolarPanelsForDayPowerConsumption::CalcNumSolarPanelsForDayPowerConsumption(
	wHDay totalPowerConsumption,
	std::size_t numOfSunshineHours )
{
	if( numOfSunshineHours == 0 )
		throw std::invalid_argument( "Num of sunshine hours must be positive" );

	m_totalPowerConsumption = totalPowerConsumption;
	m_numOfSunshineHours = numOfSunshineHours;
}


size_t CalcNumSolarPanelsForDayPowerConsumption::getSolarPanelsCount( ) const
{
	return std::ceil( m_totalPowerConsumption / ( m_numOfSunshineHours * SolarPanel::POWER ) );
}


float CalcNumSolarPanelsForDayPowerConsumption::getNeededSquareForSolarPanels( ) const
{
	return getSolarPanelsCount( ) * SolarPanel::SQUARE;
}
