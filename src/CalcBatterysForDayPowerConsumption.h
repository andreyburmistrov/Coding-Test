#ifndef CalcBatterysForDayPowerConsumption_H
#define CalcBatterysForDayPowerConsumption_H

#include <unordered_map>

class CalcBatterysForDayPowerConsumption
{
public:
	using V = float;
	using AH = float;
	using wHDay = float;

	enum class BatteryType
	{
		Lead_acid,
		Li_ion
	};

	CalcBatterysForDayPowerConsumption(
		wHDay totalPowerConsumption,
		BatteryType batteryType,
		AH batteryCapacity );

	std::size_t getBatterysCount( ) const;

private:
	static constexpr V BATTERY_VOLTAGE = 12.f;
	static inline const std::unordered_map< BatteryType, float > BATTERY_TYPE_TO_RATED_POWER_FACTOR
	{
		{ BatteryType::Lead_acid, 0.5f },
		{ BatteryType::Li_ion, 0.8f }
	};

	wHDay m_totalPowerConsumption;
	BatteryType m_batteryType;
	AH m_batteryCapacity;
};


#endif
