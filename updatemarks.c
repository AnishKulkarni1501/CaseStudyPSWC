#include<stdio.h>
#include "functions.h"

extern int roll_nos[MAX_STUDENTS];
extern char names[MAX_STUDENTS][50];
extern float marks[MAX_STUDENTS][MAX_SUBJECTS][MAX_EXAMS];
extern char grades[MAX_STUDENTS][MAX_SUBJECTS];
extern int student_count ;
extern int rollNo;



void updateMarks() {
    if (student_count == 0) {
        printf("No students added yet!\n");
        return;
    }

    printf("Enter the roll number of the student whose marks you want to update: ");
    scanf("%d", &rollNo);

    int exists = 0;
    for (int i = 0; i < student_count; i++) {
        if (roll_nos[i] == rollNo) {
            printf("Enter new marks for %d subjects for %d exams:\n", MAX_SUBJECTS, MAX_EXAMS);
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                switch (j) {
                    case 0:
                        printf("Mathematics : \n");
                        break;
                    case 1:
                        printf("Physics : \n");
                        break;
                    case 2:
                        printf("Problem Solving With C : \n");
                        break;
                }
                for (int k = 0; k < MAX_EXAMS; k++) {
                    switch (k) {
                        case 0:
                            printf("ISA 1 : ");
                            break;
                        case 1:
                            printf("ISA 2 : ");
                            break;
                        case 2:
                            printf("ESA : ");
                            break;
                    }
                    scanf("%f", &marks[i][j][k]);
                    if ((k == 0 || k == 1) && (marks[i][j][k] < 0 || marks[i][j][k] > 40)) {
                        printf("Enter number from 0 to 40!\n");
                        return;
                    } else if ((k == 2) && (marks[i][j][k] < 0 || marks[i][j][k] > 100)) {
                        printf("Enter number from 0 to 100!\n");
                        return;
                    }
                }

                
                grades[i][j] = calculateGrade(marks[i][j][0], marks[i][j][1], marks[i][j][2]);
            }

            exists = 1;
            break;
        }
    }

    if (!exists) {
        printf("Student with roll number %d does not exist!\n", rollNo);
    }
}