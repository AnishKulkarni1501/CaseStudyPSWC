#include <stdio.h>
#include <string.h>
#include "functions.h"

void updateMarks() {
    int roll_no;
    FILE *file;
    char line[256], data[1000] = "";
    int found = 0;

    printf("Enter the roll number of the student whose marks you want to update: ");
    scanf("%d", &roll_no);

    file = fopen("Data.csv", "r");
    if (file == NULL) {
        printf("No students added!\n");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        int curr_roll_no;
        sscanf(line, "%d,", &curr_roll_no);

        if (curr_roll_no == roll_no) {
            found = 1;
            char name[50];
            float marks[3][3];

            printf("Enter new marks for 3 subjects for 3 exams:\n");
            for (int i = 0; i < 3; i++) {
                switch(i){
                    case 0: printf("Mathematics:\n"); break;
                    case 1: printf("Physics:\n"); break;
                    case 2: printf("Problem Solving With C:\n"); break;
                }
                for (int j = 0; j < 3; j++) {
                    if (j <= 1) {
                        printf("ISA %d: ", j + 1);
                    } else {
                        printf("ESA: ");
                    }
                    scanf("%f", &marks[i][j]);
                    while ((j <= 1 && (marks[i][j] < 0 || marks[i][j] > 40)) || (j == 2 && (marks[i][j] < 0 || marks[i][j] > 100))) {
                        printf("Invalid mark! Enter again: ");
                        scanf("%f", &marks[i][j]);
                    }
                }
            }

            sscanf(line, "%d,%49[^,]", &curr_roll_no, name);
            sprintf(line, "%d,%s", curr_roll_no, name);
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char temp[10];
                    sprintf(temp, ",%.2f", marks[i][j]);
                    strcat(line, temp);
                }
            }
            strcat(line, "\n");
        }
        strcat(data, line);
    }

    fclose(file);

    if (!found) {
        printf("Student with roll number %d not found!\n", roll_no);
        return;
    }

    file = fopen("Data.csv", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fputs(data, file);
    fclose(file);
}
