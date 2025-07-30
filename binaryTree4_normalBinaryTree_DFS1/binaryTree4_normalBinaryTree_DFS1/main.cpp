/*
 
 DFS
 
 | 探索順       | 出力される順番                      |
 | --------- | ---------------------------- |
 | Preorder  | `4 2 1 3 6 5 7`              |
 | Inorder   | `1 2 3 4 5 6 7` ← BSTではこれが昇順 |
 | Postorder | `1 3 2 5 7 6 4`              |


 問題：
以下の木構造を作り、中間順（Inorder）探索でノードの値を出力してください。

markdown
コピーする
編集する
      4
     / \
    2   6
   / \ / \
  1  3 5  7
🔸 要件：
ノード構造体 Node を定義すること

ツリーを手動で作成すること

中間順探索で出力（期待される順番：1 2 3 4 5 6 7）

 */
//

#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;
    
    Node(int val): data(val),left(nullptr),right(nullptr){};
    
};

void inorder(Node* root)
{
    if(root == nullptr) return;
    inorder(root-> left);
    std::cout << root-> data << std::endl;
    inorder(root-> right);
}

void deleteTree(Node* root)
{
    if(root == nullptr) return;
    deleteTree(root->right);
    deleteTree(root->left);// 消すのは右、左、親の順
    delete root;
}

int main()
{
    Node* root =new Node(4);
    root->left =new Node(2);
    root->left->left =new Node(1);
    root->left->right =new Node(3);
    root->right = new Node(6);
    root->right->left =new Node(5);
    root->right->right =new Node(7);
    
    
    inorder(root);
    
    
    deleteTree(root);
    
   
    return 0;
}
