DOCUMENTATION:
C Case study:

Note : This repo has been updated to store the student info in a CSV file called "Data.csv"

[NEW FUNCTION] clearfile.c : This simply just clears the csv file

To create a grade card based of user input with a menu
Menu contains 5 options : To display grade card , Add a new student , Update a student's marks,Clear CSV File and to exit the program
There are 6 C files main.c ,clearfile.c, calculategrade.c , gradecard.c , updatemarks.c and addstudents.c as well as one C header file called fucntions.h

main.c :
Contains the Menu options as well as the main function of the C file.

addstudents.c:
Used to add students roll name and marks.
You can enter a maximum of 10 students.
We can add marks for 3 sujects and 3 exams.
The 3 subjects are : Math , Physics and PSWC.
The 3 exams are ISA 1 , ISA2 AND ESA.
Note : Both ISA's are out of 40 and ESA's are out of 100

gradecard.c:
Displays the students grade card with above mentioned inputs.

updatemarks.c:
Reassigns new marks to student and changes grade accordingly.
User must input student's roll number to change their marks.

calculategrade.c:
Returns a letter {S,A,B,C,D,E,F} according to the students score in each subject.
ESA carries 60% weightage whereas ISAs carry 20% weightage each.


functions.h:
Functions library.

To run makefile(windows) : open cmd , and write "mingw32-make -f makefile.mk"

The program "run" can be run after this by either simply typing run(windows) or ./run(linux)

Author:Anish Kulkarni [PES2UG23CS074]
Sem -2 , Sec -B
PES UNIVERSITY
