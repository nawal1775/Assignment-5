#include "faculty.h"

Faculty::Faculty(){
    //Presetting values
    facultyID = 0;
    name = "", level = "", department = "";
    for(int i = 0; i < 3; i++)
        listAdvisors[i] = 0;
}

Faculty::Faculty(int f, string n, string l, string d, int a1, int a2, int a3){
    facultyID = f;
    name = n;
    level = l;
    department = d;
    listAdvisors[0] = a1;
    listAdvisors[1] = a2;
    listAdvisors[2] = a3;
}

//Getters (no need to have a getter for the list of advisors)
int Faculty::getFacultyID(){
    return facultyID;
}

string Faculty::getName(){
    return name;
}

string Faculty::getLevel(){
    return level;
}

string Faculty::getDepartment(){
    return department;
}

int Faculty::getAdvisor(int i){
    //First make sure i is in [0, 2] --> indexes 0, 1, or 2
    //If not in, then return a negative number
    //Otherwise, the advisor id at that index
    if(i >= 0 && i <= 2)
        return listAdvisors[i];
    return -9000;
}



//Setters
void Faculty::setFacultyID(int f){
    facultyID = f;
}

void Faculty::setName(string n){
    name = n;
}

void Faculty::setLevel(string l){
    level = l;
}

void Faculty::setDepartment(string d){
    department = d;
}

//first is the index (0-2), second is the id itself
void Faculty::setAdvisor(int i, int a){
    if(i >= 0 && i <= 2)
        listAdvisors[i] = a;
    else
        cout << "Invalid index!" << endl;
}

//Overload operators (Only care about the ID)
//See Student.cpp on how this is implemented. Method is the exact same
bool Faculty::operator==(const Faculty &a){
    return (facultyID == a.facultyID);
}

bool Faculty::operator<(const Faculty &a){
    return (facultyID < a.facultyID ? true : false);
}

bool Faculty::operator>(const Faculty &a){
    return (facultyID > a.facultyID ? true : false);
}

Faculty& Faculty::operator=(const Faculty &a){

    //Just replacing current contents with copy of a
    facultyID = a.facultyID;
    name = a.name;
    level = a.level;
    department = a.department;
    for(int i = 0; i < 3; i++)
        listAdvisors[i] = a.listAdvisors[i];

    return *this;
}

ostream& operator<<(ostream &out, const Faculty &a){

    cout << "Faculty ID: ";
    out<< a.facultyID << endl;
    cout << "Faculty's name: ";
    out << a.name << endl;
    cout << "Faculty's level: ";
    out << a.level << endl;
    cout << "Faculty's department: ";
    out << a.department << endl;
    cout << "Faculty's list of advisors by id: ";
    for(int i = 0; i < 3; i++)
        out << a.listAdvisors[i] << ' ';
    out << endl << endl;

    return out;
}
