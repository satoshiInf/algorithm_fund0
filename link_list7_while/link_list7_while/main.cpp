/*
 目的：
 ノードを3つ作成（値：10, 20, 30）
 head を使ってつなげる
 while ループで表示
 メモリ解放（delete）
 */

#include <iostream>

struct Node
{
    int data;
    Node* next;
};


int main()
{
    //Nodeの箱を指し示すポインタhead
    Node* head = nullptr;
    
    head = new Node;
    head -> data = 10;
    
    head -> next = new Node;
    head ->  next -> data = 20;
    
    head ->  next -> next = new Node;
    head ->  next -> next ->data = 30;
    
    head ->  next -> next ->next = nullptr;
   
    //display
    Node* current = head;
    
    while(current!= nullptr) // headから末端へ
    {
        std::cout << current ->data << std::endl;
        current = current->next;
    }
    
    current = head; //headに戻す
    
    while(current != nullptr)
    {
        Node* temp = current; //currentのアドレスを指す、currentはhead 消す->  current->next　消す
        current = current->next;
        delete temp;
    }
    
    /*
     これは頭から消している点に注意
     はい、そのとおりです。
     「頭（head）」から順にちゃんと消している処理**になっています！

    
     while (current != nullptr) {
         Node* temp = current;       // 今のノード（current）を一時保存
         current = current->next;    // 次のノードへ進む（1つ先へ）
         delete temp;                // 一時保存したノード（今のノード）を削除
     }
     ```

     この `while` 文では、以下の流れで進みます：

     | ステップ | currentが指すノード  | 処理内容                                                         |
     | ---- | -------------- | ------------------------------------------------------------ |
     | 1    | `head`（最初のノード） | `temp = head` → `current = head->next` → `delete head`       |
     | 2    | 2番目のノード        | `temp = current` → `current = current->next` → `delete temp` |
     | 3    | 3番目のノード        | 同様に進む                                                        |
     | 4    | `nullptr` に到達  | `while` 終了                                                   |

     ---

     ## ✅ つまり：

     * `head` も含めて、**すべてのノードが順番に delete されている**
     * `delete temp;` によって、毎回 **「current の1つ前のノード」** を削除している
     * `current` を進めたあとに `delete` してるから、次のノードを失わず安全

     ---

     ## 💡 補足：なぜ直接 `delete current;` ではないの？

     ```cpp
     current = current->next;
     delete current; // ❌ 危険！順番が逆
     ```

     この書き方だと、**今のノードのアドレスを失ってから `delete`** することになるので、**メモリリーク**や**未定義動作**の原因になります。

     ---

     ## ✅ まとめ

     > 🔸 `while (current != nullptr)` の書き方は
     > **「先に次へ進む準備 → 今のノードを消す」**
     > という正しい順番で、`head` から順にすべて消す安全な方法です！

     他にも気になる部分があればどんどん聞いてくださいね！

     */
    
    
    return 0;
}
