#include <vector>
#include <list>
#include <deque>
#include "student.h"


void splitStudents(vector<Student> &students, vector<Student> &passedStudents, vector<Student> &failedStudents);
void splitStudents(list<Student> &students, list<Student> &passedStudents, list<Student> &failedStudents);
void splitStudents(deque<Student> &students, deque<Student> &passedStudents, deque<Student> &failedStudents);