//
//  main.cpp
/*
 ノーマルなバイナリーツリー（Binary Tree）
 * 「各ノードが最大2つの子を持つ」基本構造
 * 値の大小などのルールはなし
 * 木構造の基本形なので、すべての派生構造の土台になる
 * コードでノードを作ったり、親・左・右を辿る構造を作れるようにする
 */
//

#include <iostream>


struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr), right(nullptr){};// 末端にnullptrをいれる
};

void deleteTree(Node* root)
{
    if(root == nullptr)
        return;
    deleteTree(root->right);
    deleteTree(root->left);
    delete root;
}

int main()
{
    //手動でtreeを作る。
    Node* root = new Node(1);
    root-> left = new Node(2);
    root-> right = new Node(3);
    
    deleteTree(root); //メモリの解放
    
    
    return 0;
}
