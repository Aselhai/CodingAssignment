#include <iostream>
#include <cstdlib>
#include <string>

#include "student.h"

using namespace std;

Student::Student() {
    student_name = "";
    id = 0;
}

Student::Student(string i_student_name, int i_id) {
    student_name = i_student_name;
    id = i_id;
}

void Student::setter (string i_student_name, int i_id) {
    student_name = i_student_name;
    id = i_id;
}

string Student::get_student_name() {
    return student_name;
}

int Student::get_id() {
    return id;
}