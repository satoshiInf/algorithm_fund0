/*
 ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
 ポイント）
 型＊　ポインタ　＝＆A の時
 型＊は、Aの型＊である。
 
 ✅ 公式のおさらい：

 型* ポインタ名 = &変数;
 このとき、

 Aの型が int → ポインタの型は int*

 Aの型が Node → ポインタの型は Node*

 Aの型が double → ポインタの型は double*
 ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
 型* とは何ぞや
 「構造体 Node へのポインタ（Node*）」と、
 「基本型 int へのポインタ（int*）」はどちらもポインタですが、指している対象が違うだけです。
 
 １）
 int x = 42;
 int* p = &x;  // xのアドレスをpに代入

 x:  [ 42 ]     ← 実体（int型の変数）　42はintの型を持つ
       ↑
       │
 p:  [ &x ]     ← int型のポインタ。xのアドレスを持つ

 ２）
 struct Node
 {
     int data;
     Node* next;
 };

 Node n1 = {10, nullptr};
 Node* np = &n1;  // n1のアドレスをnpに代入
 
 n1: +--------+--------+
      | data=10| next=nullptr   n1はnodeの型を持つ
      +--------+--------+
          ↑
          │
 np:   [ &n1 ]    ← Node型のポインタ。n1のアドレスを持つ
 
 つまりポインターが指し示すアドレスの型がポインターの型になる
 n1はNode型を持っている → npの型はNode*
 xはintの型を持っている → pの型はint*

 型＊　ポインタ　＝＆A の時
 型＊は、Aの型＊である。

 
 
 */

#include <iostream>

struct Node
{
    int information;
    Node* next;
    
};

int main()
{
    Node* head = nullptr;
    head = new Node;
    
    head->next = new Node;
    head->next->information =1;
    
    head->next->next = new Node;
    head->next->next-> information =2;
    
    head->next->next->next = nullptr;
    
    
    
    //出力　headを起点に動かすポインタを作る
    Node* currentNode = head;
    
    // currentNode = currentNode->nextにすることでノードを移動させる
    while(currentNode !=nullptr)
    {
        std::cout << currentNode -> information << std::endl;
        currentNode = currentNode->next;
    }
    
    

    return 0;
}
