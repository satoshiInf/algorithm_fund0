/*
 ダブルリンクリスト
 */

#include <iostream>

struct Node
{
    int data;
    Node* prev;
    Node* next;
    //constractor
    Node(int val): data(val), prev(nullptr), next(nullptr){};
    
};

int main()
{
    
    Node* head = nullptr;
    head = new Node(1);
    
    //左右から位置関係を作る
    Node* second = new Node(2);
    head->next = second;
    second->prev =head;
    
    Node* third = new Node(3);
    second->next = third;
    third -> prev = second;
    
    third->next = nullptr;
    
    //小さい方から出力
    Node* current =head;
    while(current != nullptr)
    {
        std::cout << current-> data << std::endl;
        current = current->next;
    }
    
    std::cout << "\n";
    
    //大きい方から出力
    current=third;
    while(current != nullptr)
    {
        std::cout << current-> data << std::endl;
        current = current->prev;
    }
    
    current = head;
    
    while(current !=nullptr )
    {
        Node* temporary = current;
        current = current->next;
        delete temporary;
    }
    
   
    return 0;
}
