/*
 
 Node* head = new Node;
 
 new Node;の意味は
 ヒープという物置の中に　Nodeの構造体を管理する箱を作るよ
 Node*の型のへheadはヒープのNodeを指し示すよ
 「Node 型のポインタ head を使って、そのヒープ上の Node の位置を覚えておくよ」*
 つまり：
 head は矢印（ポインタ）
 それが ヒープにあるNodeの「住所（アドレス）」 を記憶している
 
 
 headもhead->nextもポインタであり、これを動かすにはnew Nodeをする必要がある
 head も head->next も「Node（ノード型のポインタ）」であり、使うには new Nodeでメモリ（中身）を確保しないといけない。
 
 
 理由1：ポインタは「箱（アドレス）」だけで、中身がない
 この時点で head は「Node型のものを指すポインタ」ですが、
 **どこも指していない（未初期化 or nullptr）**ので、使えません。
 Node* head　= nullptr;
 
 理由2：new Node でヒープに実体（中身）を作る
 head = new Node;
 
 理由3：同じく head->next もポインタなので、使う前に new が必要
 head->next = new Node;  // ここが抜けるとクラッシュの原因
 head->next->data = 20;
 head->next も Node* なので、実体がなければアクセスできません。
 
 最後のポインターをnullptrにして
 delete ポインタ；

 
 */

#include <iostream>

//基本構造を作る　1個目から2個目を考えればよし
struct Node
{
    int value;
    Node* next;
    
};

int main()
{
    //始点を作る
    Node* head = new Node;
    head->value =42;
    head->next = nullptr;
    std::cout << head->value << std:: endl;
 
    return 0;
}
