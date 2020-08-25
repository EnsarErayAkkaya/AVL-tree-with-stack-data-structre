/**
* AVLTreeNode.cpp 
* AVLTreeNode veri tipinin AVLTreeNode.h headırından implement edilmesidir. AVL ağaç nodelarının fonksyonlarını barındırır. node ların dönme fonksyonlarını da barındırır.
* @course !!!!!!! Dersi aldığınız eğitim türü ve grup !!!!!!!!!
* @assignment !!!!!!! Kaçıncı ödev olduğu !!!!!!
* 23/08/2020
* Melisa Çakmak
*/

#include "../include/AVLTreeNode.h"
#include "PersonData.cpp"
#include "Stack.cpp"

// AVLTreeNode const. PersonData ve turn verisi alır turn (turn verisi anlamak için AVLTree.h dosyasına bakınız)
AVLTreeNode::AVLTreeNode(PersonData value, int _turn){

    personData = value;
    stack = Stack();

    height = 1;
    lastHeight = 1;
    lastEditedTurn = _turn;
    isJustCreated = true;
    isRotated = false;
    
    left = nullptr;
    right = nullptr;
}
// AVLTreeNode daki PersonData verisini consola yazar
void AVLTreeNode::Print()
{
    cout << personData.name << " : "<<  personData.age << " : " << personData.weight << "   Stack: "; 
    stack.Print(); // stacki ekrana basmak için çağırır
    cout << endl; 
}
//AVLTreeNode daki stacke yeni durumunu ekler
void AVLTreeNode::PushNewState(int turn)
{
    // eğer son dokunulan tur bu değilse tur değilse bu tur oluşmamıştır
    if(lastEditedTurn != turn)
    {   
        isJustCreated = false;
    }

    // bu tur oluştuysa bir şey yapma
    if ( isJustCreated == true )
    {
        lastHeight = height;
        return;
    }   
    if(isRotated == false)
    {
        lastHeight = height;
        stack.Push('D');
        return;
    }
    //eğer bu tur ilk kez giriyorsan
    if(lastEditedTurn != turn)
    {
      /*   // tur farkını hesapla 0 dan büyükse, kaç tur girmediyseno kadar 'D' ekle çünkü kıpırdamadın. 
        if(turn-lastEditedTurn-2 > 0)
        {
            cout<<turn-lastEditedTurn<< endl;
            for (size_t i = 0; i < (turn-lastEditedTurn+1); i++)
            {
                stack.Push('D');
            }
        } */
        // turu eşitle
        lastEditedTurn = turn;

        // yeni state i push et
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
    // yeni yüksekliğini kaydet
    lastHeight = height;
    // döndü mü değerini sıfırla
    this->isRotated = false;
}

// height değerini günceller
void AVLTreeNode::updateValues(int turn)
{ 
    height = std::max(left != nullptr ? left->height : 0,
            right != nullptr ? right->height : 0) + 1;  
}
// sağ ve sol subtree ler arasında ne kadar yükseklik farkı oldupunu döndürür
int AVLTreeNode::balanceFactor(){
    return (left != nullptr ? left->height : 0) - (right != nullptr ? right->height: 0);
}
// düğümü sola döndürür
AVLTreeNode* AVLTreeNode::left_rotate(int turn){
    AVLTreeNode* R = right;
    right = right->left;
    R->left = this;

    this->isRotated = true;
    R->isRotated = true;
    
    this->updateValues(turn);  // bu update sırası önemli önce alttakini değiştirmeli
    R->updateValues(turn);     // ki bu doğru hesaplansın
    
    return R;
}
// düğümü sağa döndürür
AVLTreeNode* AVLTreeNode::right_rotate(int turn){
    AVLTreeNode* L = left;
    left = left->right;
    L->right = this;

    this->isRotated = true;
    L->isRotated = true;
    
    this->updateValues(turn);  // bu update sırası önemli önce alttakini değiştirmeli
    L->updateValues(turn);     // ki bu doğru hesaplansın
    
    return L;
}