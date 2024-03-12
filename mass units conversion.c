#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double factor;
} Unit;

Unit *add_unit(Unit *units, int *num_units, char *name, double factor) {
    Unit *new_units = realloc(units, sizeof(Unit) * (*num_units + 1));
    if (new_units == NULL) {
        return NULL;
    }
    units = new_units;
    units[*num_units].name = name;
    units[*num_units].factor = factor;
    (*num_units)++;
    return units;
}

int find_unit(Unit *units, int num_units, char *name) {
    for (int i = 0; i < num_units; i++) {
        if (strcmp(name, units[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int num_units = 0;
    Unit *units = NULL;

    // Add supported units here
    units = add_unit(units, &num_units, "kilogram", 1.0);
    units = add_unit(units, &num_units, "gram", 1000.0);
    units = add_unit(units, &num_units, "tonne", 1000000.0);
    units = add_unit(units, &num_units, "milligram", 0.001);
    units = add_unit(units, &num_units, "megatonne", 1000000000.0);
    units = add_unit(units, &num_units, "microgram", 1000000000000.0);

    char input[100], output[100];
    double value, factor;

    while (1) {
        printf("Enter the unit to convert from: ");
        scanf("%s", input);

        int from_unit_index = find_unit(units, num_units, input);
        if (from_unit_index == -1) {
            printf("Unit not supported. Please add the unit to the program.\n");
            continue;
        }

        printf("Enter the value to convert: ");
        scanf("%lf", &value);

        printf("Enter the unit to convert to: ");
        scanf("%s", output);

        int to_unit_index = find_unit(units, num_units, output);
        if (to_unit_index == -1) {
            printf("Unit not supported. Please add the unit to the program.\n");
            continue;

        }

        factor = units[from_unit_index].factor / units[to_unit_index].factor;
        printf("%.2f %s = %.2f %s\n", value, units[from_unit_index].name, value * factor, units[to_unit_index].name);
    }
    return 0;
 }
