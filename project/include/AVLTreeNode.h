/**
* AVLTreeNode.h 
* AVLTreeNode.cpp dosyasının header dosyasıdır, avl ağacının düğümlerini oluşturan yapıyı tutar.
* @course !!!!!!! Dersi aldığınız eğitim türü ve grup !!!!!!!!!
* @assignment !!!!!!! Kaçıncı ödev olduğu !!!!!!
* 24/08/2020
* Melisa Çakmak
*/
#ifndef AVLTreeNode_h
#define AVLTreeNode_h

#include <string>
#include <algorithm>
#include "Stack.h"
#include "PersonData.h"

class AVLTreeNode {
    int lastHeight;
    
    public:
        int height;
        int lastEditedTurn;
        bool isJustCreated;
        bool isRotated;

        AVLTreeNode *left;
        AVLTreeNode *right;

        AVLTreeNode(PersonData *value, int _turn);
        void Print();

        AVLTreeNode* left_rotate(int turn);
        AVLTreeNode* right_rotate(int turn);

        void PushNewState(int turn);
        void updateValues(int turn);
        int balanceFactor(); 

        PersonData* personData; // holds persons datas addres
        Stack stack;    
};

#endif