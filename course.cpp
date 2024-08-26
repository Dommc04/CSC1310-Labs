#include <iostream>
#include "course.h"
using namespace std;

    Course *createCourse(string name, string location, int numSections, int numCredit){
    Course *myCourse = new Course;

    myCourse->Name = name;
    myCourse->Location = location;
    myCourse->NumSections = numSections;
    myCourse->NumCredit = numCredit;
    myCourse-> Sections = new string[numSections];

    return myCourse;
}

  void destroyCourse(Course* myCourses){
    if(myCourses != NULL){
        delete [] myCourses->Sections;
        delete myCourses;}
}

void printCourse(Course* myCourses){
    if(myCourses != NULL){
        cout << left  <<"COURSE NAME:" <<myCourses->Name << endl;
        cout << left <<"COURSE LOCATION:" <<myCourses->Location << endl;
        cout << left  <<"COURSE HOURS:" <<myCourses->NumCredit << endl;
        cout << "COURSE SECTIONS:" << endl;
        for(int i=0; i < myCourses->NumSections; i++){
            cout << right << myCourses->Sections[i] << endl;
        }
    }
}
