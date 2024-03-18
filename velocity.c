#include <stdio.h>

// Function prototypes
float meters_per_second_to_kilometers_per_hour(float mps);
float kilometers_per_hour_to_meters_per_second(float kph);
float meters_per_second_to_miles_per_hour(float mps);
float miles_per_hour_to_meters_per_second(float mph);

int main() {
    float velocity_mps, velocity_kph, velocity_mph;

    printf("Enter velocity in meters per second: ");
    scanf("%f", &velocity_mps);

    velocity_kph = meters_per_second_to_kilometers_per_hour(velocity_mps);
    velocity_mph = meters_per_second_to_miles_per_hour(velocity_mps);

    printf("%.2f meters per second is equal to %.2f kilometers per hour.\n", velocity_mps, velocity_kph);
    printf("%.2f meters per second is equal to %.2f miles per hour.\n", velocity_mps, velocity_mph);

    printf("\nEnter velocity in kilometers per hour: ");
    scanf("%f", &velocity_kph);

    velocity_mps = kilometers_per_hour_to_meters_per_second(velocity_kph);
    velocity_mph = kilometers_per_hour_to_miles_per_hour(velocity_kph);

    printf("%.2f kilometers per hour is equal to %.2f meters per second.\n", velocity_kph, velocity_mps);
    printf("%.2f kilometers per hour is equal to %.2f miles per hour.\n", velocity_kph, velocity_mph);

    printf("\nEnter velocity in miles per hour: ");
    scanf("%f", &velocity_mph);

    velocity_mps = miles_per_hour_to_meters_per_second(velocity_mph);
    velocity_kph = miles_per_hour_to_kilometers_per_hour(velocity_mph);

    printf("%.2f miles per hour is equal to %.2f meters per second.\n", velocity_mph, velocity_mps);
    printf("%.2f miles per hour is equal to %.2f kilometers per hour.\n", velocity_mph, velocity_kph);

    return 0;
}

// Function definitions
float meters_per_second_to_kilometers_per_hour(float mps) {
    return mps * 3.6;
}

float kilometers_per_hour_to_meters_per_second(float kph) {
    return kph / 3.6;
}

float meters_per_second_to_miles_per_hour(float mps) {
    return mps * 2.23694;
}

float miles_per_hour_to_meters_per_second(float mph) {
    return mph / 2.23694;
}
