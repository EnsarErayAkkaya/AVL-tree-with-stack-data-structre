/**
* Stack.cpp 
* Stack veri tipinin Stack.h headırından implement edilmesidir. Stack Methodlarını içerir.
* @course !!!!!!! Dersi aldığınız eğitim türü ve grup !!!!!!!!!
* @assignment !!!!!!! Kaçıncı ödev olduğu !!!!!!
* 23/08/2020
* Melisa Çakmak
*/

#include "../lib/PersonData.h"
using namespace std;

PersonData::PersonData()
{
    name = "";
    age =  -1;
    weight = -1;
}

PersonData::PersonData(string _name, int _age, int _weight)
{
    name = _name;
    age = _age;
    weight = _weight;
    /*cout << name << ", " << age << ", " << weight << endl;*/
}

bool operator!= ( PersonData & lhs, PersonData & rhs )
{
    if(lhs.name == rhs.name && lhs.age == rhs.age && lhs.weight == rhs.weight )
        return false;
    else
        return true;
}