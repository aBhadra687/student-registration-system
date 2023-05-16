#include "student.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

void Student::enroll_course(int course_id, int period){
    int i = period - 1;

    if (course_map.find(course_id) != course_map.end()){
        courses[i] = course_id;
        cout << "Enrolled successfully." << endl;
    } else if (courses[i] != 0) {
        cout << "There is already a course selected for that period." << endl;
    } else {
        cout << "Invalid Course ID";
    }
}

void Student::unenroll_course(int period){
    int i = period - 1;
    if (i > 7){
        i = 7;
    }
    if (courses[i] != 0){
        courses[i] = 0;
        cout << "Course unenrolled successfully" << endl;
    } else {
        cout << "There is no course selected for that period" << endl;
    }
}

void Student::display_info(){
    
    cout << "Name: " << name << endl;
    cout << "Age " << age << endl;
    cout << "Grade " << grade << endl;
    cout << "Courses " << endl;
    for(auto p:courses){
        
        if (course_map.find(p) != course_map.end()){
        
        cout << course_map[p] << " ";
        } else {
            cout << "None" << " ";
        }
    }
    cout << endl;
}

void Student::change_name(string n){
    name = n;
}
void Student::change_age(int a){
    age = a;
}
void Student::change_grade(int g){
    grade = g;
}