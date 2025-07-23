/*
 問題1：単一ノードの作成と削除
 * Node構造体を定義
 * head に動的確保でノードを作り、data に好きな値を入れる
 * head のデータを出力する
 * 最後に delete head で解放する
 */

#include <iostream>

struct Node
{
    int data;
    Node* next; //Node型へのポインターnext
};

int main()
{
    //初期化
    Node* head = nullptr;
    
    head = new Node;
    head -> data = 0;
    
    head -> next = new Node;
    head -> next -> data =1;
    
    head -> next -> next= new Node;
    head -> next -> next-> data =2;
    
    //忘れないこと
    head -> next -> next-> next =nullptr;
    
    
    Node* current = head; //ヘッドからコピー
    while(current != nullptr)
    {
        std::cout<< current-> data << std::endl;
        current = current-> next;
    }
    
    //reset
    current = head;
    
    
    while(current != nullptr)
    {
        Node* temporaryNext = current;
        current = current -> next;
        delete temporaryNext;
    }
    
    
    return 0;
}
