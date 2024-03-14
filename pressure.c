#include <stdio.h>

/*Function to convert pressure*/ 
double convertPressure(double value, double conversionFactor) {
    return value * conversionFactor;
}

/*Function to display menu*/ 
void displayMenu() {
    printf("Pressure Conversion Menu:\n");
    printf("1. Pascal (Pa)\n");
    printf("2. Kilopascal (kPa)\n");
    printf("3. Megapascal (MPa)\n");
    printf("4. Bar (bar)\n");
    printf("5. Atmosphere (atm)\n");
    printf("6. Psi (Pound per square inch)\n");
}

int main() {
    double value, result;
    int fromIndex, toIndex;
    double conversionFactors[6][6] = {
        /*Conversion factors for pressure units*/ 
        /*row: fromUnit, column: toUnit*/ 
        {1, 0.001, 0.000001, 0.00001, 0.00000986923, 0.000145038},     /*From Pascal*/
        {1000, 1, 0.001, 0.01, 0.00986923, 0.145038},                   /*From Kilopascal*/
        {1000000, 1000, 1, 10, 9.86923, 145.038},                       /*From Megapascal*/
        {100000, 100, 0.1, 1, 0.986923, 14.5038},                       /*From Bar*/
        {101325, 101.325, 0.101325, 1.01325, 1, 14.6959},               /*From Atmosphere*/
        {6894.76, 6.89476, 0.00689476, 0.0689476, 0.0680459639, 1}     /* From Psi*/
    };

    /*Display menu*/ 
    displayMenu();

    printf("Enter value of pressure you want to convert: ");
    scanf("%lf", &value);
    
    printf("Select the Pressure unit you want to convert FROM (1-6): ");
    scanf("%d", &fromIndex);
    /*Validating the user input*/ 
    if (fromIndex < 1 || fromIndex > 6 || toIndex < 1 || toIndex > 6) {
        printf("Please select from the listed conversion units.\n");
        return 1;
    }
     printf("Select the pressure unit you want to convert TO (1-6): ");
    scanf("%d", &toIndex);

    /*Validating the user input*/ 
    if (fromIndex < 1 || fromIndex > 6 || toIndex < 1 || toIndex > 6) {
        printf("Please select from the listed conversion units.\n");
        return 1;
    }

    /*Array indexing*/
    fromIndex--;
    toIndex--;

    /*conversion of units */ 
    result = convertPressure(value, conversionFactors[fromIndex][toIndex]);

    printf("Result: %.6f\n", result);

    return 0;
}
