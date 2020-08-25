/**
* PersonData.h 
* PersonData.cpp dosyasının header dosyasıdır, kişiler.txt den gelen verileri tutar.
* @course !!!!!!! Dersi aldığınız eğitim türü ve grup !!!!!!!!!
* @assignment !!!!!!! Kaçıncı ödev olduğu !!!!!!
* 24/08/2020
* Melisa Çakmak
*/
#ifndef PersonData_h
#define PersonData_h

#include <iostream>
#include <string>

class PersonData{
    public:
        friend bool operator== (PersonData & lhs, PersonData & rhs );

        PersonData();
        PersonData(std::string _name, int _age, int _weight);
        
        std::string name;
        int age;
        int weight;
};
#endif