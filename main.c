#include <stdio.h>
#include "functions.h"

int main() {
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Display the grade card\n");
        printf("2. Add new student\n");
        printf("3. Update marks\n");
        printf("4. Clear CSV file\n");
        printf("5. Exit\n");
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
                clearCSV();
                break;
            case 5:
                printf("Exiting Program\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
