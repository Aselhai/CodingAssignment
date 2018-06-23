#include <iostream>
#include <cstdlib>
#include <string>

#include "class.h"
#include "student.h"

using namespace std;

// 전혀 특별할 것이 없는 생성자들입니다.
Class::Class() {
    amount = 0;
}

Class::Class(string i_name, string i_instructor) {
    class_name = i_name;
    instructor = i_instructor;
    amount = 0;
}

// 역시 특별할 것이 없는 복사 생성자이지만 포인터 개념이 들어가서 조금 어려웠습니다.
Class::Class(const Class &i_class) {
    class_name = i_class.class_name;
    instructor = i_class.instructor;
    amount = i_class.amount;
    
    student_list = new Student[amount];
    for(int i = 0; i < amount; i++) {
        student_list[i] = i_class.student_list[i];
    }
}

void Class::SetClassName(string i_name, string i_instructor) {
    class_name = i_name;
    instructor = i_instructor;
}

void Class::Register(string student, int id) {
    /* string형 student와 int형 id의 값을 전달받습니다. 우선 임시로 저장할 크기가 amount인 Stunent 배열 temp를 만듭니다.
        student_list의 모든 원소를 temp에 대입합니다. 이후, stundet_list를 삭제한 다음 amount에 1을 더합니다.
        student_list를 새롭게 정의한 후 temp의 값을 다 대입합니다. 마지막 남은 한 칸은 입력 받은 student, id를 넣습니다.*/
    Student *temp;
    temp = new Student[amount];

    for(int i = 0; i < amount; i++) {
        temp[i].setter(student_list[i].get_student_name(), student_list[i].get_id());
    }
    
    amount++;

    delete [] student_list;
    student_list = new Student[amount];
    for(int i = 0; i < amount - 1; i++) {
        student_list[i].setter(temp[i].get_student_name(), temp[i].get_id());
    }

    delete [] temp;
    student_list[amount - 1].setter(student, id);
}

void Class::Withdraw(int i_id) {
    /* for문을 이용하여 i_id와 같은 값을 찾습니다. 같다면, 크기가 amount - (i + 1)인 Student 배열 temp를 만듭니다.
        여기에 찾은 값을 기준으로 temp 배열에 넣습니다. 이후, amount에서 1을 뺀 후 student_list를 삭제한 후 새로 만듭니다.
        이후, for문으로 temp의 모든 원소를 student_list에 넣은 후 temp를 삭제합니다.*/
    for(int i = 0; i < amount; i++) {
        if (student_list[i].get_id() == i_id) {
            Student *temp;
            temp = new Student[amount - 1];

            for(int j = 0; j < i; j++) {
                temp[j].setter(student_list[j].get_student_name(), student_list[j].get_id());
            }
            for(int j = i; j < amount - 1; j++) {
                temp[j].setter(student_list[j + 1].get_student_name(), student_list[j + 1].get_id());
            }

            amount--;

            delete [] student_list;
            student_list = new Student[amount];

            for(int j = 0; j < amount; j++) {
                student_list[j].setter(temp[j].get_student_name(), temp[j].get_id());
            }

            delete [] temp;

            break;
        }
    }
}

void Class::Display() {
    cout<<"Prof. : "<<instructor<<"            Class name : "<<class_name<<endl;
    cout<<"--------------------------------------------------------------"<<endl;
    cout<<"Total number of students : "<<amount<<endl;
    cout<<endl;
    for(int i = 0; i < amount; i++) {
        cout<<student_list[i].get_student_name()<<"                 "<<student_list[i].get_id()<<endl;
    }
    cout<<endl;
}

Class& Class::operator =(const Class &i_class) {
    if (this != &i_class ) {
        delete [] student_list;

        this->class_name = i_class.class_name;
        this->instructor = i_class.instructor;
        this->amount = i_class.amount;
        
        this->student_list = new Student[amount];
        for(int i = 0; i < amount + 1; i++) {
            cout<<i_class.student_list[i].get_student_name()<<endl;
            this->student_list[i].setter(i_class.student_list[i].get_student_name(), i_class.student_list[i].get_id());
        }
    }
    return *this;  
}

Class::~Class() {
    delete [] student_list;
}