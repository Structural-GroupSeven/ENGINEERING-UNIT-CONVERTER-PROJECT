#include <stdio.h>

/*Function to convert energy*/ 
double convertEnergy(double value, double conversionFactor) {
    return value * conversionFactor;
}
/*Function to display menu*/ 
void displayMenu() {
    printf("Energy Conversion Menu:\n");
    printf("1. Joule (J)\n");
    printf("2. Kilojoule (kJ)\n");
    printf("3. Calorie (cal)\n");
    printf("4. Kilocalorie (kcal)\n");
    printf("5. Electronvolt (eV)\n");
    printf("6. British Thermal Unit (BTU)\n");
    printf("7. Foot-pound (ft-lb)\n");
}

int main() {
    double value, result;
    int fromIndex, toIndex;
    double conversionFactors[7][7] = {
        /*Conversion factors for energy units*/ 
        /*row: fromUnit, column: toUnit*/ 
        {1, 0.001, 0.239006, 0.000239006, 6.242e+18, 0.000947817, 0.737562},        /*From Joule*/ 
        {1000, 1, 239.006, 0.239006, 6.242e+21, 0.947817, 737.562},                  /*From Kilojoule*/ 
        {4.184, 0.004184, 1, 0.001, 2.611e+19, 0.00396567, 3.08802},                 /* From Calorie*/
        {4184, 4.184, 1000, 1, 2.611e+22, 3.96567, 3088.02},                         /*From Kilocalorie*/ 
        {1.602e-19, 1.602e-22, 3.8267e-20, 3.8267e-23, 1, 1.51857e-17, 1.18171e-16}, /*From Electronvolt*/ 
        {1055.06, 1.05506, 252.164, 0.252164, 6.585e+19, 1, 778.169},                /*From British Thermal Unit*/ 
        {1355.82, 1.35582, 324.048, 0.324048, 8.462e+19, 1.28507, 1}                 /*From Foot-pound*/ 
    };

   /*Display menu*/ 
    displayMenu();
    
    printf("Enter Energy value you want to convert: ");
    scanf("%lf", &value);
   
    printf("Select the Energy unit you want to convert from(1-7): ");
    scanf("%d", &fromIndex);
    
    printf("Select the Energy unit you want to convert to(1-7): ");
    scanf("%d", &toIndex);

     /*Validating the user input*/
    if (fromIndex < 1 || fromIndex > 7 || toIndex < 1 || toIndex > 7) {
        printf("Please select from the listed conversion units.\n");
        return 1;
    }

    /*Array indexing*/ 
    fromIndex--;
    toIndex--;
    /*Convert units*/ 
    result = convertEnergy(value, conversionFactors[fromIndex][toIndex]);

    printf("Result: %.6f\n", result);

    return 0;
}
