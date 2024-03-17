#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    double factor;
} Unit;

typedef struct {
    char *name;
    Unit *units;
    int num_units;
} System;

Unit *new_unit(char *name, double factor) {
    Unit *unit = (Unit *) malloc(sizeof(Unit));
    unit->name = name;
    unit->factor = factor;
    return unit;
}

System *new_system(char *name, Unit *units, int num_units) {
    System *system = (System *) malloc(sizeof(System));
    system->name = name;
    system->units = units;
    system->num_units = num_units;
    return system;
}

double convert(System *from_system, int from_unit_index, double from_value, System *to_system, int to_unit_index) {
    double from_factor = from_system->units[from_unit_index].factor;
    double to_factor = to_system->units[to_unit_index].factor;
    return from_value * from_factor / to_factor;
}

int main() {
    // Define length units
    Unit length_units[] = {
        {"meter", 1.0},
        {"kilometer", 1000.0},
        {"centimeter", 0.01},
        {"millimeter", 0.001},
        {"mile", 1609.34},
        {"yard", 0.9144},
        {"foot", 0.3048},
        {"inch", 0.0254},
    };
    System length_system = {"length", length_units, sizeof(length_units) / sizeof(Unit)};

    // Define volume units
    Unit volume_units[] = {
        {"cubic_meter", 1.0},
        {"cubic_kilometer", 1000000000.0},
        {"cubic_centimeter", 0.000001},
        {"cubic_millimeter", 0.000000001},
        {"liter", 0.001},
        {"gallon", 0.00378541},
        {"cubic_inch", 0.0000163871},
        {"cubic_foot", 0.0283168},
    };
    System volume_system = {"volume", volume_units, sizeof(volume_units) / sizeof(Unit)};

    int choice;
    double from_value, to_value;
    while (1) {
        printf("Choose a system to convert from:\n");
        printf("1. Length\n");
        printf("2. Volume\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            break;
        }

        System *from_system;
        Unit *from_units;
        int *from_unit_indices;
        double *from_factors;
        int num_units;
        switch (choice) {
            case 1:
                from_system = &length_system;
                from_units = length_units;
                from_unit_indices = (int[]) {0, 1, 2, 3, 4, 5, 6, 7};
                from_factors = (double[]) {1.0, 1000.0, 0.01, 0.001, 0.000189394, 0.9144, 0.3048, 0.0254};
                num_units = sizeof(from_unit_indices) / sizeof(int);
                break;
            case 2:
                from_system = &volume_system;
                from_units = volume_units;
                from_unit_indices = (int[]) {0, 1, 2, 3, 4, 5, 6, 7};
                from_factors = (double[]) {1.0, 1000000000.0, 0.000001, 0.000000001, 1.0, 3.78541, 0.0000163871, 0.0283168};
                num_units = sizeof(from_unit_indices) / sizeof(int);
                break;
        }

        printf("Choose a unit to convert from: ");
        int from_unit_index;
        scanf("%d", &from_unit_index);

        printf("Enter the value to convert: ");
        scanf("%lf", &from_value);

        printf("Choose a system to convert to:\n");
        printf("1. Length\n");
        printf("2. Volume\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        System *to_system;
        Unit *to_units;
        int *to_unit_indices;
        double *to_factors;
        int num_to_units;
        switch (choice) {
            case 1:
                to_system = &length_system;
                to_units = length_units;
                to_unit_indices = (int[]) {0, 1, 2, 3, 4, 5, 6, 7};
                to_factors = (double[]) {1.0, 0.001, 100.0, 1000.0, 5280.0, 3.28084, 12.0, 39.3701};
                num_to_units = sizeof(to_unit_indices) / sizeof(int);
                break;
            case 2:
                to_system = &volume_system;
                to_units = volume_units;
                to_unit_indices = (int[]) {0, 1, 2, 3, 4, 5, 6, 7};
                to_factors = (double[]) {1.0, 0.000001, 1000000.0, 1000000000.0, 0.001, 0.264172, 16.3871, 0.0610237};
                num_to_units = sizeof(to_unit_indices) / sizeof(int);
                break;
            case 3:
                return 0;
        }

        printf("Choose a unit to convert to: ");
        int to_unit_index;
        scanf("%d", &to_unit_index);

        to_value = convert(from_system, from_unit_index, from_value, to_system, to_unit_index);

        printf("Result: %lf %s = %lf %s\n", from_value, from_units[from_unit_index].name, to_value, to_units[to_unit_index].name);
        printf("Conversion factor: %lf %s = %lf %s\n", from_value * from_factors[from_unit_index], from_units[from_unit_index].name, to_value * to_factors[to_unit_index], to_units[to_unit_index].name);
    }

    return 0;
}
