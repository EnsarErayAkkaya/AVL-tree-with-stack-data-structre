/**
* AVLTree.cpp 
* AVLTree veri tipinin AVLTree.h headırından implement edilmesidir. AVL ağaç fonksyonlarını barındırır. Ağaca veri ekleme, postorder yazdırmagibi temel methodlardan oluşur. 
* @course !!!!!!! Dersi aldığınız eğitim türü ve grup !!!!!!!!!
* @assignment !!!!!!! Kaçıncı ödev olduğu !!!!!!
* 23/08/2020
* Melisa Çakmak
*/

#include "../include/AVLTree.h"

// constructer
AVLTree::AVLTree(){
    root = nullptr;
}

// yeni düğüm ekler
void AVLTree::insert(PersonData value)
{
    AVLTreeNode **indirect = &root;                   // rootun konumunu bir pointera kaydet
    std::vector<AVLTreeNode**> path;                  // daha sonra ağacı dengelemek için dolaşılan düğümlerin listesi
    
    while (*indirect != nullptr)                      // eğer boş değilse
    {
        path.push_back(indirect);                     // düğümü listeye ekle
        
        if ((*indirect)->personData.age >= value.age) // eğer yaşı küçük ve ya eşitse sola git
            indirect = &((*indirect)->left);
        else                                          // büyükse sağa git
            indirect = &((*indirect)->right);
    }
    
    *indirect = new AVLTreeNode(value, turn);         // düğümü oluştur ve en sonunda elinde kalan boş konuma ekle
    
    path.push_back(indirect);                         // yeni eklediğin düğümüde listeye ekle
    
    balance(path);                                    // ağacı dengele
}

// AVL ağacını dengeler
void AVLTree::balance(std::vector<AVLTreeNode**> path)
{  
    std::reverse(path.begin(), path.end());  // pathi ters çevir ki en alttan başlayabilelim
    
    for (auto indirect: path)   // path teki her Node için
    {
        (*indirect)->updateValues(turn);                // yükseklik değerini güncelle
        
        if ((*indirect)->balanceFactor() >= 2 && (*indirect)->left->balanceFactor() >= 0)    // balance faktörleri kontroler ediliyor
            *indirect = (*indirect)->right_rotate(turn);  // left - left
        
        else if ((*indirect)->balanceFactor() >= 2)                                         
        { 
            (*indirect)->left = (*indirect)->left->left_rotate(turn);   // left - right
            *indirect = (*indirect)->right_rotate(turn);
        }
        
        else if ((*indirect)->balanceFactor() <= -2 && (*indirect)->right->balanceFactor() <= 0)  
            *indirect = (*indirect)->left_rotate(turn);     // right - right
        
        else if ((*indirect)->balanceFactor() <= -2) 
        {  
            (*indirect)->right = ((*indirect)->right)->right_rotate(turn);// right - left
            *indirect = (*indirect)->left_rotate(turn);
        }
    }     
}
// Ağacı postOrder şeklinde gezer ve değerleri yazdırır 
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
// Ağacı post order şeklinde gezer ve node ların yeni statelerini ekler
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
    
