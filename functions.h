#define MAX_STUDENTS 10
#define MAX_SUBJECTS 3
#define MAX_EXAMS 3


#ifdef _MAIN_
void GradeCard();
void addstudent();
void updateMarks();
char calculateGrade(float isa1, float isa2, float esa);
#else 
extern void GradeCard();
extern void addstudent();
extern void updateMarks();
extern char calculateGrade(float isa1, float isa2, float esa);
#endif
