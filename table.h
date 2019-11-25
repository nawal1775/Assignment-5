#ifndef TABLE_H
#define TABLE_H

#include "faculty.h" //faculty also has student included
#include <fstream>

template <class T>
class Table{
    private:
        //Going to use a struct (nested within a class) so that we can preserve the Template typing
        //Using typedef so that we don't have to declare a Node type as struct Node everytime.
        typedef struct Node{
            T key; //if this was outside the class, then using K would not be possible;
            Node *left, *right;
        } Node; //Node here replaces "struct Node" when declaring as an object

        Node *head; //the beginning of the BST


    public:
        Table();

        void addToTree(T);
        Node *insert(Node *, T);

        void printInOrder();
        void print(Node *);


        void deleteFromTree(T);
        Node *minValue(Node *);
        Node *remove(Node *, T);


        void find(T);
        void search(Node *, T);

        void fileInOrder(ofstream &);
        void printFile(Node *, ofstream &);

};


//templates are used, must include table.cpp here after the class declaration above.
#include "table.cpp"

#endif
