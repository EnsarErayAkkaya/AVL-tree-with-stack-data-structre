/**
* Stack.cpp 
* Stack veri tipinin Stack.h headırından implement edilmesidir. Stack Methodlarını içerir.
* @course !!!!!!! Dersi aldığınız eğitim türü ve grup !!!!!!!!!
* @assignment !!!!!!! Kaçıncı ödev olduğu !!!!!!
* 23/08/2020
* Melisa Çakmak
*/

#include "../include/Stack.h"
using namespace std;

// Constructer
Stack::Stack()
{
  stack[0] = 'O';
  top = 1;
}

// stackteki verileri pop methodunu kullanarak(son eklenenden başa) consola basar
void Stack::Print()
{
  while (top > 0)
  {
      cout << Pop();
  }
}

// Push method, yeni bir eleman ekler
void Stack::Push(char val)
{
  stack[top] = val;
  top = top + 1;
}

// Pop method, en üst elemanı çıkartır
char Stack::Pop()
{
  top = top - 1;
  char temp = stack[top];
  stack[top] = '\0';
  return (temp);
}