/**
* Stack.cpp 
* Stack veri tipinin Stack.h headırından implement edilmesidir. Stack Methodlarını içerir.
* @course !!!!!!! Dersi aldığınız eğitim türü ve grup !!!!!!!!!
* @assignment !!!!!!! Kaçıncı ödev olduğu !!!!!!
* 23/08/2020
* Melisa Çakmak
*/

#include "../lib/Stack.h"
using namespace std;

// Constructer
Stack::Stack()
{
  stack[0] = 'O';
  top = 1;
}
void Stack::Print()
{
  cout << stack;
}

// Push method, yeni bir eleman ekler
void Stack::Push(char val)
{
  stack[top] = val;
  top = top + 1;
}

// Stackin uzunluğunu veren method
int Stack::Length()
{
  cout << top << "items currently in stack" << endl;
  return (top);
}

// Stackin en son elemanını veren method
char Stack::Top()
{
  //cout << "reached Top method" << endl;
  return (stack[top - 1]);
}

// Pop method, en üst elemanı çıkartır
char Stack::Pop()
{
  top = top - 1;
  char temp = stack[top];
  stack[top] = '\0';
  return (temp);
}

// Stack boş mu
bool Stack::Empty()
{
  bool val;
  val = true;
  if (top > 0)
  {
    val = false;
  }
  return (val);
}