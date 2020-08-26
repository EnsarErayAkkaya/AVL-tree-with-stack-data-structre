/**
* main.cpp 
* main dosyası 'Kisiler.txt' dosyasından verileri çeker ağaca ekler ve tüm veriler bitince postOrder ile yazdırır. 
* @course !!!!!!! Dersi aldığınız eğitim türü ve grup !!!!!!!!!
* @assignment !!!!!!! Kaçıncı ödev olduğu !!!!!!
* 23/08/2020
* Melisa Çakmak
*/

#include <iostream>
#include <fstream>
#include "../include/AVLTree.h"

using namespace std;

int main(int argc, const char * argv[])
{
    AVLTree *avlTree = new AVLTree(); // ağaç oluşturuldu

    const string delimiter = "#"; // Kisiler.txt de ayraç olarak kullanılan karakteri ata

    string line;
    
    ifstream myfile ("../Kisiler.txt"); // dosyaya eriş
    
    if (myfile.is_open()) // eğer dosyayı açabildiysen
    {
        while ( getline (myfile,line) ) // ilk satırı okur
        {
            string _name;
            int _age;
            int _weight;

            size_t pos = 0;
            
            // veriler okunur ve formatlanır           
            // get name
            pos = line.find(delimiter);
            _name = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            //
            
            // get age
            pos = line.find(delimiter);
            _age = stoi( line.substr(0, pos) );
            _age = 2020 - _age;
            line.erase(0, pos + delimiter.length());
            //
            
            // get weight
            _weight = stoi(line);
            //
            
            PersonData *person = new PersonData(_name, _age, _weight); // PersonData ve pointerını oluştur
                           
            avlTree->insert(person); // ağaca ekle
        
            avlTree->updateNodesPostOrder(avlTree->root); // ekleme ve dengeleme işleminden sonra UpdatesNodeOostOrder ı çağır

            avlTree->turn += 1; // yeni tura geç

            person = nullptr;//pointerı null yap
            delete person;// ve sil
        }
        
        myfile.close();// dosyatı kapat
    }
    else
        cout << "Dosya bulunamıyor veya açılamıyor"; 

    avlTree->printPostOrder(avlTree->root); // postOrder şeklinde tüm verileri ekrana yazdır

    //Burası entera basınca kapanmasını sağlıyor consolda çalıştırılırsa bunu aktif ediniz
    //ancak ödevde "ekrana yazdırılıp kapansın" dendiği için ben yoruma alıyorum.

    /* std::cin.ignore(std::cin.rdbuf()->in_avail());
    std::cout << "press enter to close\n";
    std::cin.ignore(); */
}