#include <stdio.h>

int main() {
    float power;
    char unit;

    // Prompting the user for power value and unit
    printf("Enter the power value: ");
    scanf("%f", &power);
    printf("Enter the unit (W for watts, kW for kilowatts, MW for megawatts, HP for horsepower): ");
    scanf(" %c", &unit);

    // Converting to other units and printing
    printf("\nEquivalent values:\n");
    switch(unit) {
        case 'W':
            printf("%.2f watts\n", power);
            printf("%.6f kilowatts\n", power / 1000);
            printf("%.9f megawatts\n", power / 1000000);
            printf("%.3f horsepower\n", power / 745.7);
            break;
        case 'k':
            printf("%.2f kilowatts\n", power);
            printf("%.0f watts\n", power * 1000);
            printf("%.6f megawatts\n", power / 1000);
            printf("%.0f horsepower\n", power / 0.7457);
            break;
        case 'M':
            printf("%.2f megawatts\n", power);
            printf("%.0f watts\n", power * 1000000);
            printf("%.3f kilowatts\n", power * 1000);
            printf("%.0f horsepower\n", power / 0.0007457);
            break;
        case 'H':
            printf("%.2f horsepower\n", power);
            printf("%.0f watts\n", power * 745.7);
            printf("%.6f kilowatts\n", power * 0.7457);
            printf("%.9f megawatts\n", power * 0.0007457);
            break;
        default:
            printf("Invalid unit entered.\n");
    }

    return 0;
}
