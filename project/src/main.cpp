#include <iostream>
#include <fstream>
#include "../lib/AVLTree.h"
#include "AVLTree.cpp"

using namespace std;

int main(int argc, const char * argv[])
{
    AVLTree *avlTree = new AVLTree();

    const string delimiter = "#";

    string line;
    
    ifstream myfile ("../Kisiler.txt");
    
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            string _name;
            int _age;
            int _weight;

            size_t pos = 0;
            
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
            PersonData *person = new PersonData(_name, _age, _weight);
            try
            {                
                cout << "\n"<< person->name << ": eklendi" << endl;
                avlTree->insert(*person);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }

            try
            {
                avlTree->updateNodesPostOrder(avlTree->root);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            avlTree->turn += 1;
        }
        
        myfile.close();
    }
    else
        cout << "Unable to open file"; 

    avlTree->printPostOrder(avlTree->root);
}