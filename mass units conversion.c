#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    double factor;
} Unit;

Unit *add_unit(Unit *units, int *num_units, char *name, double factor)
{
    Unit *new_units = realloc(units, sizeof(Unit) * (*num_units + 1));
    if (new_units == NULL)
    {
        return NULL;
    }
    units = new_units;
    units[*num_units].name = name;
    units[*num_units].factor = factor;
    (*num_units)++;
    return units;
}

int find_unit(Unit *units, int num_units, char *name)
{
    for (int i = 0; i < num_units; i++)
    {
        if (strcmp(name, units[i].name) == 0)
        {
            return i;
        }
    }
    return -1;
}

void display_menu(Unit *units, int num_units)
{
    printf("Conversion Options:\n");
    for (int i = 0; i < num_units; i++)
    {
        printf("%d. %s\n", i + 1, units[i].name);
    }
}

int main()
{
    int num_units = 0;
    Unit *units = NULL;

    // Add supported units here
    units = add_unit(units, &num_units, "kilogram", 1.0);
    units = add_unit(units, &num_units, "gram", 0.001);
    units = add_unit(units, &num_units, "tonne", 1000.0);
    units = add_unit(units, &num_units, "milligram", 0.000001);
    units = add_unit(units, &num_units, "megatonne", 1000000.0);
    units = add_unit(units, &num_units, "microgram", 0.000000001);

    char input[100], output[100];
    double value, factor;

    display_menu(units, num_units);

    while (1)
    {
        printf("Enter the unit to convert from (by numeric): ");
        scanf("%s", input);

        int from_unit_index = atoi(input) - 1;
        if (from_unit_index < 0 || from_unit_index >= num_units)
        {
            printf("Invalid unit selection.\n");
            continue;
        }

        printf("Enter the value to convert: ");
        scanf("%lf", &value);

        printf("Enter the unit to convert to (by numeric): ");
        scanf("%s", output);

        int to_unit_index = atoi(output) - 1;
        if (to_unit_index < 0 || to_unit_index >= num_units)
        {
            printf("Invalid unit selection.\n");
            continue;
        }

        factor = units[from_unit_index].factor / units[to_unit_index].factor;
        printf("%.2f %s = %.2f %s\n", value, units[from_unit_index].name, value * factor, units[to_unit_index].name);

        // Exit the loop after printing the conversion
        break;
    }
    return 0;
}

     
