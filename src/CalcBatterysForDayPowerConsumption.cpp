#include "CalcBatterysForDayPowerConsumption.h"

CalcBatterysForDayPowerConsumption::CalcBatterysForDayPowerConsumption(
	wHDay totalPowerConsumption,
	BatteryType batteryType,
	AH batteryCapacity )
{
	if( std::islessequal( batteryCapacity, 0.f ) )
		throw std::invalid_argument( "battery capacity must be positive" );

	m_totalPowerConsumption = totalPowerConsumption;
	m_batteryType = batteryType;
	m_batteryCapacity = batteryCapacity;
}


size_t CalcBatterysForDayPowerConsumption::getBatterysCount( ) const
{
	const auto wattsInBattery = m_batteryCapacity * BATTERY_TYPE_TO_RATED_POWER_FACTOR.at( m_batteryType ) * BATTERY_VOLTAGE;

	return std::ceil( m_totalPowerConsumption / wattsInBattery );
}
