

#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr), right(nullptr){};
};

Node* insert(Node* root, int val)
{
    //valはカーソルが保持する数値
    if(root == nullptr) return new Node(val);
    if( val < root->data) //左
    {
        root-> left = insert( root-> left, val);
    }
    else //右
    {
        root-> right = insert(root->right, val);
    }
    return root;
}

void displayByinOrder(Node* root)
{
    if(!root) return; //ここでポインタが何も指していない時終わり
    displayByinOrder(root-> left);
    std::cout << root-> data <<" ";
    displayByinOrder(root-> right);
}

int main()
{
    Node* root = nullptr;
    int arr[] = {1,7,3,8,5};
    //bstInsert(root,val);
    for(int val :arr)
    {
        root = insert(root,val);
    }
    
        displayByinOrder(root);
    
    
   
    return 0;
}
