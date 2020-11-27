// Name        : Node.h
// Author      : Giovanni Parati
// Date           : 11/6/2020
// h file for Node.cpp

class Node{
    private:
    char c;
    Node* next;

    public:
    Node();
    Node(char a);
    Node(Node* n);
    //Node(char c, Node* n=NULL);

    char getChar();
    char& getCell();
    Node* getNext();

    void setChar(char a);
    Node* setNext(Node* n);
};