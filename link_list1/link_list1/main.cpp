/*
 リンクリストの基本構造
 struct Node a;
 struct Node* p
 p = &a;
 
 a
 address| value
 ↑
 p
 
 １）
 初期化
 指し示すものがない状態で初期化する = 指し示すものがないので値も持てない
 headがnullであるから*headを定義することができない
 
 head
  ↓
 NULL/     value= *headを定義することができない
 
 ２）
 一つノードを作った
 head
  ↓
 +-------+--------+
 |  10   |  NULL  |
 +-------+--------+
 
data =10
nextへのポインタ型 =null
 
 
 ポイント）
 nodeの方を決める時は一個めのノードの絵を見て判断する
 
 
 Node* head = new Node;
 head->data =10; //headの指し示すアドレスのdataの型に１０を代入
 head-> next = NULL; //headの指し示すアドレスのnextへのポインタ型にNULLを代入
 
 ３）
 2個目
 head
  ↓
 +-------+----------+     +-------+--------+
 |  10   |    *-----|---> |  20   |  NULL  |
 +-------+----------+     +-------+--------+
 data =10                   data =20
 nextへのポインタ型 =20        nextへのポインター型　＝NULL
 
 
 Node* head = new Node;
 head->data = 10;
 head->next = new Node;        // ここで2個目のノードを作る
 head->next->data = 20;
 head->next->next = nullptr;

 ４）
 3個目
 head
  ↓
 +-------+----------+     +-------+----------+     +-------+--------+
 |  10   |    *-----|---->|  20   |    *-----|---->|  30   |  NULL  |
 +-------+----------+     +-------+----------+     +-------+--------+

 data = 10                 data = 20             　data = 30
 nextへのポインタ型 = 20      nextへのポインタ型 = 30   nextへのポインタ型 = NULL

 
 // 1個目のノード
  Node* head = new Node;
  head->data = 10;
  head->next = nullptr;

  // 2個目のノード
  head->next = new Node;
  head->next->data = 20;
  head->next->next = nullptr;

  // 3個目のノード
  head->next->next = new Node;
  head->next->next->data = 30;
  head->next->next->next = nullptr;
 
 
    末端のポインタpは
    次のアドレスを指し示すものがない　->null
 
 
    リンクリストで書く際はこの3点セット　＋ delete処理
    Node* head = new Node; // 実体を作る（newで動的確保）
    head->data = 100;      // ここで初めて値を入れられる
    head->next = nullptr;

 
 　　delete head; // delete ポインタ名

 
 */

#include <iostream>

struct Node
{
    int data;
    //c における構造体の宣言ではクラスの使い方＋structを先頭に
    //struct Node* next;
    //c++では不要
    Node* next;
    //ポインターが何も指し示すものがないと状態から始める決まり。headをnullにする
    //head
};



int main()
{
    //指し示すものが無い　とかく
    Node* head = NULL; //nodeの初期化
    
    /*
     ノードを作成するときは動的メモリの確保から始める
     Node* head = new Node;
     
      Node head;（実体）
     [ data | next ] ← 実体そのもの
     
     head → NULL
     Node* head = NULL;（ポインタ）
     このとき、*head や head->data にアクセスするとクラッシュします！
     なぜなら、head はまだ「どのノードも指していない（NULL）」からです。
     
     値を入れるには、実体が必要
     たとえば、値を入れたいなら次のようにします：
     
     Node* head = new Node; // 実体を作る（newで動的確保）
     head->data = 100;      // ここで初めて値を入れられる
     head->next = nullptr;
     
     意味
     Node* head = NULL;    まだノードを指していない（実体なし）
     head->data = 10;    ❌ ダメ！クラッシュする（NULL参照）
     head = new Node;    実体を作ってからなら OK
     head->data = 10;    ✅ 実体があるので代入可能


     */
    //クラッシュする
    //std::cout << *head << std::endl;
    
    head -> data =10;
    //std::cout << *head << std::endl;
    head -> next = NULL;
    
    
    return 0;
}
