//
//  main.cpp
//  binaryTree4_normalBinaryTree_DFS2

/*
 
 「深さ優先探索（DFS）」 の3つのパターン（Preorder・Inorder・Postorder）を使って、バイナリーツリーをたどる学習用コード。
 DFSは探索する順番に重点を置いている
 
 
       4
      / \
      2   6
     / \ / \
    1  3 5  7

 | 探索順       | 出力される順番                      |
 | --------- | ---------------------------- |
 | Preorder  | `4 2 1 3 6 5 7`              |
 | Inorder   | `1 2 3 4 5 6 7` ← BSTではこれが昇順 |
 | Postorder | `1 3 2 5 7 6 4`              |
 
 数値の順序を紙に書こう
 
 // Preorder（前順）: 自分 → 左 → 右
 void preorder(Node* root) {
     if (root == nullptr) return;
     std::cout << root->data << " ";
     preorder(root->left);
     preorder(root->right);
 }

 // Inorder（中間順）: 左 → 自分 → 右
 void inorder(Node* root) {
     if (root == nullptr) return;
     inorder(root->left);
     std::cout << root->data << " ";
     inorder(root->right);
 }

 // Postorder（後順）: 左 → 右 → 自分
 void postorder(Node* root) {
     if (root == nullptr) return;
     postorder(root->left);
     postorder(root->right);
     std::cout << root->data << " ";
 }
 
 
 #include <iostream>

 struct Node {
     int data;
     Node* left;
     Node* right;
     Node(int val): data(val), left(nullptr), right(nullptr) {};
 };

 void preorder(Node* root) {
     if (!root) return;
     std::cout << root->data << std::endl;
     preorder(root->left);
     preorder(root->right);
 }

 void inorder(Node* root) {
     if (!root) return;
     inorder(root->left);
     std::cout << root->data << std::endl;
     inorder(root->right);
 }

 void postorder(Node* root) {
     if (!root) return;
     postorder(root->left);
     postorder(root->right);
     std::cout << root->data << std::endl;
 }

 int main() {
     Node* root = new Node(4);
     root->left = new Node(2);
     root->right = new Node(6);
     root->left->left = new Node(1);
     root->left->right = new Node(3);
     root->right->left = new Node(5);
     root->right->right = new Node(7);

     std::cout << "Preorder:\n";
     preorder(root);
     std::cout << "\nInorder:\n";
     inorder(root);
     std::cout << "\nPostorder:\n";
     postorder(root);

     return 0;
 }

 
 */


#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr), right(nullptr){};
    
};

void preorder(Node* root)
{
    if(!root) return;
    std::cout<< root -> data << std::endl;
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if(!root) return;
    inorder(root->left);
    std::cout<< root -> data << std::endl;
    inorder(root->right);
}

void postorder(Node* root)
{
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    std::cout<< root -> data << std::endl;
}

int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    
    
    preorder(root);
    std::cout<<"\n";
    inorder(root);
    std::cout<<"\n";
    postorder(root);
    
    
    return 0;
}
