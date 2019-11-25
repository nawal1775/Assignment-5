//header guards!
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student{

    private:
        int studentID, advisorID;
        string name, level, major;
        double gpa;


    public:

        //Constructor required; both default and nondefault will be used
        Student();
        Student(int, int, string, string, string, double);

        //Getters
        int getStudentID();
        int getAdvisorID();
        string getName();
        string getLevel();
        string getMajor();
        double getGPA();

        //Setters
        void setStudentID(int);
        void setAdvisorID(int);
        void setName(string);
        void setLevel(string);
        void setMajor(string);
        void setGPA(double);

        //Overload operators (Only care about the ID)
        //Adding in assignment operator to help Table be easier to implement
        bool operator==(const Student &); //equality
        bool operator<(const Student &); //less than
        bool operator>(const Student &); //greater than
        Student& operator=(const Student &); //assignment

        //For Table, to output entire student information
        friend ostream& operator<<(ostream &, const Student &);



};




#endif
