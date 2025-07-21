
/*
 問題①：1ノードだけ作って出力せよ
 📋 内容：
 Node 構造体を定義する
 head ノードを動的に作り、data = 42 を入れる
 next は nullptr にする
 その data を cout で出力
 最後に delete


 
 */

#include <iostream>

//一つ目のノードで見ると　矢印と値が必要
struct Node
{
    int data;
    Node* next;
    
};

int main()
{
    //int data;
    //Node* next;
    
    //head は最初のノードのアドレスを持つ。
    //Node* head = NULL;
    
    //Node* next= new Node;
    //先頭のポインタの作成、動的に管理
    Node* head = new Node;
    
    
    /*
     head
     
     対象 headを元に取得していくよ
     */
    
    head->data =42;
    head-> next = NULL;
    
    std::cout << head ->data << std::endl;
    
    delete head;
    
    
    
    return 0;
}
