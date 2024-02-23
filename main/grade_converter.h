#ifndef CGPA_GRADE_CONVERTER_H
#define CGPA_GRADE_CONVERTER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class GradeConverter {
public:
    std::map<std::string, double> gradeMap;
    void parseGrades(const std::string& filename) {
        std::ifstream file(filename); // Open the file
        std::map<std::string, double> gradeMap;

        if (!file.is_open()) {
            std::cerr << "Error opening file." << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string grade;
            double value;

            if (!(iss >> grade >> value)) { // Read the grade and value from the line
                std::cerr << "Error parsing line: " << line << std::endl;
                continue;
            }
            std::cout << grade << " " << value << std::endl;
            gradeMap[grade] = value; // Store the grade and its value in the map
        }

        file.close(); // Close the file
    }

    double getGrade(std::string &grade) {
        return gradeMap[grade];
    }

};

#endif //CGPA_GRADE_CONVERTER_H
