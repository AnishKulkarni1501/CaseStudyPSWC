#include <stdio.h>
#include "functions.h"

void GradeCard() {
    FILE *file = fopen("Data.csv", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char line[256];
    int student_count = 0;

    printf("\n        Grade Card:        \n");
    for (int i = 0; i <= 30; i++) {
        printf("-");
    }
    printf("\n");

    while (fgets(line, sizeof(line), file)) {
        student_count++;
        int roll_no;
        char name[50];
        float marks[3][3];
        sscanf(line, "%d,%49[^,],%f,%f,%f,%f,%f,%f,%f,%f,%f", &roll_no, name, 
               &marks[0][0], &marks[0][1], &marks[0][2],
               &marks[1][0], &marks[1][1], &marks[1][2],
               &marks[2][0], &marks[2][1], &marks[2][2]);

        char grade1 = calculateGrade(marks[0][0], marks[0][1], marks[0][2]);
        char grade2 = calculateGrade(marks[1][0], marks[1][1], marks[1][2]);
        char grade3 = calculateGrade(marks[2][0], marks[2][1], marks[2][2]);

        printf("\nStudent:\n");
        printf("Roll Number: %d\n", roll_no);
        printf("Name: %s\n", name);
        printf("Mathematics: Grade %c\n", grade1);
        printf("Physics: Grade %c\n", grade2);
        printf("Problem Solving With C: Grade %c\n", grade3);

        for (int j = 0; j < 3; j++) {
            switch(j){
                case 0: printf("Mathematics: "); break;
                case 1: printf("Physics: "); break;
                case 2: printf("Problem Solving With C: "); break;
            }
            for (int k = 0; k < 3; k++) {
                switch(k){
                    case 0: printf("ISA 1: "); break;
                    case 1: printf("ISA 2: "); break;
                    case 2: printf("ESA: "); break;
                }
                printf("%.2f ", marks[j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    if (student_count == 0) {
        printf("No students added!\n");
    }

    fclose(file);
}
