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
    int from_unit_index, to_unit_index;

    System *from_system = &volume_system;
    System *to_system = &volume_system;

    // Display the units for the user to choose from
    display_units(from_system);
    scanf("%d", &from_unit_index);

    printf("Enter the value to convert: ");
    scanf("%lf", &from_value);

    // Display the units for the user to choose to
    display_units(to_system);
    scanf("%d", &to_unit_index);

    to_value = convert(from_system, to_system, from_unit_index, from_value, to_unit_index);

    printf("Result: %lf %s = %lf %s\n", from_value, from_system->units[from_unit_index].name, to_value, to_system->units[to_unit_index].name);

    return 0;
}
