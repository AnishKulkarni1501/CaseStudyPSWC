#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_STUDENTS 5
#define MAX_NAME_LENGTH 50

struct Student {
    int roll_no;
    char name[MAX_NAME_LENGTH];
    float marks[3][3];
    char grade[3];
};
void GradeCard();
void addstudent();
void updateMarks();
char calculateGrade(float isa1, float isa2, float esa);

#endif 

