#include "student.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int find(vector <int> vec, size_t len, int seek)
{
    for (size_t i = 0; i < len; ++i)
    {
        if (vec[i] == seek) return i;
    }
    return -1;
}
  

int main (){
vector <int> ids {};
vector<Student> students {};
bool isrunning {true};
int age {};
int grade {};
int id {};
string name {};
cout << "Welcome to the Student Access Center." << endl;
cout << "You are logged in as an administrator." << endl;
cout << "What would you like to do?" << endl;

while (isrunning){
    char choice {};
    cout << "A - Add student" << endl;
    cout << "L - Look up student by ID" << endl;
    cout << "C - Change student info" << endl;
    cout << "E - Enroll student in course" << endl;
    cout << "U - Unenroll student in course" << endl;
    cout << "Q - quit" << endl;
    cin >> choice;
    switch (choice)
    {
    case 'a': case 'A': {
        id = 0;
        age = 0;
        grade = 0;
        name = " ";
        cout << "Enter Age:" << endl;
        cin >> age;
        cout << "Enter Grade" << endl;
        cin >> grade;
        cout << "Enter Name" << endl;
        cin >> name;
        cout << "Enter ID" << endl;
        cin >> id;
        
        
        students.emplace_back(name,age,grade);
        ids.emplace_back(id);
    };
        break;
    case 'l': case 'L': {
        
        cout << "Enter ID of Student you want to find:" << endl;
        cin >> id;
        int i = find(ids,ids.size(), id);
        Student s = students.at(i);
        s.display_info();
    };
        break; 

    case 'c': case 'C':{
        int choice {0};
        int id {0};
        string newname {""};
        int newage {0};
        int newgrade {0};
        cout << "Enter ID of Student you want to change information for." << endl;
        cin >> id;
        int i = find(ids, ids.size(), id);
        Student s = students.at(i);
        cout << "Press 1 to change name" << endl;
        cout << "Press 2 to change age" << endl;
        cout << "Press 3 to change grade" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter your new name." << endl;
                cin >> newname;
                s.change_name(newname);
                break;
            case 2:
                cout << "Enter your new age." << endl;
                cin >> newage;
                s.change_age(newage);
                break;
            case 3:
                cout << "Enter your new age." << endl;
                cin >> newgrade;
                s.change_grade(newgrade);
                break;
        }
        students[i] = s;

    };
    break;
    case 'e': case 'E': {
        int period;
        int cid;
        cout << "Enter ID of Student you want to enroll course:" << endl;
        cin >> id;
        int i = find(ids, ids.size(), id);
        Student s = students.at(i);
        cout << "Loading student info for student" << endl;
        s.display_info();
        cout << "Enter period you want to change course in. (1-8)" << endl;
        cin >> period;
        cout << "Enter new course id." << endl;
        cin >> cid;
        s.enroll_course(cid, period);
        students[i] = s;
    };
        break;

    case 'u': case 'U': {
        int period;
        cout << "Enter ID of Student you want to enroll course:" << endl;
        cin >> id;
        int i = find(ids, ids.size(), id);
        Student s = students.at(i);
        cout << "Loading student info for student" << endl;
        s.display_info();
        cout << "Enter period you want to change course in. (1-8)" << endl;
        cin >> period;
        s.unenroll_course(period);
        students[i] = s;
        cout << "Course set to default." << endl;
    };
        break;
    case 'q': case 'Q':
        isrunning = false;
        break;

    

    default:
    cout << "illegal input" << endl;
        break;
    }
    







    cout << "Continue? (y/n)";
    cin >> choice;
    switch (choice)
    {
    case 'Y': case 'y':
        continue;
        break;
    case 'N': case 'n':
        isrunning = false;
        break;
    default:
        cout << "Illegal input";
        break;
    }

};
    
    return 0;
}