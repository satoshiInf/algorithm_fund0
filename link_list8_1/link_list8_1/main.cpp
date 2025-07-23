//
//  main.cpp
//  link_list8_1
//
//  Created by Satoshi on 7/23/25.
//

#include <iostream>

struct Node
{
    public:
    int data;
    Node* next;
};


int main()
{
    //何も入ってない　指す対象がない
    Node* head = nullptr;
    
    //メモリの確保
    head = new Node;
    head -> data = 0;
    
    head-> next = new Node;
    head-> next -> data = 1;
    
    head -> next -> next = new Node;
    head -> next -> next -> data = 2;
    
    head -> next -> next -> next = nullptr;
    
    //出力
    Node* current = head;
    while(current != nullptr)
    {
        std::cout<< current->data << std::endl;
        current = current->next;
    }
    
    std::cout<< "\n" << std::endl;
    
    //whileの実行されない条件を保持してループを出るのでcurrentはnullptr
    //forとwhileを使ったらその変数の値を再度リセットする必要があり
    
    current = head;
    std::cout << "reset: " << current-> data <<std::endl;
    
    
    while(current != nullptr)
    {
        std::cout<< current << std::endl;
        current = current->next;
    }
    
    
    /*
    delete head -> next -> next -> next;
    delete head -> next -> next;
    delete head -> next;
    delete head ;
    */
    
    
    /*
    Node* temp = current;　//currentはポインタ
    これは 「current が指しているノード（＝Node構造体）のアドレス」を temp にコピーする という意味。
    つまり、temp と current は同じアドレス（同じノード）を指すポインタ
    なので *temp も *current も 同じノードの中身を見ている
     でも、current を進めたあとでも、temp には消すべきアドレスが残っている
     */
    
    //頭から削除できる　current =current->nextでポインタを保持
    while(current != nullptr)
    {
        Node* temp = current;
        current = current -> next;
        delete temp;
    }
    
    /*
     ノードをコピーする
     Node* current = head;
     Node* temp = current;

    [ノードA(data=1)] ---> [ノードB(data=2)] ---> [ノードC(data=3)] ---> nullptr
       ↑         ↑
       |         |
     temp     current
     
     current = current->next;
     [ノードA] ---> [ノードB] ---> [ノードC] ---> nullptr
        ↑               ↑
       temp          current

     | ポインタ      | 何をしているか                      |
     | --------- | ---------------------------- |
     | `current` | 現在のノードをなぞって次に進むためのポインタ       |
     | `temp`    | 今まさに delete したいノードのアドレスを一時保存 |

     
     
     */
    
    
    return 0;
}
