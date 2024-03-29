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

System length_system = {"length", length_units, sizeof(length_units) / sizeof(Unit)};
System volume_system = {"volume", volume_units, sizeof(volume_units) / sizeof(Unit)};

void display_units(System *system) {
    printf("\nUnits for the %s system:\n", system->name);
    for (int i = 0; i < system->num_units; i++) {
        printf("%d. %s\n", i, system->units[i].name);
    }
    printf("Choose a unit to convert from: ");
}

double convert(System *from_system, System *to_system, int from_unit_index, double from_value, int to_unit_index) {
    double from_factor = from_system->units[from_unit_index].factor;
    double to_factor = to_system->units[to_unit_index].factor;
    return from_value * from_factor / to_factor;
}

int main() {
    double from_value, to_value;
    int choice, from_unit_index, to_unit_index;

    while (1) {
        printf("Choose a system to convert from:\n");
        printf("1. Length\n");
        printf("2. Volume\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        System *from_system, *to_system;

        switch (choice) {
            case 1:
                from_system = &length_system;
                to_system = &length_system;
                break;
            case 2:
                from_system = &volume_system;
                to_system = &volume_system;
                break;
            case 3:
                return 0;
            default:
                continue;
        }

        // Display the units for the user to choose from
        display_units(from_system);
        scanf("%d", &from_unit_index);

        printf("Enter the value to convert: ");
        scanf("%lf", &from_value);

        printf("Choose a system to convert to:\n");
        printf("1. Length\n");
        printf("2. Volume\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                to_system = &length_system;
                break;
            case 2:
                to_system = &volume_system;
              break;
            case 3:
                return 0;
            default:
                continue;
        }

        // Display the units for the user to choose to
        display_units(to_system);
        scanf("%d", &to_unit_index);

        to_value = convert(from_system, to_system, from_unit_index, from_value, to_unit_index);

        printf("Result: %lf %s = %lf %s\n", from_value, from_system->units[from_unit_index].name, to_value, to_system->units[to_unit_index].name);
    }

    return 0;
}
