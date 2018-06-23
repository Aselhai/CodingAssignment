#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <cstdlib>
#include <string>

#include "student.h"

using namespace std;

class Class {
    private:
        string class_name;
        string instructor;
        Student *student_list;
        int amount;
    public:
        Class();
        Class(string i_name, string i_instructor);
        Class(const Class &i_class);

        void SetClassName(string i_name, string i_instructor);
        void Register(string student, int id);
        void Withdraw(int i_id);
        void Display();

        Class& operator =(const Class &i_class);
        
        ~Class();
};

#endif