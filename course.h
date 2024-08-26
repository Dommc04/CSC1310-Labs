
#ifndef Course_H
#define Course_H

#include <iostream>
#include <string>
using namespace std;

struct Course

{
   string Name;
   string Location;
   string *Sections;
   int NumSections;
   int NumCredit;

};

Course* createCourse(string, string, int, int);
void destroyCourse(Course* myCourses);
void printCourse(Course* myCourses);

#endif

