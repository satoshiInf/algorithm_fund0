
#include <iostream>

/*
 BSTでツリーを配置して、DFSで出力する
 */

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr),right(nullptr){};
};

/*
 | 変数           | 型       | 意味                           |
 | ------------ | ------- | ---------------------------- |
 | `root`       | `Node*` | 「今見ているノードの場所（ポインタ）」          |
 | `root->data` | `int`   | 今見ているノードが持っている値（数）           |
 | `val`        | `int`   | 挿入したい値（これと `root->data` を比較） |
 */

Node* insert(Node* root, int val) // left < root < right
{
    if(root == nullptr) return new Node(val);
    if(val < root-> data)
    {
        root-> left = insert(root-> left, val);
    }
    else
    {
        root-> right = insert(root-> right, val);
    }
    return root;
}


void printbyInorder(Node* root)
{
    if(!root) return;
    printbyInorder(root->left);
    std::cout << root-> data << std::endl;
    printbyInorder(root->right);
}


int main()
{
    Node* root = nullptr;
    int arr[] = {3,2,1,4,5}; //int arr[空] = {1, 2, 3}; のような書き方は、“定義のとき”だけ許される
    //配列でツリーを作るときはinsertの関数を作り、その関数内でnew Node;
    for(int val: arr)
    {
        root = insert(root, val);
    }
    
    printbyInorder(root);
    
    return 0;
}
