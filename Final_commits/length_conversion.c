#include <stdio.h>

// Function prototypes
double km_to_m(double km);
double m_to_km(double m);
double km_to_cm(double km);
double cm_to_km(double cm);
double km_to_mm(double km);
double mm_to_km(double mm);
double km_to_mi(double km);
double mi_to_km(double mi);
double km_to_ft(double km);
double ft_to_km(double ft);
double km_to_in(double km);
double in_to_km(double in);

/* Function definitions for length conversion */
void lengthConversion()
{
    int choice;
    double length;

    printf("Choose a conversion:\n");
    printf("1. Kilometers to Meters\n");
    printf("2. Meters to Kilometers\n");
    printf("3. Kilometers to Centimeters\n");
    printf("4. Centimeters to Kilometers\n");
    printf("5. Kilometers to Millimeters\n");
    printf("6. Millimeters to Kilometers\n");
    printf("7. Kilometers to Miles\n");
    printf("8. Miles to Kilometers\n");
    printf("9. Kilometers to Feet\n");
    printf("10. Feet to Kilometers\n");
    printf("11. Kilometers to Inches\n");
    printf("12. Inches to Kilometers\n");
    printf("Enter your choice (1 to 12): ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter length in kilometers: ");
        scanf("%lf", &length);
        printf("%.2lf kilometers is equal to %.2lf meters\n", length, km_to_m(length));
        break;
    case 2:
        printf("Enter length in meters: ");
        scanf("%lf", &length);
        printf("%.2lf meters is equal to %.2lf kilometers\n", length, m_to_km(length));
        break;
    case 3:
        printf("Enter length in kilometers: ");
        scanf("%lf", &length);
        printf("%.2lf kilometers is equal to %.2lf centimeters\n", length, km_to_cm(length));
        break;
    case 4:
        printf("Enter length in centimeters: ");
        scanf("%lf", &length);
        printf("%.2lf centimeters is equal to %.2lf kilometers\n", length, cm_to_km(length));
        break;
    case 5:
        printf("Enter length in kilometers: ");
        scanf("%lf", &length);
        printf("%.2lf kilometers is equal to %.2lf millimeters\n", length, km_to_mm(length));
        break;
    case 6:
        printf("Enter length in millimeters: ");
        scanf("%lf", &length);
        printf("%.2lf millimeters is equal to %.2lf kilometers\n", length, mm_to_km(length));
        break;
    case 7:
        printf("Enter length in kilometers: ");
        scanf("%lf", &length);
        printf("%.2lf kilometers is equal to %.2lf miles\n", length, km_to_mi(length));
        break;
    case 8:
        printf("Enter length in miles: ");
        scanf("%lf", &length);
        printf("%.2lf miles is equal to %.2lf kilometers\n", length, mi_to_km(length));
        break;
    case 9:
        printf("Enter length in kilometers: ");
        scanf("%lf", &length);
        printf("%.2lf kilometers is equal to %.2lf feet\n", length, km_to_ft(length));
        break;
    case 10:
        printf("Enter length in feet: ");
        scanf("%lf", &length);
        printf("%.2lf feet is equal to %.2lf kilometers\n", length, ft_to_km(length));
        break;
    case 11:
        printf("Enter length in kilometers: ");
        scanf("%lf", &length);
        printf("%.2lf kilometers is equal to %.2lf inches\n", length, km_to_in(length));
        break;
    case 12:
        printf("Enter length in inches: ");
        scanf("%lf", &length);
        printf("%.2lf inches is equal to %.2lf kilometers\n", length, in_to_km(length));
        break;
    default:
        printf("Invalid choice\n");
    }
}

// Function definitions
double km_to_m(double km)
{
    return km * 1000.0;
}

double m_to_km(double m)
{
    return m / 1000.0;
}

double km_to_cm(double km)
{
    return km * 100000.0;
}

double cm_to_km(double cm)
{
    return cm / 100000.0;
}

double km_to_mm(double km)
{
    return km * 1000000.0;
}

double mm_to_km(double mm)
{
    return mm / 1000000.0;
}

double km_to_mi(double km)
{
    return km / 1.60934;
}

double mi_to_km(double mi)
{
    return mi * 1.60934;
}

double km_to_ft(double km)
{
    return km * 3280.84;
}

double ft_to_km(double ft)
{
    return ft / 3280.84;
}

double km_to_in(double km)
{
    return km * 39370.1;
}

double in_to_km(double in)
{
    return in / 39370.1;
}
