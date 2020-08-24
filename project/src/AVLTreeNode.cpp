#include "../lib/AVLTreeNode.h"
#include "PersonData.cpp"
#include "Stack.cpp"
AVLTreeNode::AVLTreeNode(PersonData value, int _turn){

    personData = value;
    stack = Stack();

    count = 1;
    height = 1;
    lastHeight = 1;
    lastEditedTurn = _turn;
    isJustCreated = true;
    isRotated = false;
    
    left = nullptr;
    right = nullptr;
}
void AVLTreeNode::Print()
{
    cout << personData.name << " : "<<  personData.age << " : " << personData.weight << "   Stack: "; 
    stack.Print();
    cout << endl; 
}
void AVLTreeNode::PushNewState(int turn)
{
    if(lastEditedTurn != turn)
    {   
        isJustCreated = false;
    }

    cout<< personData.name << " : " << lastHeight <<" : "<< height << " : " << lastEditedTurn << endl;

    if (isJustCreated && isRotated == false)
        return;
    
    if(lastEditedTurn != turn)
    {
        if(turn-lastEditedTurn-2 > 0)
        {
            cout<<turn-lastEditedTurn<< endl;
            for (size_t i = 0; i < (turn-lastEditedTurn+1); i++)
            {
                stack.Push('D');
            }
        }        
        lastEditedTurn = turn;

        if(lastHeight == height)
        {
            stack.Push('D');
        }
        else if(lastHeight < height)
        {
            stack.Push('Y');
        }
        else if(lastHeight > height)
        {
            stack.Push('A');
        }
    }
    cout << stack.Top() << endl;
    lastHeight = height; 
}


void AVLTreeNode::updateValues(int turn)
{   
    count = (left != nullptr ? left->count : 0) + (right != nullptr ? right->count : 0) + 1;

    height = std::max(left != nullptr ? left->height : 0,
                    right != nullptr ? right->height : 0) + 1;
}

int AVLTreeNode::balanceFactor(){
    return (left != nullptr ? left->height : 0) - (right != nullptr ? right->height: 0);
}

AVLTreeNode* AVLTreeNode::left_rotate(int turn){
    AVLTreeNode* R = right;
    right = right->left;
    R->left = this;
    
    this->isRotated = true;
    R->isRotated = true;

    cout<< personData.name << " : Rotated Left" << endl;
    
    this->updateValues(turn);  // the order is important
    R->updateValues(turn);
    
    return R;
}

AVLTreeNode* AVLTreeNode::right_rotate(int turn){
    AVLTreeNode* L = left;
    left = left->right;
    L->right = this;

    cout<< personData.name << " : Rotated Right" << endl;

    this->isRotated = true;
    L->isRotated = true;
    
    this->updateValues(turn);  // the order is important
    L->updateValues(turn);
    
    return L;
}