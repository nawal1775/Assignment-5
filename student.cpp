#include "student.h"

//Default constructor
Student::Student(){
    //Presetting values
    studentID = 0, advisorID = 0;
    name = "", level = "", major = "";
    gpa = 0;
}

//Nondefault constructor
Student::Student(int s, int a, string n, string l, string m, double g){
    //Setting values based on passed on parameters
    studentID = s, advisorID = a;
    name = n, level = l, major = m;
    gpa = g;
}

//Getters

//Returns student ID
int Student::getStudentID(){
    return studentID;
}

//Returns advisor ID
int Student::getAdvisorID(){
    return advisorID;
}

//Returns name
string Student::getName(){
    return name;
}

//Returns Level
string Student::getLevel(){
    return level;
}

//Returns major
string Student::getMajor(){
    return major;
}

//Returns GPA
double Student::getGPA(){
    return gpa;
}

//Setters

//Changes the studentID to w/e s is
void Student::setStudentID(int s){
    studentID = s;
}

//Changes the advisorID to w/e a is
void Student::setAdvisorID(int a){
    advisorID = a;
}

//Changes the name to w/e n is
void Student::setName(string n){
    name = n;
}

//Changes the Level to w/e l is
void Student::setLevel(string l){
    level = l;
}

//Changes the major to w/e m is
void Student::setMajor(string m){
    major = m;
}

//Changes the GPA to w/e g is
void Student::setGPA(double g){
    gpa = g;
}

//Overload operators (Only care about the ID)

//equality
bool Student::operator==(const Student &a){
    return (studentID == a.studentID/* && advisorID == a.advisorID && name == a.name && Level == a.Level && major == a.major && gpa == a.gpa*/);
}

//less than
bool Student::operator<(const Student &a){
    //a way to write this is by using if/else
    if(studentID < a.studentID)
        return true;
    return false;
}

//greater than
bool Student::operator>(const Student &a){
    //a way to write this is by using (STATEMENT ? DO THIS IF TRUE : DO THIS IF FALSE)
    return (studentID > a.studentID ? true : false);
}

//Assignment operator: will be easier for Table to work with
Student& Student::operator=(const Student &a){

    //Just replacing current contents with copy of a
    studentID = a.studentID;
    advisorID = a.advisorID;
    name = a.name;
    level = a.level;
    major = a.major;
    gpa = a.gpa;

    return *this;
}

ostream& operator<<(ostream &out, const Student &a){

    cout << "Student ID: ";
    out << a.studentID << endl;
    cout << "Student's advisor ID: ";
    out << a.advisorID << endl;
    cout << "Student's name: ";
    out << a.name << endl;
    cout << "Student's Level of study: ";
    out << a.level << endl;
    cout << "Student's major: ";
    out << a.major << endl;
    cout << "Student's gpa: ";
    out << a.gpa << endl << endl;


    return out;
}
