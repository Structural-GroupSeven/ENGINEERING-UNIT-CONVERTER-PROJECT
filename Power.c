#include <stdio.h>

int main() {
    float power;
    char from_unit, to_unit;

    // Prompting the user for power value and units
    printf("Enter the power value: ");
    scanf("%f", &power);
    printf("Enter the unit of the power value (W for watts, kW for kilowatts, MW for megawatts, HP for horsepower): ");
    scanf(" %c", &from_unit);
    printf("Enter the unit to convert to (W, kW, MW, HP): ");
    scanf(" %c", &to_unit);

    // Converting to the selected unit and printing the result
    printf("\nConverted value: ");
    switch(from_unit) {
        case 'W':
            if (to_unit == 'W')
                printf("%.2f watts\n", power);
            else if (to_unit == 'k')
                printf("%.6f kilowatts\n", power / 1000);
            else if (to_unit == 'M')
                printf("%.9f megawatts\n", power / 1000000);
            else if (to_unit == 'H')
                printf("%.6f horsepower\n", power * 0.00134102);
            else
                printf("Invalid unit entered.\n");
            break;
        case 'k':
            if (to_unit == 'W')
                printf("%.0f watts\n", power * 1000);
            else if (to_unit == 'k')
                printf("%.2f kilowatts\n", power);
            else if (to_unit == 'M')
                printf("%.6f megawatts\n", power / 1000);
            else if (to_unit == 'H')
                printf("%.0f horsepower\n", power * 1.34102);
            else
                printf("Invalid unit entered.\n");
            break;
        case 'M':
            if (to_unit == 'W')
                printf("%.0f watts\n", power * 1000000);
            else if (to_unit == 'k')
                printf("%.3f kilowatts\n", power * 1000);
            else if (to_unit == 'M')
                printf("%.2f megawatts\n", power);
            else if (to_unit == 'H')
                printf("%.0f horsepower\n", power * 1341.02);
            else
                printf("Invalid unit entered.\n");
            break;
        case 'H':
            if (to_unit == 'W')
                printf("%.0f watts\n", power * 745.7);
            else if (to_unit == 'k')
                printf("%.6f kilowatts\n", power * 0.7457);
            else if (to_unit == 'M')
                printf("%.9f megawatts\n", power * 0.0007457);
            else if (to_unit == 'H')
                printf("%.2f horsepower\n", power);
            else
                printf("Invalid unit entered.\n");
            break;
        default:
            printf("Invalid unit entered.\n");
    }

    return 0;
}
