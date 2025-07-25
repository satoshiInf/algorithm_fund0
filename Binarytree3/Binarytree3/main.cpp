
 //BFS
 


#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value): data(value), left(nullptr),right(nullptr){};
    
};


//小さいは左、大きいは右　→   左＜ptr＜右という関係を作る
Node* insert(Node* root, int value)
{
    if(root == nullptr)
    {
        return new Node(value);//存在しない時に数字をおく
    }
    if(value < root-> data)
    {
        root-> left = insert(root->left, value);//一個下で再度
    }
    else
    {
        root-> right = insert(root->right, value);//一個下で再度
    }
    return root;//更新した場所をrootに代入する
    
}

/*
 
     5
    / \
   3   7
  / \
 1   4
 
 
 */


void inorder(Node* root)
{
    if(root == nullptr) return; //nullptrで終了
    inorder(root->left); //一段下を実行　→新しい現在地（左側）の出力 + 左側１個下を実行
    std::cout<< root-> data << std::endl; //現在地の出力
    inorder(root->right);//一段下を実行　→新しい現在地（右側）の出力 + 右側１個下を実行
    
}

int main()
{
    Node* root = nullptr;
    
    // 10-> 3 ->7 ->1 -> 4
    
    root = insert(root, 5); //rootがNode*だから
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    insert(root, 4);
    
    inorder(root);
    std::cout<< std::endl;
    
    

    
    return 0;
}
