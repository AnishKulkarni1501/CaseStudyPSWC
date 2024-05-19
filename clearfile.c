#include <stdio.h>
#include "functions.h"

void clearCSV() {
    FILE *file = fopen("Data.csv", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fclose(file);
    printf("CSV file cleared successfully.\n");
}
