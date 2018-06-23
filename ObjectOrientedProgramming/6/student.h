#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Student {
    private:
        string student_name;
        int id;
    public:
        Student();
        Student(string i_student_name, int i_id);

        void setter (string i_student_name, int i_id);

        string get_student_name();
        int get_id();
};

#endif