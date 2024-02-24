#include <iostream>
#include <vector>
#include <iomanip>
#include "grade_converter.h"

using namespace std;

int num_courses;
vector<string> courses;
vector<double> grades;
vector<int> credits;

void grade_information() {
    GradeConverter converter;
    converter.parseGrades("main/grades.txt");

    cout << "Number of courses you have: ";
    cin >> num_courses;
    courses.resize(num_courses);
    grades.resize(num_courses);
    credits.resize(num_courses);

    cout << "\nBelow please insert names of the courses, their grades and number of credits\n";
    for(int i=0; i<num_courses; i++) {
        cout << "\nCourse name " << i+1 << ": ";
        cin >> courses[i];
        cout<<"\nGrade for " << courses[i] << ": ";
        string grade;
        cin >> grade;
        grades[i] = converter.getGrade(grade);
        cout<<"\nNumber of credits: ";
        cin >> credits[i];
    }
}

double caclulate_CGPA() {
    double total_grade_point = 0.0;
    int total_credit_hours = 0;

    for(int i=0; i<num_courses; i++) {
        total_grade_point+=(grades[i]*credits[i]);
        total_credit_hours+=credits[i];
    }

    return total_grade_point/total_credit_hours;
}

int main() {
    grade_information();
    //calculation code
    double CGPA = caclulate_CGPA();
    cout << fixed << setprecision(2);
    cout << "\nYour cumulative grade point average is: " << CGPA;
}

