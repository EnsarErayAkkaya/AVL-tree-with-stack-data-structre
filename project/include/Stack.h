/**
* Stack.h 
* Stack.cpp dosyasının header dosyasıdır ve stack method şablonları ve sınıf tanımını içerir.
* @course !!!!!!! Dersi aldığınız eğitim türü ve grup !!!!!!!!!
* @assignment !!!!!!! Kaçıncı ödev olduğu !!!!!!
* 23/08/2020
* Melisa Çakmak
*/
#ifndef Stack_h
#define Stack_h

#include <iostream>
#include <cstring>
using namespace std;

//constant declaration
const unsigned int MAX_SIZE = 50;

class Stack {
public:
    Stack();
    void Push( char );
    char Pop();
    void Print();

private:
    char stack[MAX_SIZE+1];
    int top;
};

#endif