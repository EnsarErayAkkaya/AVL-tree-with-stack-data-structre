#ifndef AVLTree_h
#define AVLTree_h

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "AVLTreeNode.h"

class AVLTree {
    int _size;
    
    void balance(std::vector<AVLTreeNode**> path);
    
public:
    AVLTree();
    ~AVLTree();
    
    AVLTreeNode *root;

    int turn = 0;
    void updateNodesPostOrder(AVLTreeNode* node);
    
    void printPostOrder(AVLTreeNode* node);

    void display(AVLTreeNode* cur, int depth=0, int state=0);

    void insert(PersonData value);
    void erase(PersonData value);
    
    void clear();
    bool empty() const;
    int size() const;
    
    int find(PersonData value) const;
    int lower_bound(PersonData value) const;
    int upper_bound(PersonData value) const;
    
    const PersonData& find_min() const;
    const PersonData& find_max() const;
    const PersonData& operator[](std::size_t idx) const;
    
    void display();
};

#endif /* AVLTree_hpp */