#include "gen_stud_file.h"

void gen_stud_file(int homeworkCount) {
    vector<int> fileSizes = {1000, 10000, 100000, 1000000, 10000000};
    Timer timer;
    double duration;
    system("mkdir -p data");
    for(int fileSize: fileSizes) {
        timer.reset();
        string filename = "data/studentai" + to_string(fileSize) + ".txt";
        createFileWithStudents(filename, fileSize, homeworkCount);
        timer.stop();
        duration += timer.getDuration();
        cout << "Failo \"" << filename << "\" sukurimas uztruko: " << fixed << setprecision(2) << timer.getDuration() << "s" << endl;
    }
    cout << "Viso uztruko: " << fixed << setprecision(2) << duration << "s" << endl;
}

void createFileWithStudents(string filename, int fileSize, int homeworkCount) {
    string output = "";
    stringstream ss;
    ss << setw(30) << left << "Vardas" << setw(30) << "Pavarde";
    for (int i = 0; i < homeworkCount; i++) {
        ss << setw(20) << "ND" + to_string(i + 1);
    }
    ss << setw(20) << "Egz." << endl;
    output += ss.str();

    mt19937 gen(random_device{}());

    for (int i = 0; i < fileSize; i++) {
        ss.str("");
        Student student;
        student.name = "Vardas" + to_string(i+1);
        student.surname = "Pavarde" + to_string(i+1);

        generateGrades(student, homeworkCount, &gen);

        ss << setw(30) << left << student.name << setw(30) << student.surname;
        for (int j = 0; j < homeworkCount; j++) {
            ss << setw(20) << student.homeworkGrades.at(j);
        }
        ss << setw(20) << student.examGrade << endl;
        output += ss.str();
    }
    ofstream file(filename);
    file << output;
    file.close();
}