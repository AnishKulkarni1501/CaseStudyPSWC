#include <stdio.h>
#include "functions.h"
extern struct Student students[10];
extern int student_count;
void GradeCard() {
    if (student_count == 0) {
        printf("No students added!\n");
        return;
    } else {
        printf("\n        Grade Card        \n");
        printf("-------------------------\n");

        for (int i = 0; i < student_count; i++) {
            printf("\nStudent %d\n", i + 1);
            printf("Roll Number: %d\n", students[i].roll_no);
            printf("Name: %s\n", students[i].name);
            printf("Marks:\n");

            for (int j = 0; j < 3; j++) {
                switch (j) {
                    case 0:
                        printf("Mathematics:\n");
                        break;
                    case 1:
                        printf("Physics:\n");
                        break;
                    case 2:
                        printf("Problem Solving With C:\n");
                        break;
                }

                for (int k = 0; k < 3; k++) {
                    switch (k) {
                        case 0:
                            printf("ISA 1: ");
                            break;
                        case 1:
                            printf("ISA 2: ");
                            break;
                        case 2:
                            printf("ESA: ");
                            break;
                    }
                    printf("%.2f ", students[i].marks[j][k]);
                }
                printf("\nGrade: %c\n", students[i].grade[j]);
            }
            printf("-------------------------\n");
        }
    }
}
