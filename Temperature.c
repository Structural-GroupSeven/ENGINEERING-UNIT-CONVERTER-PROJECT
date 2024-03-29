#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Celsius to Kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Fahrenheit to Kelvin
float fahrenheit_to_kelvin(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9 + 273.15;
}

// Function to convert Kelvin to Celsius
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

// Function to convert Kelvin to Fahrenheit
float kelvin_to_fahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9 / 5 + 32;
}

int main() {
    float temperature;
    char fromUnit, toUnit;

    printf("Enter temperature value: ");
    scanf("%f", &temperature);

    printf("Enter temperature unit (C, F, K): ");
    scanf(" %c", &fromUnit);

    printf("Enter unit to convert to (C, F, K): ");
    scanf(" %c", &toUnit);

    switch (fromUnit) {
        case 'C':
        case 'c':
            switch (toUnit) {
                case 'C':
                case 'c':
                    printf("Temperature in Celsius: %.2f\n", temperature);
                    break;
                case 'F':
                case 'f':
                    printf("Temperature in Fahrenheit: %.2f\n", celsius_to_fahrenheit(temperature));
                    break;
                case 'K':
                case 'k':
                    printf("Temperature in Kelvin: %.2f\n", celsius_to_kelvin(temperature));
                    break;
                default:
                    printf("Invalid unit entered\n");
                    break;
            }
            break;
        case 'F':
        case 'f':
            switch (toUnit) {
                case 'C':
                case 'c':
                    printf("Temperature in Celsius: %.2f\n", fahrenheit_to_celsius(temperature));
                    break;
                case 'F':
                case 'f':
                    printf("Temperature in Fahrenheit: %.2f\n", temperature);
                    break;
                case 'K':
                case 'k':
                    printf("Temperature in Kelvin: %.2f\n", fahrenheit_to_kelvin(temperature));
                    break;
                default:
                    printf("Invalid unit entered\n");
                    break;
            }
            break;
        case 'K':
        case 'k':
            switch (toUnit) {
                case 'C':
                case 'c':
                    printf("Temperature in Celsius: %.2f\n", kelvin_to_celsius(temperature));
                    break;
                case 'F':
                case 'f':
                    printf("Temperature in Fahrenheit: %.2f\n", kelvin_to_fahrenheit(temperature));
                    break;
                case 'K':
                case 'k':
                    printf("Temperature in Kelvin: %.2f\n", temperature);
                    break;
                default:
                    printf("Invalid unit entered\n");
                    break;
            }
            break;
        default:
            printf("Invalid unit entered\n");
            break;
    }

    return 0;
}
