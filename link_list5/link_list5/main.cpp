/*
 
 問題③：3ノードをループで表示せよ（基本構造）
 📋 内容：
 * data = 1, 2, 3 のノードを順につなげる
 * while 文で全ノードの data を表示（nullptr まで）
 * 最後に delete で全ノードのメモリ解放を行う
 
 
 */

#include <iostream>

struct Node
{
    
    int data;
    Node* next;
};

//間違っているコード
int main()
{
    //null
    Node* head = nullptr;
    head = new Node;
    
    //1
    head -> next = new Node;
    head -> next -> data =1;
    
    //2
    head -> next ->next = new Node;
    head -> next ->next -> data =2;
    
    //3
    head -> next ->next -> next = new Node;
    head -> next ->next -> next ->data =3;
    
    delete head -> next ->next -> next;
    delete head -> next ->next;
    delete head -> next;

    return 0;
}

/*

  
  問題③：3ノードをループで表示せよ（基本構造）
  📋 内容：
  * data = 1, 2, 3 のノードを順につなげる
  * while 文で全ノードの data を表示（nullptr まで）
  * 最後に delete で全ノードのメモリ解放を行う
  
  
 / *
 
  正しくは
 
 #include <iostream>
 struct Node
 {
     
     int data;
     Node* next;
 };


 int main()
 {
     //null
     Node* head = nullptr;
     head = new Node;
     head -> data =0;
     
     //1
     head -> next = new Node;
     head -> next -> data =1;
     
     //2
     head -> next ->next = new Node;
     head -> next ->next -> data =2;
     
     //3
     head -> next ->next -> next = new Node;
     head -> next ->next -> next ->data =3;
 
    //末尾にnullを書く
     head -> next ->next -> next ->next =nullptr;
     
     delete head -> next ->next -> next;
     delete head -> next ->next;
     delete head -> next;

     return 0;
 }

 */
