// Name        : SLLString.h
// Author      : Giovanni Parati
// Date           : 11/6/2020
// h file for SLLString.cpp
#include <string>
#include "Node.h"
using namespace std;

class SLLString{
    private:
    Node* head;
    int l;
    Node* copyChain(int* pl, Node* h);

    public:
    SLLString();
    SLLString(const string& other);
    ~SLLString();
    SLLString(const SLLString& other);

    SLLString& operator=(const SLLString& other);
    int length() const;
    SLLString& operator+= (const SLLString& other);
    char& operator[](const int n);

    int findSubstring(const SLLString& substring);
    void erase(char c);

    Node* getHead() const;

    friend ostream& operator<<(ostream& os, const SLLString& s);
};