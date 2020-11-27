// Name        : Node.cpp
// Author      : Giovanni Parati
// Date           : 11/6/2020
// Description : implementation for Node. Contains constructors, setters, and getters
#include <iostream>
using namespace std;
#include "Node.h"

Node::Node():c('\0'), next(NULL){}

Node::Node(char a){
    c=a;
    //cout<<"constructor 2"<<endl;
    next=NULL;
}

Node::Node(Node* n){
    c='\0';
    //cout<<"constructor 1"<<endl;
    next=n;
}

char Node::getChar(){
    return c;
}

char& Node::getCell(){
    return c;
}

Node* Node::getNext(){
    return next;
}

void Node::setChar(char a){
    c=a;
}

Node* Node::setNext(Node* n){
    next=n;
    return next;
}