#include "table.h"

int main(){

    //Declare a database of both students and faculty
    Table<Student> masterStudent;
    Table<Faculty> masterFaculty;

    //First, add to students;
    ifstream student("studentTable.txt");
    if(student.good()){

        //Declare variables to store data into a single student
        int id, aid;
        string name, field, major, bogus;
        double gpa;

        //loop until end of file
        while(!student.eof()){

            //Read in each line of info
            student >> id >> aid;
            getline(student, bogus); //For some reason, transitioning from cin >> to getline(cin, ...) results in bogus reads, thus we add this
            getline(student, name);
            getline(student, field);
            getline(student, major);
            student >> gpa;

            //Store into newStudent via nondefault constructor
            Student newStudent(id, aid, name, field, major, gpa);

            //Add to the tree
            masterStudent.addToTree(newStudent);

        }

        //Close the student file
        student.close();
    }

    //Then, add to faculty
    ifstream faculty("facultyTable.txt");
    if(faculty.good()){

        //Declare variables to store data into a single faculty member
        int id;
        string name, level, department, bogus;
        int aid1, aid2, aid3;

        //loop until end of file
        while(!faculty.eof()){

            //Read in each line of info
            faculty >> id;
            getline(faculty, bogus); //For some reason, transitioning from cin >> to getline(cin, ...) results in bogus reads, add this
            getline(faculty, name);
            getline(faculty, level);
            getline(faculty, department);
            faculty >> aid1 >> aid2 >> aid3;

            //Store into newFaculty via nondefault constructor
            Faculty newFaculty(id, name, level, department, aid1, aid2, aid3);

            //Add to the tree
            masterFaculty.addToTree(newFaculty);

        }

        //Close the faculty file
        faculty.close();
    }

    //The game loop: using a do/while to guarantee that w/e's inside the loop will be guaranteed to happen at least once.
    int option;
    do{
        //Menu system
        cout << "1. Print all students' info" << endl;
        cout << "2. Print all faculty members' info" << endl;
        cout << "3. Display a specific student info based on their id" << endl;
        cout << "4. Display a specific faculty info based on their id" << endl;
        cout << "5. Add a new student" << endl;
        cout << "6. Delete a student based on their id" << endl;
        cout << "7. Add a new faculty member" << endl;
        cout << "8. Delete a faculty member based on their id" << endl;
        cout << "9. Given a student’s id, print the name and info of their faculty advisor " << endl;
        cout << "10. Given a faculty id, print ALL the names and info of his/her advisees. " << endl;
        cout << "11. Change a student’s advisor given the student id and the new faculty id. " << endl;
        cout << "12. Remove an advisee from a faculty member given the ids " << endl;
        cout << "13. Rollback " << endl;
        cout << "14. Exit" << endl << endl;



        cout << "Please enter one of the options above (1-14): ";
        cin >> option;

        //Cycle through all options: cycling through option 14 is optional
        if(option == 1){
            cout << "Printing out all students sorted by ID: " << endl;
            masterStudent.printInOrder();
        }

        if(option == 2){
            cout << "Printing out all faculty members sorted by ID: " << endl;
            masterFaculty.printInOrder();
        }

        if(option == 3){
            int id;

            //Ask for id
            cout << "Student id to find: ";
            cin >> id;

            //Create a default student and use setter to ONLY add id
            Student findStudent;
            findStudent.setStudentID(id);

            //Finally, call the find function
            masterStudent.find(findStudent);

        }

        if(option == 4){
            int id;

            //Ask for id
            cout << "Faculty id to find: ";
            cin >> id;

            //Create a default faculty and use setter to ONLY add id
            Faculty findFaculty;
            findFaculty.setFacultyID(id);


            //Finally, call the find function
            masterFaculty.find(findFaculty);

        }

        if(option == 5){
            int id, aid;
            string name, field, major;
            double gpa;

            //Ask for various pieces of info for Student
            cout << "Student id: ";
            cin >> id;
            cout << "Student's advisor id: ";
            cin >> aid;
            cin.ignore(); //transitioning from cin >> to getline(cin, ..) will cause problems
            cout << "Student name: ";
            getline(cin, name);
            cout << "Student field: ";
            getline(cin, field);
            cout << "Student major: ";
            getline(cin, major);
            cout << "Student gpa: ";
            cin >> gpa;
            cout << endl;

            //Create the student, given info above, and add to the BST
            Student newStudent(id, aid, name, field, major, gpa);
            masterStudent.addToTree(newStudent);
        }

        if(option == 6){
            //IDEA: only ask for id, then create the new student via default constructor and use the id setter.
            //Looking at operator overload on student, so of the the id matches we're good


            int id;

            //Ask for id
            cout << "Student id to remove: ";
            cin >> id;

            //Create a default student and use setter to ONLY add id
            Student deleteStudent;
            deleteStudent.setStudentID(id);

            //Delete the student with the same id, if they exist
            masterStudent.deleteFromTree(deleteStudent);

        }

        if(option == 7){
            //Declare variables to store data into a single faculty member
            int id;
            string name, level, department;
            int aid1, aid2, aid3;

            //Ask for various pieces of info for Faculty
            cout << "Faculty id: ";
            cin >> id;
            cin.ignore(); //transitioning from cin >> to getline(cin, ..) will cause problems
            cout << "Faculty name: ";
            getline(cin, name);
            cout << "Faculty level: ";
            getline(cin, level);
            cout << "Faculty department: ";
            getline(cin, department);
            cout << "First advisor id: ";
            cin >> aid1;
            cout << "Second advisor id: ";
            cin >> aid2;
            cout << "Third advisor id: ";
            cin >> aid3;

            //Create the faculty, given info above, and add to the BST
            Faculty newFaculty(id, name, level, department, aid1, aid2, aid3);
            masterFaculty.addToTree(newFaculty);

        }

        if(option == 8){
            //same as the idea of option 6

            int id;

            //Ask for id
            cout << "Faculty id to remove: ";
            cin >> id;

            //Create a default faculty and use setter to ONLY add id
            Faculty deleteFaculty;
            deleteFaculty.setFacultyID(id);

            //Delete the faculty with the same id, if they exist
            masterFaculty.deleteFromTree(deleteFaculty);
        }

        if(option == 14){

            //Write back to the files
            ofstream writeStudent, writeFaculty;

            //Start with student
            writeStudent.open("studentTable.txt");
            masterStudent.fileInOrder(writeStudent);
            writeStudent.close();

            //Then with faculty
            writeFaculty.open("facultyTable.txt");
            masterFaculty.fileInOrder(writeFaculty);
            writeFaculty.close();

        }

        cout << endl;

    } while(option != 14);







    return 0;
}
