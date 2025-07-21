//
//  main.cpp
//  link_list6
//
//  Created by Satoshi on 7/21/25.
//

#include <iostream>

struct Node
{
    int value;
    //Node* --->Node 構造体の 住所を持っている変数（ポインタ）
    Node* next;// ＝＆A
    //nextは何かわからないけど、　Nodeの箱であるAを指し示している
};

int main()
{
    //Nodeの箱を指し示すポインタhead
    
    //Nodeの箱を指し示すポインターheadは存在しない
    //ポインタheadは実在しないNodeの箱を指し示す
    Node* head = nullptr;
    
    
    head->next = new Node;
    
    head->next-> next = new Node;
    
    head->next -> next -> next= nullptr;
    
    
    delete head->next-> next;
    delete head->next ;
    delete head;
    
    
    
   
    

    return 0;
}
