#include <stdio.h>
#include "velocity_conversion.h"

// Functions
float mph_to_kph(float mph);
float kph_to_mph(float kph);
float mph_to_mps(float mph);
float kph_to_mps(float kph);
float mps_to_kph(float mps);
float mps_to_mph(float mps);

/* Function to perform velocity conversion */
void velocityConversion()
{
    int choice;
    double velocity;

    printf("Choose a conversion:\n");
    printf("1. Miles per hour to Kilometers per hour\n");
    printf("2. Kilometers per hour to Miles per hour\n");
    printf("3. Kilometers per hour to meters per second\n");
    printf("4. Miles per hour to meters per second\n");
    printf("5. Meters per second to Miles per hour\n");
    printf("6. Meters per second to Kilometers per hour\n");
    printf("Enter your choice (1 to 6): ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter velocity in miles per hour: ");
        scanf("%lf", &velocity);
        printf("%.2lf miles per hour is equal to %.2lf kilometers per hour\n", velocity, mph_to_kph(velocity));
        break;
    case 2:
        printf("Enter velocity in kilometers per hour: ");
        scanf("%lf", &velocity);
        printf("%.2lf kilometers per hour is equal to %.2lf miles per hour\n", velocity, kph_to_mph(velocity));
        break;
    case 3:
        printf("Enter velocity in kilometers per hour: ");
        scanf("%lf", &velocity);
        printf("%.2lf kilometers per hour is equal to %.2lf meters per second\n", velocity, kph_to_mps(velocity));
        break;
    case 4:
        printf("Enter velocity in miles per hour: ");
        scanf("%lf", &velocity);
        printf("%.2lf miles per hour is equal to %.2lf meters per second\n", velocity, mph_to_mps(velocity));
        break;
    case 5:
        printf("Enter velocity in meters per second: ");
        scanf("%lf", &velocity);
        printf("%.2lf meters per second is equal to %.2lf miles per hour\n", velocity, mps_to_mph(velocity));
        break;
    case 6:
        printf("Enter velocity in meters per second: ");
        scanf("%lf", &velocity);
        printf("%.2lf meters per second is equal to %.2lf kilometers per hour\n", velocity, mps_to_kph(velocity));
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
}

// Function definitions
float mps_to_kph(float mps)
{
    return mps * 3.6;
}

float kph_to_mps(float kph)
{
    return kph / 3.6;
}

float mps_to_mph(float mps)
{
    return mps * 2.23694;
}

float mph_to_mps(float mph)
{
    return mph / 2.23694;
}
float mph_to_kph(float mph)
{
    return mph * 1.60934;
}
float kph_to_mph(float kph)
{
    return kph / 1.60934;
}