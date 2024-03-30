#include <stdio.h>

// Function prototypes
double l_to_m3(double l);
double m3_to_l(double m3);
double l_to_ml(double l);
double ml_to_l(double ml);
double l_to_gal(double l);
double gal_to_l(double gal);
double l_to_floz(double l);
double floz_to_l(double floz);

/* Function definitions for volume conversion */
void volumeConversion()
{
    int choice;
    double volume;

    printf("Choose a conversion:\n");
    printf("1. Liters to Cubic Meters\n");
    printf("2. Cubic Meters to Liters\n");
    printf("3. Liters to Milliliters\n");
    printf("4. Milliliters to Liters\n");
    printf("5. Liters to Gallons\n");
    printf("6. Gallons to Liters\n");
    printf("7. Liters to Fluid Ounces\n");
    printf("8. Fluid Ounces to Liters\n");
    printf("Enter your choice (1 to 8): ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter volume in liters: ");
        scanf("%lf", &volume);
        printf("%.2lf liters is equal to %.2lf cubic meters\n", volume, l_to_m3(volume));
        break;
    case 2:
        printf("Enter volume in cubic meters: ");
        scanf("%lf", &volume);
        printf("%.2lf cubic meters is equal to %.2lf liters\n", volume, m3_to_l(volume));
        break;
    case 3:
        printf("Enter volume in liters: ");
        scanf("%lf", &volume);
        printf("%.2lf liters is equal to %.2lf milliliters\n", volume, l_to_ml(volume));
        break;
    case 4:
        printf("Enter volume in milliliters: ");
        scanf("%lf", &volume);
        printf("%.2lf milliliters is equal to %.2lf liters\n", volume, ml_to_l(volume));
        break;
    case 5:
        printf("Enter volume in liters: ");
        scanf("%lf", &volume);
        printf("%.2lf liters is equal to %.2lf gallons\n", volume, l_to_gal(volume));
        break;
    case 6:
        printf("Enter volume in gallons: ");
        scanf("%lf", &volume);
        printf("%.2lf gallons is equal to %.2lf liters\n", volume, gal_to_l(volume));
        break;
    case 7:
        printf("Enter volume in liters: ");
        scanf("%lf", &volume);
        printf("%.2lf liters is equal to %.2lf fluid ounces\n", volume, l_to_floz(volume));
        break;
    case 8:
        printf("Enter volume in fluid ounces: ");
        scanf("%lf", &volume);
        printf("%.2lf fluid ounces is equal to %.2lf liters\n", volume, floz_to_l(volume));
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
}

// Function definitions
double l_to_m3(double l)
{
    return l / 1000.0;
}

double m3_to_l(double m3)
{
    return m3 * 1000.0;
}

double l_to_ml(double l)
{
    return l * 1000.0;
}

double ml_to_l(double ml)
{
    return ml / 1000.0;
}

double l_to_gal(double l)
{
    return l / 3.78541;
}
double gal_to_l(double gal)
{
    return gal * 3.78541;
}

double l_to_floz(double l)
{
    return l * 33.814;
}

double floz_to_l(double floz)
{
    return floz / 33.814;
}
