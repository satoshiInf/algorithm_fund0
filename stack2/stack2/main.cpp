//
/*
 top--; これって違和感があるんだけど　マイナスしているだけでなんで配列の要素が無くなるの?

 
 確かに `top--;` って「数字を減らしてるだけ」に見えますよね。
 でも実は **それで正しいんです。理由があります。**
 ## 🔁 スタックの中身を実際に「消している」わけではない,無視しているだけ！！

 ```cpp
 void pop() {
     if (top == -1) {
         std::cout << "取り出し不可\n";
         return;
     }
     top--;  // ← ここ
 }
 ```

 ### ❓ ここで何が起きてるの？

 * `top` は「**次に push/pull する位置**」または「**現在の一番上の要素のインデックス**」を指します。
 * `pop()` で **top を 1 つ減らすだけ** で、「一番上の要素は無視する」ことになります。

 ---

 ## 📦 例：実際の動作イメージ（MAX = 5）

 ```cpp
 push(10) → top = 0 → data[0] = 10
 push(20) → top = 1 → data[1] = 20
 push(30) → top = 2 → data[2] = 30
 ```

 今の状態：

 | index | 0   | 1  | 2  | 3 | 4 |
 | ----- | --- | -- | -- | - | - |
 | data  | 10  | 20 | 30 |   |   |
 | top   | ↑ 2 |    |    |   |   |

 ---

 ### pop() を呼ぶと…
 top-- → 1になる
 でも `data[2]` の値（30）はメモリ上にまだあります！
 **でも `top = 1` になったことで、プログラム的には「もう data\[2] は見ない」ことになります。**
 → これが「要素を取り出した」ことになるんです。
 ## 💡 補足：完全にデータを消したいなら？

 data[top] = 0; // などで上書きしてから top--
 
 とすれば物理的に消せますが、普通のスタック実装では「無視」されるだけで十分です。
 （実際 STL の `std::stack` もそうです）
 ---
 ## ✅ まとめ
 * `top` だけで **どこまでが有効なデータかを管理**している
 * `top--` は「**上の要素はもう使わない**」という宣言のようなもの
 * 実際の値は消さなくても OK（無視されるだけ）
 ---
 気になる場合は、`data[top] = 0;` を追加してデバッグしてみると感覚がつかめますよ！
 もっと詳しく動作を図解しましょうか？
 */
//

#include <iostream>
#define MAX 5 //セミコロン不要

struct Stack
{
    int data[MAX];
    int top;
    
    Stack() : top(-1){};
    
    void push(int x)
    {
        if(top >= MAX -1)
        {
            std::cout << "詰めない" << std::endl;
        }
        data[++top] = x;
    }
    
    void pop()
    {
        if (top == -1)
        {
            std::cout << "スタックが存在しない" << std::endl;
        }
        top--; // 無視するだけ
    }
    
    int peek()
    {
        if(top == -1)
        {
            std::cout << "空" << std::endl;
            return -1;
        }
         else
         {
             return data[top];
         }
    }
    
    /*
     意味を分解すると：
     top == -1
     　→ スタックが空（要素が1つも入っていない）ことを表します。
     return top == -1;
     　→ 空なら true を返す、そうでなければ false を返す。
     */
    bool empty()
    {
        return top == -1;
    }
};





int main()
{
    Stack s;
    
    std::cout << s.empty() << std::endl; //trueは１
    s.push(5);
    s.push(10);
    std::cout << s.empty() << std::endl;// falseは0
    std::cout<< "一番上"<<s.peek() << std::endl;
    s.pop();
    s.pop();
    std::cout<< "一番上"<<s.peek() << std::endl;//取れない
    s.pop(); //取れない
    std::cout << s.empty() << std::endl;// false は0
    
    
    
    return 0;
}
