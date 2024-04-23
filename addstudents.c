#include <stdio.h>
#include <string.h>
#include "functions.h"
extern struct Student students[10];
extern int student_count;
void addstudent() {
    if (student_count == MAX_STUDENTS) {
        printf("Maximum number of students reached!\n");
        return;
    }

    int rollNo;
    printf("\nEnter details for Student %d:\n", student_count + 1);
    printf("Roll Number: ");
    scanf("%d", &rollNo);

    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == rollNo) {
            printf("Student with roll number %d already exists!\n", rollNo);
            return;
        }
    }

    students[student_count].roll_no = rollNo;

    printf("Enter name: ");
    scanf(" %[^\n]", students[student_count].name);

    printf("Enter marks for %d subjects for %d exams:\n", 3, 3);
    for (int i = 0; i < 3; i++) {
        switch(i) {
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

        for (int j = 0; j < 3; j++) {
            if (j <= 1) {
                printf("ISA %d: ", j + 1);
            } else {
                printf("ESA: ");
            }
            scanf("%f", &students[student_count].marks[i][j]);

            if ((j == 0 || j == 1) && (students[student_count].marks[i][j] < 0 || students[student_count].marks[i][j] > 40)) {
                printf("Enter number from 0 to 40\n");
                return;
            } else if ((j == 2) && (students[student_count].marks[i][j] < 0 || students[student_count].marks[i][j] > 100)) {
                printf("Enter number from 0 to 100\n");
                return;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        students[student_count].grade[i] = calculateGrade(students[student_count].marks[i][0], students[student_count].marks[i][1], students[student_count].marks[i][2]);
    }

    student_count++;
}
