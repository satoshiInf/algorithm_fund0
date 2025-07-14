// overload
/*
 関数オーバーロード
同じ名前でも、引数の型や数が違う複数の関数を用意できること。
演算子オーバーロード
演算子（+、-、<< など）を自分のクラス・構造体向けに意味づけて使えるように「書き換えること」。
 */

#include <iostream>

/*
operator<<(a, b)から a << b
operator<<(a,b) ->  operatorを消す、<<aをくっつけて反転　a<<にする。
a << bから operator<<(a, b)
a << b -> (<<a, b)にする、手前にoperatorをつける　operator<<(a,b)
*/


struct Point
{
    int x;
    int y;
};

//std:: cout << p1;
std::ostream& operator<< (std::ostream& os, const Point& p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

/*
 ”o”stream :
stream for output such as cout
cout:実体、オブジェクト
ostream:クラス
 
operator<< :
function of (operator<<)

std::ostream& os :
std:: cout
 
const Point& p :
 p1
*/





int main()
{
    
    Point p1; //object
    p1.x = 1;
    p1.y = 2;
    
    //cout << p1      // error  -> need to make operator.
    std:: cout << p1;//　osにstd::cout の参照が渡される,coutはostreamのオブジェクトなので上に帰る

    return 0;
}


/*
 ## 1. `std::cout` は何か？
 * `std::cout` は **`std::ostream` 型のオブジェクト**（正確には `std::ostream` を継承した `std::ostream` クラスの実体）です。
 * つまり、`std::cout` は **画面への出力を行う「ストリーム」** です。
 
 「std::cout は std::ostream クラスのオブジェクト」なので、
 std::cout に対して操作をするときは、その基になっているクラスの機能（メンバ関数など）が使われます。
 だから「オブジェクトからクラスが呼ばれる」という表現は、
 「オブジェクトを操作するときに、そのクラスのメソッド（関数）が実行される」
 という意味で合っています。

 ---
 演算子は内部的には関数呼び出し
 a << b という書き方は、operator<<(a, b) と同じ意味です。
 
 operator<<(a, b)から a << b
 operator<<(a,b) ->  operatorを消す、<<aをくっつけて反転　a<<にする。
 
 a << bから operator<<(a, b)
 a << b -> (<<a, b)にする、手前にoperatorをつける　operator<<(a,b)
 
 ## 2. `operator<<` はどうやって呼ばれるのか？
 どの operator<< を呼ぶか決めるルール
 C++ は「どの operator<< 関数を呼べば良いか」を決めるとき、
 左辺のオブジェクトの型に合う関数を探します。
 
 * `std::cout << p1` と書くと、
 * C++ は左辺の型（この場合 `std::ostream`）に合う `operator<<` を探します。
 * もし `p1` の型に合った `operator<<` が標準にない（`Point`型の場合はない）ので、
 * 自分で定義した
 cpp
 std::ostream& operator<<(std::ostream& os, const Point& p)
 があれば、それを呼びます。

 ---

 ## 3. 引数 `std::ostream& os` に `std::cout` が渡る理由
 * `operator<<` の最初の引数は「どこに書き込むか」を表すストリーム（出力先）なので、
 * `std::cout << p1` の場合は、`os` に `std::cout` の参照が渡される形です。

 ---

 ## まとめると

 | 書いたコード             | 実際に呼ばれる関数                                           | 引数に入るもの                                     |
 | ------------------ | --------------------------------------------------- | ------------------------------------------- |
 | `std::cout << p1;` | `operator<<(std::ostream& os, const Point& p)` 呼ばれる | `os` に `std::cout`（画面出力ストリーム）<br>`p` に `p1` |

 ---

 こうして、`operator<<` 内で

 ```cpp
 os << "(" << p.x << ", " << p.y << ")";
 ```

 と画面（`std::cout`）に `p1` の内容を書き込んでいるわけです。

 ---

 もしさらに詳しく知りたい部分があれば教えてくださいね！

 */
