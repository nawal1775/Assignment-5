/*
   templates are used
*/


#ifndef TABLE_CPP
#define TABLE_CPP

#include "table.h"

template <class T>
Table<T>::Table(){
    head = nullptr;
}

/*
    Helper function that simply calls the recursive insert function
*/
template <class T>
void Table<T>::addToTree(T data){
    Node *copy = head;
    head = insert(copy, data);
}

/*
    Insert is a recursive function that will immediately insert each value in the right place
    The recursion happens when iterating down the tree.

    with nested structures we can't immediately return Node *, since Node is "nested"
    Must define Node * in the scope of the class Table with the typename and then scope the function
*/
template <class T>
typename Table<T>::Node *Table<T>::insert(Node *copy, T data){

    //If the head is empty, then make the first data point = head
    if(copy == nullptr){
        copy = new Node;
        copy->key = data;
        copy->left = nullptr;
        copy->right = nullptr;
        return copy;
    }

    //Otherwise, call Insert again, but for either head->right (if data is larger than head's value) or head->left (if data is smaller than head's value)
    if(copy->key > data)
        copy->left = insert(copy->left, data);
    else if(copy->key < data)
        copy->right = insert(copy->right, data);

    return copy;
}

template <class T>
void Table<T>::printInOrder(){
    Node *current = head;
    print(current);
}

template <class T>
void Table<T>::print(Node *current){
    if(current != nullptr){
        print(current->left);
        cout << current->key << endl;
        print(current->right);
    }
}

template <class T>
void Table<T>::deleteFromTree(T data){
    Node *current = head;
    head = remove(current, data);
}

//helper function for remove; doesn't have to start at head
template <class T>
typename Table<T>::Node *Table<T>::minValue(Node *current){

    Node *temp = current;

    while (temp != nullptr && temp->left != nullptr)
        temp = temp->left;

    return temp;
}

template <class T>
typename Table<T>::Node *Table<T>::remove(Node *current, T data){

    //Base case: current node being searched is empty
    if(current == nullptr)
        return current;

    //If the id is smaller than root's id, then go left
    if(data < current->key)
        current->left = remove(current->left, data);
    //If the id is larger than root's id, then go right
    else if(data > current->key)
        current->right = remove(current->right, data);
    //FOUND IT
    else{
        //The found node doesn't have 2 children
        if(current->left == nullptr){
            Node *temp = current->right;
            delete current;
            return temp;
        }
        else if(current->right == nullptr){
            Node *temp = current->left;
            delete current;
            return temp;
        }

        //Confirmed to have 2 children: maintain order
        Node* temp = minValue(current->right);

        current->key = temp->key;

        current->right = remove(current->right, temp->key);
    }

    return current;
}

template <class T>
void Table<T>::find(T data){
    Node *current = head;
    search(current, data);
}

template <class T>
void Table<T>::search(Node *current, T data){
    //Will use the inorder traversal.
    //However, assuming that the ids are unique, we will assume only 1 thing will be outputted
    if(current != nullptr){
        search(current->left, data);

        //Found the matching ids
        if(current->key == data)
            cout << current->key << endl; //do not output data, output current's key instead

        search(current->right, data);
    }
}

//REWRITING FILE CONTENTS; same as inorder traversal
template <class T>
void Table<T>::fileInOrder(ofstream &out){
    Node *current = head;
    printFile(current, out);
}

template <class T>
void Table<T>::printFile(Node *current, ofstream &out){
    if(current != nullptr){
        printFile(current->left, out);
        out << current->key << endl;
        printFile(current->right, out);
    }
}

#endif
