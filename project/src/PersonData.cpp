/**
* PersonData.cpp 
* PersonData veri tipinin PersonData.h headırından implement edilmesidir. Person data ile alakalı bir kaç işlemi içerir.
* @course !!!!!!! Dersi aldığınız eğitim türü ve grup !!!!!!!!!
* @assignment !!!!!!! Kaçıncı ödev olduğu !!!!!!
* 23/08/2020
* Melisa Çakmak
*/

#include "../include/PersonData.h"
using namespace std;

// Empty PersonData constructer (ağaçta ilk üretilen root nodu için)
PersonData::PersonData()
{
    name = "";
    age =  -1;
    weight = -1;
}
// PersonData construcer with person data
PersonData::PersonData(string _name, int _age, int _weight)
{
    name = _name;
    age = _age;
    weight = _weight;
    /*cout << name << ", " << age << ", " << weight << endl;*/
}
// PersonData ların eşitsizliğini kıyaslayan operator
bool operator!= ( PersonData & lhs, PersonData & rhs )
{
    if(lhs.name == rhs.name && lhs.age == rhs.age && lhs.weight == rhs.weight )
        return false;
    else
        return true;
}