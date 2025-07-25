/*
問題3：3ノードの連結とwhileループでのデータ出力と解放
* 3つのノードを連結し、それぞれに 1, 2, 3 の値を入れる
* while ループで head から全ノードの data を表示
* while ループで全ノードをdeleteして解放
*/

#include <iostream>

struct Node
{
    int data;
    Node* next;
};

int main()
{
    Node* head = nullptr;
    head = new Node;
    head->data = 1;
    
    //next自体がNodeへのポインターであることは内部で宣言されているのでNode*が不要
    head->next = nullptr;
    head->next = new Node;
    head ->next->data =2;
    
    head->next->next = nullptr;
    head->next->next = new Node;
    head->next->next->data =3;
    
    head->next->next-> next = nullptr;
    
    //出力
    Node* current = head;
    while(current != nullptr)
    {
        std::cout<< current->data << std::endl;
        current = current-> next;
    }
    
    //currentの値を元に戻す
    current = head;
    
    //ヒープの解放
    
    while(current != nullptr)
    {
        Node* deletePtr = current;
        current = current->next;
        delete deletePtr;
    }

    /*
    delete head->next->next-> next;
    delete head->next->next;
    delete head->next;
    delete head;
    */
    
    return 0;
}
