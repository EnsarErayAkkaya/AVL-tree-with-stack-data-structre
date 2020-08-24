#ifndef AVLTreeNode_h
#define AVLTreeNode_h

#include <string>
#include <algorithm>
#include "Stack.h"
#include "PersonData.h"

class AVLTreeNode {
    int lastHeight;
    
    public:
        int count;  // how many nodes are there in this subtree
        int height;
        int lastEditedTurn;
        bool isJustCreated;
        bool isRotated;

        AVLTreeNode *left;
        AVLTreeNode *right;

        AVLTreeNode(PersonData value, int _turn);
        void Print();

        AVLTreeNode* left_rotate(int turn);
        AVLTreeNode* right_rotate(int turn);

        void PushNewState(int turn);
        void updateValues(int turn);
        int balanceFactor(); 

        PersonData personData; // holds persons data
        Stack stack;    
};

#endif