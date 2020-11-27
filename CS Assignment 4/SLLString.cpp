// Name        : SLLString.cpp
// Author      : Giovanni Parati
// Date           : 11/6/2020
// Description : implementation for SLLString. Contains constructors, erase, findSubstring, a deep copy method,
// operators and getters

#include <string>
#include <iostream>
#include "SLLString.h"

SLLString::SLLString(){
    head=new Node();
    l=0;//length
}

SLLString::SLLString(const string& other){
    head=new Node(other.at(0));
    Node* p=head;
    for(l=1; l<other.size(); l++){
        //cout<<"before"<<endl;
        char f=other.at(l);
        //cout<<"f: "<<f<<endl;
        Node* t=new Node(f);
        //cout<<"after"<<endl;
        p=p->setNext(t);
    }
}

SLLString::~SLLString(){
    Node *currNode = head, *nextNode = NULL;
    while (currNode != NULL){
        // Step 1: remember the next node
        nextNode = currNode->getNext();        
        // step 2: destroy the current node
        delete currNode;
        // step 3: make the next node current
        currNode = nextNode;
    }
}

SLLString::SLLString(const SLLString& other){
    head=new Node(other.getHead());
    Node* pn=head;
    Node* po=other.getHead()->getNext();
    while(l!=other.length()){
        Node t=new Node(po->getChar());
        po=po->setNext(&t);
    }
}

Node* SLLString::getHead() const{
    return head;
}
int SLLString::length() const{
    return l;
}

SLLString& SLLString::operator=(const SLLString& other){
    head=copyChain(&l, other.head);//need Node destructor
    return *this;
}

char& SLLString::operator[](const int n){
    Node* p=head;
    int i=0;

    while(i<l){
        if(i==n){
            return p->getCell();
        }
        else{
            i++;
            p=p->getNext();
        }
    }
    if(n>l){
        return p->getCell();
    }
    return head->getCell();
}

SLLString& SLLString::operator+= (const SLLString& other){
    if(head==NULL){
        head=other.head;
    }
    else{
        Node* p=head;
        while(p->getNext()!=NULL){
            p=p->getNext();
        }
        int t=0;
        p->setNext(copyChain(&t, other.head));
        l+=t;
    }
    return *this;
}

//finds index of the first char of the substring
int SLLString::findSubstring(const SLLString& substring){
    char cs=substring.getHead()->getChar();
    char cf;
    Node* p=head;
    //cf=p->getChar();    
    int j=0;
    bool done=false;
    while(p->getNext()!=NULL && !done){
        while(p->getChar()!=cs && p->getNext()!=NULL){
            p=p->getNext();
            if(p!=NULL){
                //cf=p->getChar();
                j++;
            }
        }
        Node* ps=substring.getHead();
        int i=0;
        done=true;
        while(i<substring.length()){
            if(p->getChar()!=ps->getChar()){
                done=false;
            }
            else{
                p=p->getNext();
                ps=ps->getNext();
            }
            i++;
        }
    }
    if(done){
        return j;
    }
    return -1;
}

ostream& operator<< (ostream& os, const SLLString& s){
    string t="";
    Node* p=s.getHead();
    while(p!=NULL){
        t+=p->getChar();
        p=p->getNext();
    }
    os<<t;
    return os;
}

//erases all instances of the given character
void SLLString::erase(char c){
    int i=0;
    Node* p=head;
    while(p!=NULL && p->getChar()==c){
        Node* temp=p;
        p=(p->getNext());
        delete temp;
        head=p;
        i++;
    }
    while(p->getNext()!=NULL){
        if(p->getNext()->getChar()==c){
            Node* temp=p->getNext();
            p->setNext(p->getNext()->getNext());
            delete temp;
            i++;
        }
        else{p=p->getNext();}
    }
    l-=i;
}

//creates deep copy of an SLLString, input length so it can be changed appropriately
Node* SLLString::copyChain(int* pl, Node* h){
    int i=0;
    if(h==NULL){
        *pl=i;
        return h;
    }
    Node* nhead=new Node();
    i++;
    nhead->setChar(h->getChar());
    h=h->getNext();
    Node* p=nhead;
    while(h!=NULL){
        //cout<<"before"<<endl;
        //cout<<"f: "<<f<<endl;
        Node* t=new Node();
        i++;
        t->setChar(h->getChar());
        //cout<<"after"<<endl;
        p=p->setNext(t);
        h=h->getNext();
    }
    *pl=i;
    return nhead;
}