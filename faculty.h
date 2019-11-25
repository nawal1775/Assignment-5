/*
    header guards
    #ifndef
    #define

    //declarations in the middle

    #endif

*/
#ifndef FACULTY_H
#define FACULTY_H

#include "student.h" //student.h has <iostream>, <string> and using namespace std thus student is included

class Faculty{

    private:
        int facultyID;
        string name, level, department;
        int listAdvisors[3]; //For simplicity, only assume there are 3 advisors per faculty; this can be changed to be dynamic or there can be different # of advisors

    public:
        //Default constructor
        Faculty();
        //Nondefault constructor
        Faculty(int, string, string, string, int, int, int);

        //Getters
        int getFacultyID();
        string getName();
        string getLevel();
        string getDepartment();
        int getAdvisor(int); //only getting 1 advisor by index


        //Setters
        void setFacultyID(int);
        void setName(string);
        void setLevel(string);
        void setDepartment(string);
        void setAdvisor(int, int); //first is the index (0-2), second is the id itself

        //Overload operators (Only care about ID)
        //Adding in assignment operator to help Table be easier to implement
        bool operator==(const Faculty &); //equality
        bool operator<(const Faculty &); //less than
        bool operator>(const Faculty &); //greater than
        Faculty& operator=(const Faculty &); //assignment

        //For Table, to output entire faculty information
        friend ostream& operator<<(ostream &, const Faculty &);

};

#endif
