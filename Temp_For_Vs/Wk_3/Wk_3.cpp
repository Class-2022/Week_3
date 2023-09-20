#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Student {
public:
    Student(const string& first_name, const string& last_name, int grade)
        : first_name(first_name), last_name(last_name), grade(grade) {}

    
    string getFirstName() const {
        return first_name;
    }

    string getLastName() const {
        return last_name;
    }

    int getGrade() const {
        return grade;
    }

    
    bool operator<(const Student& other) const {
        return grade > other.grade;
    }

private:
    string first_name;
    string last_name;
    int grade;
};

int main() {
    vector<Student> students;
    ifstream inputFile("student_data.txt");

    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string first_name, last_name;
        int grade;

        if (iss >> first_name >> last_name >> grade) {
            Student student(first_name, last_name, grade);
            students.push_back(student);
        }
        else {
            cerr << "Error parsing line: " << line << endl;
        }
    }

    cout << "Week 3 assignment - Students grades." << endl;
    cout << "------------------------------------" << endl;

    inputFile.close();

    
    sort(students.begin(), students.end());

   
    for (const Student& student : students) {
        cout << student.getFirstName() << " " << student.getLastName() << ": " << student.getGrade() << endl;
    }

    return 0;
}
