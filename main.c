#include <stdio.h>
#include <string.h>
#include "functions.h"
#define _MAIN_
int roll_nos[MAX_STUDENTS];
char names[MAX_STUDENTS][50];
float marks[MAX_STUDENTS][MAX_SUBJECTS][MAX_EXAMS];
char grades[MAX_STUDENTS][MAX_SUBJECTS];

 int student_count = 0;
 int rollNo;



int main() {
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Display the grade card\n");
        printf("2. Add new student\n");
        printf("3. Update marks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                GradeCard();
                break;
            case 2:
                addstudent();
                break;
            case 3:
                updateMarks();
                break;
            case 4:
                printf("Exiting Program\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
