#ifndef STUDENT_IO_H
#define STUDENT_IO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <random>
#include <limits>

#include "student.h"
#include "timer.h"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::stringstream;
using std::invalid_argument;
using std::setw;
using std::left;
using std::setprecision;
using std::fixed;
using std::ofstream;

char getActionFromInput();
void addStudentsFromFile(vector<Student> &students, string fileName);
void addStudentsFromFile(list<Student> &students, string fileName);
void addStudentsFromFile(deque<Student> &students, string fileName);
int getHomeworkCountFromInput();
string getFileNameFromInput();
bool fileExists(const string& fileName);
bool fileEmpty(string fileName);
Student parseLine(const string& line);
string cleanGradeString(string grade);
void addStudentsFromSTDIN(vector<Student> &students);
void addStudentsFromSTDIN(list<Student> &students);
void addStudentsFromSTDIN(deque<Student> &students);
void enterStudentInformation(Student &student);
bool getFinalGradeCalculationMethod();
void writeResultsToFile(vector<Student>& students, string fileName, bool useAverage);
void writeResultsToFile(list<Student> &students, string fileName, bool useAverage);
void writeResultsToFile(deque<Student> &students, string fileName, bool useAverage);
string getFormattedStudentData(const Student& student, bool useAverage);

#endif