#include <iostream>
#include <vector>
#include <array>

const std::array<std::string, 9> grades = {"A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F"};

const double pa[] = {4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.0};

double grade_to_pa(const std::string &grade) {
    for (int i = 0; i < grades.size(); ++i) {
        if (grades[i] == grade)
            return pa[i];
    }
    throw; // unreachable
}


int main() {
    constexpr int courses = 20;
    double acc_gp = 0;
    double acc_pa = 0;
    for (int i = 0; i < courses; ++i) {
        std::string course_name;
        double gp;
        std::string grade;
        std::cin >> course_name >> gp >> grade;

        if (grade == "P")
            continue;

        acc_pa += grade_to_pa(grade) * gp;
        acc_gp += gp;
    }

    double gpa = acc_pa / acc_gp;
    // std::cout << gpa;
    std::printf("%.6f", gpa);
}

