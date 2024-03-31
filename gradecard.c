#include<stdio.h>
#include<string.h>
#include "functions.h"

extern int roll_nos[MAX_STUDENTS];
extern char names[MAX_STUDENTS][50];
extern float marks[MAX_STUDENTS][MAX_SUBJECTS][MAX_EXAMS];
extern char grades[MAX_STUDENTS][MAX_SUBJECTS];

extern int student_count;
extern int rollNo;



void GradeCard() {
    if (student_count == 0) {
        printf("No students added!\n");
        return;
    } else {
        printf("\n                  Grade Card:                   \n");
        for (int i = 0; i <= 50; i++) {
            printf("-");
        }

        for (int i = 0; i < student_count; i++) {
            printf("\nStudent %d\n", i + 1);
            printf("Roll Number: %d\n", roll_nos[i]);
            printf("Name: %s\n", names[i]);
            printf("Marks:\n");
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                switch (j) {
                    case 0:
                        printf("Mathematics : \n");
                        printf("Grade : %c", grades[i][j]);
                        break;
                    case 1:
                        printf("Physics : \n");
                        printf("Grade : %c", grades[i][j]);
                        break;
                    case 2:
                        printf("Problem Solving With C : \n");
                        printf("Grade : %c", grades[i][j]);
                        break;
                }

                for (int k = 0; k < MAX_EXAMS; k++) {
                    switch (k) {
                        case 0:
                            printf(" ISA 1: ");
                            break;
                        case 1:
                            printf(" ISA 2 : ");
                            break;
                        case 2:
                            printf(" ESA : ");
                            break;
                    }
                    printf("%.2f ", marks[i][j][k]);
                }
                printf("\n");
            }
            printf("\n");
        }
    }
}