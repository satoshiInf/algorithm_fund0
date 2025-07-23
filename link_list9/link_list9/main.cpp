/*
 問題1：単一ノードの作成と削除
 Node構造体を定義
 head に動的確保でノードを作り、data に好きな値を入れる
 head のデータを出力する
 最後に delete head で解放する
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
    head -> data =0;
    
    head -> next = new Node;
    head -> next -> data =1;
    
    head -> next -> next= new Node;
    head -> next -> next -> data = 2;
    
    
    
    
    
    Node* current = head;
    //出力
    while( current != nullptr)
    {
        std::cout << current-> data <<std::endl;
        current = current->next;
        
    }
    
    //動的メモリの削除
    /*
     currentは対象を動かすカーソルでtempで消す対象を捕まえる
    まさにその通りです！超わかりやすい説明です。
    current はリストをなぞる「カーソル」や「歩き手」
    temp は今まさに消すべき「ターゲット（ノードのアドレス）」を捕まえる役割
     
    temporaryNodeをcurrentNodeにループ内にセット
    currentNodeを動かす
    temporaryNodeを削除
     
    */
    
    while(current != nullptr )
    {
        Node* temp = current;//currentを毎ループ動かすためその都度更新しそれを消す
        current = current-> next;
        delete temp;
    }
    
    /*
    while(current != nullptr)
    {
        Node* temporaryNode = currentNode;
        currentNode = currentNode-> next;
     ```delete temporaryNode;
    }
    */
    
    return 0;
}
