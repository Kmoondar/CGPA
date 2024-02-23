#include <iostream>
#include <vector>
#include <map>
#include "grade_converter.h"

using namespace std;


int main() {
    //Number of courses student has
    cout << "Number of courses you have: ";
    int num_courses;
    cin >> num_courses;
    cout << "\n";

    cout << "Below please insert names of the courses, their grades and number of credits\n";
    vector<string> courses(num_courses);
    vector<double> grades(num_courses);
    vector<int> credits(num_courses);
    GradeConverter converter;
    for(int i=0; i<num_courses; i++) {
        cout << "Course name " << i+1 << ": ";
        cin >> courses[i];
        cout<<"Grade for " << courses[i] << ": ";
        string grade;
        cin >> grade;
        grades[i] = converter.getGrade(grade);
        cout<<"Number of credits: ";
        cin >> credits[i];
    }
    cout <<"list of grades\n";
    for(auto e: grades) {
        cout << e << endl;
    }
}