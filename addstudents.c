#include <stdio.h>
#include <string.h>
#include "functions.h"

void addstudent() {
    int roll_no;
    char name[50];
    float marks[3][3];

    printf("Enter Roll Number: ");
    scanf("%d", &roll_no);

    FILE *file = fopen("Data.csv", "r");
    char line[256];
    while (file && fgets(line, sizeof(line), file)) {
        int existing_roll_no;
        sscanf(line, "%d,", &existing_roll_no);
        if (existing_roll_no == roll_no) {
            printf("Student with roll number %d already exists!\n", roll_no);
            fclose(file);
            return;
        }
    }
    if (file) fclose(file);

    printf("Enter name: ");
    scanf(" %[^\n]", name);

    printf("Enter marks for 3 subjects for 3 exams:\n");
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

    file = fopen("Data.csv", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "%d,%s", roll_no, name);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            fprintf(file, ",%.2f", marks[i][j]);
        }
    }
    fprintf(file, "\n");
    fclose(file);
}
