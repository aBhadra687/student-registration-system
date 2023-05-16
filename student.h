#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <string>
#include <map>
using namespace std;


    class Student {
        private:
        string name {};
        int grade {0};
        int age {0};
        int courses [8]{0,0,0,0,0,0,0,0};
        map <int, string> course_map;
        
        
        
        
        public:
        Student (string n, int a, int g)
        : name {n}, age{a}, grade{g}{
            course_map[1] = "Math";
            course_map[2] = "Language Arts";
            course_map[3] = "History";
            course_map[4] = "Advisory/Lunch";
            course_map[5] = "Science";
            course_map[6] = "French";
            course_map[7] = "Gym";
            course_map[8] = "Orchestra";
        }

        void enroll_course (int course_id, int period);
        void unenroll_course (int period);
        void display_info ();     
        void change_name (string n);
        void change_age (int a);
        void change_grade (int g);
           
        









    };

#endif