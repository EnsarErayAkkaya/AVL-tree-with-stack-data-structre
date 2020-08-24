#include "../lib/AVLTree.h"
#include "AVLTreeNode.cpp"

AVLTree::AVLTree(){
    root = nullptr;
    _size = 0;
}

AVLTree::~AVLTree(){
    clear();
}


void AVLTree::clear(){
    std::vector<AVLTreeNode*> stack;
    
    if (root != nullptr)
        stack.push_back(root);
    
    while (!stack.empty()){
        AVLTreeNode *node = stack.back();
        stack.pop_back();
        
        if (node->left != nullptr)
            stack.push_back(node->left);
        
        if (node->right != nullptr)
            stack.push_back(node->right);
        
        _size--;
        delete node;
    }
    
    root = nullptr;
}

void AVLTree::insert(PersonData value){
    AVLTreeNode **indirect = &root;  // to generalize insertion
    std::vector<AVLTreeNode**> path;  // to update height values
    
    while (*indirect != nullptr){
        path.push_back(indirect);
        
        if ((*indirect)->personData.age >= value.age)
            indirect = &((*indirect)->left);
        else
            indirect = &((*indirect)->right);
    }
    
    *indirect = new AVLTreeNode(value, turn);
    path.push_back(indirect);
    
    cout<< turn << endl;
    balance(path);
    _size++;
 
}

void AVLTree::erase(PersonData value){
    AVLTreeNode **indirect = &root;  // to generalize insertion
    std::vector<AVLTreeNode**> path;  // to update height values
    
    while (*indirect != nullptr && (*indirect)->personData != value){
        path.push_back(indirect);
        
        if ((*indirect)->personData.age >= value.age)
            indirect = &((*indirect)->left);
        else
            indirect = &((*indirect)->right);
    }
    
    if (*indirect == nullptr)  // the value does not exist in tree
        return;  // may be raising an Exception is more elegant
    
    else
        path.push_back(indirect);
    
    std::size_t index = path.size();
    
    if ((*indirect)->left == nullptr && (*indirect)->right == nullptr){  // the node is leaf
        delete *indirect;  // just delete node
        *indirect = nullptr;
        path.pop_back();  // pop the deleted node from path
    }
    
    else if ((*indirect)->right == nullptr){  // only left child exists
        AVLTreeNode *toRemove = *indirect;
        
        (*indirect) = (*indirect)->left;
        delete toRemove;
        
        path.pop_back();
    }
    
    else{  // right child exists
        AVLTreeNode **successor = &((*indirect)->right);
        
        while ((*successor)->left != nullptr){
            path.push_back(successor);
            successor = &((*successor)->left);
        }
        
        if (*successor == (*indirect)->right){
            (*successor)->left = (*indirect)->left;
            
            AVLTreeNode *toRemove = *indirect;
            *indirect = *successor;
            delete toRemove;
        }
        
        else{
            AVLTreeNode *tmp = *path.back(), *suc = *successor;
            
            tmp->left = (*successor)->right;
            suc->left = (*indirect)->left;
            suc->right = (*indirect)->right;
            
            delete *indirect;
            *indirect = suc;
            path[index] = &(suc->right);
        }
    }
    
    balance(path);
    _size--;
}

void AVLTree::balance(std::vector<AVLTreeNode**> path)
{  // starting from root
    
    std::reverse(path.begin(), path.end());
    
    for (auto indirect: path){
        (*indirect)->updateValues(turn);
        
        if ((*indirect)->balanceFactor() >= 2 && (*indirect)->left->balanceFactor() >= 0)   // left - left
            *indirect = (*indirect)->right_rotate(turn);
        
        else if ((*indirect)->balanceFactor() >= 2){  // left - right
            (*indirect)->left = (*indirect)->left->left_rotate(turn);
            *indirect = (*indirect)->right_rotate(turn);
        }
        
        else if ((*indirect)->balanceFactor() <= -2 && (*indirect)->right->balanceFactor() <= 0)  // right - right
            *indirect = (*indirect)->left_rotate(turn);
        
        else if ((*indirect)->balanceFactor() <= -2){  // right - left
            (*indirect)->right = ((*indirect)->right)->right_rotate(turn);
            *indirect = (*indirect)->left_rotate(turn);
        }
    }     
}

bool AVLTree::empty() const{
    return _size == 0;
}


int AVLTree::size() const{
    return _size;
}

int AVLTree::find(PersonData value) const{
    AVLTreeNode *direct = root;
    int idx = 0;
    
    while (direct != nullptr && direct->personData != value){
        if (direct->personData.age >= value.age)
            direct = direct->left;
        else{
            idx += (direct->left ? direct->left->count : 0) + 1;
            direct = direct->right;
        }
    }
    
    if (direct == nullptr)
        return -1;
    
    else
        return idx + (direct->left ? direct->left->count : 0);
}

int AVLTree::upper_bound(PersonData value) const{
    AVLTreeNode *direct = root;
    int idx = 0;
    
    while (direct != nullptr){
        if (direct->personData.age >= value.age)
            direct = direct->left;
        else{
            idx += (direct->left ? direct->left->count : 0) + 1;
            direct = direct->right;
        }
    }
    
    return idx;
}

int AVLTree::lower_bound(PersonData value) const{
    AVLTreeNode *direct = root;
    int idx = 0;
    
    while (direct != nullptr){
        if (direct->personData.age >= value.age)
            direct = direct->left;
        else{
            idx += (direct->left ? direct->left->count : 0) + 1;
            direct = direct->right;
        }
    }
    
    return idx;
}

const PersonData& AVLTree::find_min() const{
    AVLTreeNode *cur = root;
    
    while (cur->left != nullptr)
        cur = cur->left;
    
    return cur->personData;
}

const PersonData& AVLTree::find_max() const{
    AVLTreeNode *cur = root;
    
    while (cur->right != nullptr)
        cur = cur->right;
    
    return cur->personData;
}

const PersonData& AVLTree::operator[](std::size_t idx) const{
    AVLTreeNode *cur = root;
    int left = cur->left != nullptr ? cur->left->count : 0;
    
    while (left != idx){
        if (left < idx){
            idx -= left + 1;
            
            cur = cur->right;
            left = cur->left != nullptr ? cur->left->count : 0;
        }
        
        else{
            cur = cur->left;
            left = cur->left != nullptr ? cur->left->count : 0;
        }
    }
    
    return cur->personData;
}

void AVLTree::display(){
    printf("\n");
    if (root != nullptr)
        display(root);
    else
        printf("Empty");
    printf("\n");
}

void AVLTree::display(AVLTreeNode *cur, int depth, int state)
{  // state: 1 -> left, 2 -> right , 0 -> root
    try
    {
        if (cur->left)
        display(cur->left, depth + 1, 1);
    
        for (int i=0; i < depth; i++)
            printf("     ");
        
        if (state == 1) // left
            printf("┌───");
        else if (state == 2)  // right
            printf("└───");
        
        std::cout << "[" << cur->personData.name << "] - (" << cur->count << ", " << cur->height << ")" << std::endl;
        
        if (cur->right)
            display(cur->right, depth + 1, 2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void AVLTree::printPostOrder(AVLTreeNode *node)
{
    if (node == NULL) 
        return; 

    // first recur on left subtree 
    printPostOrder(node->left); 

    // then recur on right subtree 
    printPostOrder(node->right); 

    // now deal with the node 
    node->Print();
}
void AVLTree::updateNodesPostOrder(AVLTreeNode *node)
{
    if (node == NULL) 
        return; 

    // first recur on left subtree 
    updateNodesPostOrder(node->left); 

    // then recur on right subtree 
    updateNodesPostOrder(node->right);

    node->PushNewState(turn);
}
    
