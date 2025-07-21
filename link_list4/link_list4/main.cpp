/*
 ✅ 問題②：2ノードをつないで出力せよ
 📋 内容：
 * head と head->next を作成
 * data = 10 と 20 を順に入れる
 * cout で2つの data を出力（ループなし）
 * delete も2回きちんと書くこと
 */



#include <iostream>

struct Node
{
    int data;
    // NodeポインタでNode内の方を保持
    Node* next;
    
};

int main()
{
    //初期化
    Node* head = nullptr;
    
    //Node* head = new Node;
    head = new Node;
    head-> data =10;
    
    // head ->next = new Node;が抜けていた
    //ポインターを使うときは　住所を作る（new Node)
    //その後、型に対して初めて代入できる
    
    head -> next = new Node; //下行でhead-> next ->と続く場合はhead-> next　= newになる
    head-> next ->data =20;
    
    //末尾にヌルを作る
    head->next->next = nullptr;
    
    
    std::cout << head-> data <<" "<< head->next->data << std::endl;
    
    //逆
    //delete head;
    //delete head->next;
    //delete head->next->next;
    
    /*
    処理    理由
    new Node    動的にノードを作るため
    head->next = ...    ポインタはまず「new」で中身を作る必要がある
    delete 順番    後ろから順に解放しないとクラッシュする
    delete nullptr    何も起きないが、無意味な操作
     */
    
    //末尾から削除をしていく
    //delete head->next->next; ヌルの場合はそもそも何も無いのだから消す対象がない
    delete head->next;
    delete head;
    
    
    
    return 0;
}
