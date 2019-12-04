#include <iostream>
#include "CalcBatterysForDayPowerConsumption.h"
#include "CalcSolarPanelsForDayPowerConsumption.h"

static void processBatterys( std::istream& is )
{
	CalcBatterysForDayPowerConsumption::wHDay totalPowerConsumption{ };
	std::cout << "Input total power consumption ( wHDay )" << '\n';
	is >> totalPowerConsumption;

	std::cout << '\n';

	CalcBatterysForDayPowerConsumption::AH batteryCapacity{ };
	std::cout << "Input battery capacity ( AH )" << '\n';
	is >> batteryCapacity;

	std::cout << '\n';

	unsigned short numBattteryType{ };
	std::cout << "Choose your battery type:" << '\n';
	std::cout << "1. Lead acid" << '\n';
	std::cout << "2. Li-ion" << '\n';
	is >> numBattteryType;

	std::cout << '\n';

	CalcBatterysForDayPowerConsumption::BatteryType batteryType{ };

	if( numBattteryType == 1 )
		batteryType = CalcBatterysForDayPowerConsumption::BatteryType::Lead_acid;
	else if( numBattteryType == 2 )
		batteryType = CalcBatterysForDayPowerConsumption::BatteryType::Li_ion;
	else
		throw std::invalid_argument( "unknown battery type" );

	CalcBatterysForDayPowerConsumption result( totalPowerConsumption, batteryType, batteryCapacity );
	std::cout << "Num of battery's needed to cover power consumption: " << result.getBatterysCount( ) << '\n';
}


static void processSolarPanels( std::istream& is )
{
	CalcSolarPanelsForDayPowerConsumption::wHDay totalPowerConsumption{ };
	std::cout << "Input total power consumption ( wHDay )" << '\n';
	is >> totalPowerConsumption;

	unsigned short numOfSunshineHours{ };
	std::cout << "Input num of sunshine hours" << '\n';
	is >> numOfSunshineHours;

	CalcSolarPanelsForDayPowerConsumption result( totalPowerConsumption, numOfSunshineHours );
	std::cout << "Num of solar panels needed to cover power consumption: " << result.getSolarPanelsCount( ) << '\n';

	std::cout << "Square needed for placing solar panels: " << result.getNeededSquareForSolarPanels( ) << '\n';
}


static void inputData( std::istream& is )
{
	while( true )
	{
		try
		{
			unsigned short answer{ };

			std::cout << '\n' << "What do you want to calculate?" << "\n\n";
			std::cout << "1. Num of battery’s needed to cover power consumption" << '\n';
			std::cout << "2. Num and square of solar panels needed to cover power consumption" << '\n';
			std::cout << "3. Exit" << '\n';

			is >> answer;

			std::cout << '\n';

			switch( answer )
			{
				case 1:
					processBatterys( is );
					break;
				case 2:
					processSolarPanels( is );
					break;
				case 3:
					return;
				default:
					throw std::invalid_argument( "please, choose correct menu item" );
			}
		}
		catch( const std::invalid_argument& ex )
		{
			std::cerr << "Error: " << ex.what( ) << '\n';
		}
		catch( const std::exception& )
		{
			std::cerr << "Something went wrong..." << '\n';
			std::cerr << "Please, check your input and try again!" << '\n';

			is.clear( );
			is.ignore( std::numeric_limits< int >::max( ), '\n' );
		}
	}
}


int main( int argc, const char * argv[ ] )
{
	std::cout << "Hello! It's a simple solar panel calculator" << "\n\n";

	std::cin.exceptions( std::istream::failbit | std::istream::badbit );

	inputData( std::cin );

	std::cout << "Good Buy!" << '\n';

	return 0;
}
