/**
* AVLTree.h 
* AVLTree.cpp dosyasının header dosyasıdır, avl ağaç sistemini tutar.
* @course !!!!!!! Dersi aldığınız eğitim türü ve grup !!!!!!!!!
* @assignment !!!!!!! Kaçıncı ödev olduğu !!!!!!
* 24/08/2020
* Melisa Çakmak
*/
#ifndef AVLTree_h
#define AVLTree_h

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "AVLTreeNode.h"

class AVLTree {    
    void balance(std::vector<AVLTreeNode**> path);
    
    public:
        AVLTree();
        
        AVLTreeNode *root;

        int turn = 0; // bu değer her yeni düğüm ve stateler eklendikten sonra artar ve
                        // düğümleri birden fazla update edilmemelerini ve oluşturuldukları zaman yeni state eklenmemesini sağlar
        
        void updateNodesPostOrder(AVLTreeNode* node);
        
        void printPostOrder(AVLTreeNode* node);

        void insert(PersonData value);
};

#endif /* AVLTree_hpp */