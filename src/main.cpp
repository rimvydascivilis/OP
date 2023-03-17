#include "student_io.h"
#include "gen_stud_file.h"
#include "timer.h"

int main() {
    vector<Student> students;
    string results;
    double programDuration = 0;
    Timer timer;

    char action = getActionFromInput();
    if (action == 'g'){
        gen_stud_file(getHomeworkCountFromInput());
        return 0;
    }
    if (action == 'f') {
        string fileName = getFileNameFromInput();

        timer.reset();
        addStudentsFromFile(students, fileName);
        timer.stop();

        programDuration += timer.getDuration();
        cout << "Studentu nuskaitymas is failo uztruko: " << timer.getDuration() << "s" << endl;
    } else {
        addStudentsFromSTDIN(students);
    }

    bool useAverage = getFinalGradeCalculationMethod();
    for (Student &student : students) {
        calculateFinalGrade(student, useAverage);
    }

    timer.reset();
    sort(students.begin(), students.end(), [](Student &a, Student &b) {
        return a.surname > b.surname;
    });
    timer.stop();

    cout << "Studentu rusiavimas uztruko: " << timer.getDuration() << "s" << endl;
    programDuration += timer.getDuration();
    
    timer.reset();
    vector<Student> failedStudents;
    vector<Student> passedStudents;
    while (students.size()) {
        Student student = students.back();
        students.pop_back();
        if (student.finalGrade < 5) {
            failedStudents.push_back(student);
        } else {
            passedStudents.push_back(student);
        }
    }
    timer.stop();

    cout << "Studentu surinkimas uztruko: " << timer.getDuration() << "s" << endl;
    programDuration += timer.getDuration();
    timer.reset();

    fs::create_directory("data");

    timer.reset();
    writeResultsToFile(passedStudents, "data/geriStudentai.txt", useAverage);
    timer.stop();

    cout << "Geru studentu irasymas i faila uztruko: " << timer.getDuration() << "s" << endl;
    programDuration += timer.getDuration();
    
    timer.reset();
    writeResultsToFile(failedStudents, "data/blogiStudentai.txt", useAverage);
    timer.stop();

    cout << "Blogu studentu irasymas i faila uztruko: " << timer.getDuration() << "s" << endl;
    programDuration += timer.getDuration();

    cout << "Programos veikimo laikas (Be naudotojo ivesties laukimo laiko): " << programDuration << "s" << endl;
    return 0;
}