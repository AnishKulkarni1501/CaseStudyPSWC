#include<stdio.h>
#include<string.h>
#include "functions.h"


int roll_nos[MAX_STUDENTS];
char names[MAX_STUDENTS][50];
float marks[MAX_STUDENTS][MAX_SUBJECTS][MAX_EXAMS];
char grades[MAX_STUDENTS][MAX_SUBJECTS];

extern int student_count;
extern int rollNo;


//char calculateGrade();
void addstudent() {
    if (student_count == MAX_STUDENTS) {
        printf("Maximum number of students reached!\n");
        return;
    }

    printf("\nEnter details for Student %d:\n", student_count + 1);
    printf("Roll Number: ");
    scanf("%d", &rollNo);

    for (int i = 0; i < student_count; i++) {
        if (roll_nos[i] == rollNo) {
            printf("Student with roll number %d already exists!\n", rollNo);
            return;
        }
    }

    roll_nos[student_count] = rollNo;

    
    printf("Enter name: ");
     scanf(" %[^\n]", names[student_count]);
    names[student_count][strlen(names[student_count])] = '\0';

    printf("Enter marks for %d subjects for %d exams:\n", MAX_SUBJECTS, MAX_EXAMS);
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        switch (i) {
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

        for (int j = 0; j < MAX_EXAMS; j++) {
            if (j <= 1) {
                printf("ISA %d: ", j + 1);
            } else {
                printf("ESA : ");
            }
            scanf("%f", &marks[student_count][i][j]);

            if ((j == 0 || j == 1) && (marks[student_count][i][j] < 0 || marks[student_count][i][j] > 40)) {
                printf("Enter number from 0 to 40\n");
                return;
            } else if ((j == 2) && (marks[student_count][i][j] < 0 || marks[student_count][i][j] > 100)) {
                printf("Enter number from 0 to 100\n");
                return;
            }
        }

        
        grades[student_count][i] = calculateGrade(marks[student_count][i][0], marks[student_count][i][1],
                                                  marks[student_count][i][2]);
    }

    student_count++;
}