#include "funtions.h"

int main() {
    vector<Student> students;
    string results;

    addStudents(students);
    if (students.size() == 0) {
        cout << "Nera duomenu, rezultatu failas nebus sukurtas" << endl;
        return 0;
    }
    cout << "Skaiciuojami balai..." << endl;
    for (Student &student : students) {
        calculateFinalGrade(student);
    }
    cout << "Rezultatai surikiuojami..." << endl;
    sort(students.begin(), students.end(), [](Student a, Student b) { return a.surname < b.surname; });
    cout << "Rezultatai isvedami i faila..." << endl;
    writeResultsToFile(students, "rezultatai.txt");
    
    return 0;
}