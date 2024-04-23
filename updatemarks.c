#include <stdio.h>
#include "functions.h"
extern struct Student students[10];
extern int student_count;

void updateMarks() {
    if (student_count == 0) {
        printf("No students added yet!\n");
        return;
    }

    int rollNo;
    printf("Enter the roll number of the student whose marks you want to update: ");
    scanf("%d", &rollNo);

    int exists = 0;
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == rollNo) {
            printf("Enter new marks for %d subjects for %d exams:\n", 3, 3);
            for (int j = 0; j < 3; j++) {
                switch (j) {
                    case 0:
                        printf("Mathematics: \n");
                        break;
                    case 1:
                        printf("Physics: \n");
                        break;
                    case 2:
                        printf("Problem Solving With C: \n");
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
                    scanf("%f", &students[i].marks[j][k]);
                    if ((k == 0 || k == 1) && (students[i].marks[j][k] < 0 || students[i].marks[j][k] > 40)) {
                        printf("Enter number from 0 to 40!\n");
                        return;
                    } else if ((k == 2) && (students[i].marks[j][k] < 0 || students[i].marks[j][k] > 100)) {
                        printf("Enter number from 0 to 100!\n");
                        return;
                    }
                }
            }

            for (int j = 0; j < 3; j++) {
                students[i].grade[j] = calculateGrade(students[i].marks[j][0], students[i].marks[j][1], students[i].marks[j][2]);
            }

            exists = 1;
            break;
        }
    }

    if (!exists) {
        printf("Student with roll number %d does not exist!\n", rollNo);
    }
}
