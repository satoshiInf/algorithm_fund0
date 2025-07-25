//
//  main.cpp
//  link_list14
//
//  Created by Satoshi on 7/25/25.
//

#include <iostream>

struct Node
{
    int data;
    Node* next;
    Node* prev;
    
    //Node(int val):メンバー(仮引数）、’’’’’’{};
    Node(int val):data(val),next(nullptr),prev(nullptr){};
    
};

int main()
{
    Node* head = nullptr;
    head = new Node(1);
    
    Node* second = nullptr;
    second = new Node(2);
    head-> next = second;
    second-> prev = head;
    
    Node* third = nullptr;
    third = new Node(3);
    second-> next = third;
    third-> prev = second;
    
    third-> next = nullptr;
    
    //小さい方から
    Node* current = head;
    while(current !=nullptr)
    {
        std::cout << current->data <<std::endl;
        current = current -> next;
    }
        
    //大きい方から
    current =third;
    while(current !=nullptr)
    {
        std::cout << current->data <<std::endl;
        current = current -> prev;
    }
    
    //メモリの解放
    //Node* temp = head;
    while(current !=nullptr)
    {
        Node* temp = current;
        current = current -> next;
        delete temp;
    }
    
    
    return 0;
}
