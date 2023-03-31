#include "utility.h"

void splitStudents(vector<Student> &students, vector<Student> &passedStudents, vector<Student> &failedStudents) {
    while (students.size()) {
        Student student = students.back();
        students.pop_back();
        if (student.finalGrade < 5) {
            failedStudents.push_back(student);
        } else {
            passedStudents.push_back(student);
        }
    }
}

void splitStudents(list<Student> &students, list<Student> &passedStudents, list<Student> &failedStudents) {
    while (students.size()) {
        Student student = students.back();
        students.pop_back();
        if (student.finalGrade < 5) {
            failedStudents.push_back(student);
        } else {
            passedStudents.push_back(student);
        }
    }
}

void splitStudents(deque<Student> &students, deque<Student> &passedStudents, deque<Student> &failedStudents) {
    while (students.size()) {
        Student student = students.back();
        students.pop_back();
        if (student.finalGrade < 5) {
            failedStudents.push_back(student);
        } else {
            passedStudents.push_back(student);
        }
    }
}