#include <stdio.h>
#include "energy_conversion.h"
#include "pressure_conversion.h"
#include "area_conversion.h"
#include "velocity_conversion.h"
#include "volume_conversion.h"
#include "temperature_conversion.h"
#include "mass_conversion.h"
#include "length_conversion.h"
#include "power_conversion.h"

int main()
{
    int choice;

    printf("Select conversion type:\n");
    printf("1. Pressure Conversion\n");
    printf("2. Energy Conversion\n");
    printf("3. Velocity Conversion\n");
    printf("4. Area Conversion\n");
    printf("5. Volume Conversion\n");
    printf("6. Length Conversion\n");
    printf("7. Temperature Conversion\n");
    printf("8. Mass Conversion\n");
    printf("9. Power Conversion\n");
    printf("\n Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        pressureConversion();
        break;
    case 2:
        energyConversion();
        break;
    case 3:
        velocityConversion();
        break;
    case 4:
        areaConversion();
        break;
    case 5:
        volumeConversion();
        break;
    case 6:
        lengthConversion();
        break;
    case 7:
        temperatureConversion();
        break;
    case 8:
        massConversion();
        break;
    case 9:
        powerConversion();
        break;
    default:
        printf("\nPlease select from the above list.\n");
        break;
    }

    return 0;
}
