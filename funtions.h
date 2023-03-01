#include "MyLib.h"
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct Student {
    string name, surname;
    vector<float> homeworkGrades;
    int examGrade;
    double finalGradeAverage = 0, finalGradeMedian = 0;
};

void addStudents(vector<Student> &students);
void addStudentsFromFile(vector<Student> &students);
void addStudentsFromSTDIN(vector<Student> &students);
void enterStudentData(Student &student);
void generateGrades(Student &student);
void calculateFinalGrade(Student &student);
string getFormatedStudentData(Student student, bool useAverage);
void writeResultsToFile(vector<Student> &students, string fileName);

#endif