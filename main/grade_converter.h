#ifndef CGPA_GRADE_CONVERTER_H
#define CGPA_GRADE_CONVERTER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class GradeConverter {
private:
    std::map<std::string, double> gradeMap;

public:
    void parseGrades(const std::string& filename) {
        std::ifstream file(filename); // Open the file

        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string grade;
            char equal;
            double value;

            if (!(iss >> grade >> equal >> value)) { // Read the grade and value from the line
                std::cerr << "Error parsing line: " << line << std::endl;
                continue;
            }

            gradeMap[grade] = value; // Store the grade and its value in the map
        }

        file.close(); // Close the file
    }

    double getGrade(const std::string &grade) const {
        auto it = gradeMap.find(grade);
        if (it != gradeMap.end()) {
            return it->second;
        } else {
            std::cerr << "Grade not found: " << grade << std::endl;
            return 0.0;
        }
    }

    void printMap() const {
        for(const auto& entry: gradeMap) {
            std::cout << entry.first << " = " << entry.second << "\n";
        }
    }
};

#endif //CGPA_GRADE_CONVERTER_H
