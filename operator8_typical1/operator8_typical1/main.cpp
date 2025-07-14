/*
 📝【設問】
演算子オーバーロードの総合練習
以下の仕様をすべて満たすC++プログラムを作成しなさい：
構造体 Point を作成すること
Point p1{1, 2};
Point p2{3, 4};を使用する。
 
 メンバ変数 int x, y を持つ。
以下の演算子をオーバーロードすること：
 1)
 +：
 　Point 同士を加算して、新しい Point を返す。
 2)
 <<（出力）：
 　std::cout << p で (x, y) の形式で出力できるようにする。
 3)
 ==：
 　2つの Point の x, y が同じなら等価とみなす。
 4)
 []（インデックス演算子）：
 　p[0] で x、p[1] で y を返す。
 　それ以外のインデックスが来た場合はエラーを出す。
 5)
 ()（関数呼び出し演算子）：
 　p() で、x + y の合計を返す。

 ■ main() 関数で以下を行う：
 2つの Point を作成し、加算して表示。
 == を使って比較。, [] を使って x, y を個別に表示。() を使って x + y の結果を表示。
 
 */

#include <iostream>
#include <stdexcept>


struct Point
{
    int x;
    int y;
    
    //1)
    Point operator+(const Point& other)const
    {
        return Point((x+other.x),(y+other.y));
    }
    
    // なぜフレンドにするのか
    //2)
    friend std::ostream& operator<<(std::ostream& os, const Point& p)
    {
        os << "(" << p.x << "," << p.y << ")";
        return os;
    }
    
    //3)
    bool operator==(const Point& other)const
    {
        return x == other.x and y == other.y;
    }
    
    //4)書き直すこと
    const int& operator[](int index) const
    {
        if (index == 0)
            return x;
        else if (index == 1)
            return y;
        else throw std::out_of_range("Index must be 0 or 1");
    }
    
    //5)
    int operator()() const
    {
        return x + y;
    }

};


int main()
{
    //1 and 2)
    Point p1{1,2};
    Point p2{3,4};
    Point p3 = p1 + p2;
    std::cout << p3 << std::endl;
    
    //3)
    if( p3 == Point(4,6)) // the operator begins to work here.
    {
        std::cout << "Correct"<<std::endl;
    }
    
    //4)
    std::cout<< p3[0]<< std::endl;
    std::cout<< p3[1] << std::endl;
    
    //5)
    std::cout<< p3() << std::endl;
    //p3(); → p3.operator()() が呼ばれる！
    
 
    return 0;
}









/*
 
 #include <iostream>
 #include <stdexcept>

 struct Point {
     int x, y;

     // 1. 加算
     Point operator+(const Point& other) const {
         return Point{x + other.x, y + other.y};
     }

     // 2. 出力（friendで外部からアクセス可能に）
     friend std::ostream& operator<<(std::ostream& os, const Point& p) {
         return os << "(" << p.x << ", " << p.y << ")";
     }

     // 3. 等価比較
     bool operator==(const Point& other) const {
         return x == other.x && y == other.y;
     }

     // 4. 添字アクセス：x=0, y=1
     int& operator[](int index) {
         if (index == 0) return x;
         else if (index == 1) return y;
         else throw std::out_of_range("Index must be 0 or 1");//ライブラリ　std::out_of_range
     }

     const int& operator[](int index) const {
         if (index == 0) return x;
         else if (index == 1) return y;
         else throw std::out_of_range("Index must be 0 or 1");
     }

     // 5. ()でx + yを返す
     int operator()() const {
         return x + y;
     }
 };

 int main() {
     Point p1{1, 2};
     Point p2{3, 4};

     // 加算
     Point p3 = p1 + p2;
     std::cout << "p1 = " << p1 << std::endl;
     std::cout << "p2 = " << p2 << std::endl;
     std::cout << "p1 + p2 = " << p3 << std::endl;

     // 比較
     if (p3 == Point{4, 6}) {
         std::cout << "p3は(4, 6)と等しいです" << std::endl;
     }

     // 添字アクセス
     std::cout << "p3[0] = " << p3[0] << std::endl;
     std::cout << "p3[1] = " << p3[1] << std::endl;

     // 関数呼び出し演算子
     std::cout << "p3() = " << p3() << std::endl;

     return 0;
 }

 

 ### ✅ 主語を明確にした説明：

 C++で `std::cout << p` のように出力を行うとき、
 このコードは内部的に次のように呼び出されます：

 ```cpp
 operator<<(std::cout, p);
 ```

 このとき、**左辺の `std::cout` は `std::ostream` 型**、
 **右辺の `p` はユーザー定義型 `Point`** です。

 ---

 ### ❗ ここで問題になるのは次の点です：

 * `std::ostream` は C++標準ライブラリのクラスであり、
   そこに自分で `Point` 型専用の `<<` を追加することはできません。
 * つまり、**`<<` のオーバーロードは `Point` 側が用意する必要があります。**

 ---

 ### ✅ そのため、次のような非メンバ関数を定義します：

 ```cpp
 std::ostream& operator<<(std::ostream& os, const Point& p);
 ```

 この関数は `Point` クラスの**外部**に定義されているため、
 `p.x` や `p.y` に**直接アクセスする権限がありません。**

 ---

 ### 🔒 そこで登場するのが `friend` 修飾子です：

 `Point` クラスの中で、この関数を **`friend`** として宣言することで、
 その関数に `Point` の内部メンバ（`x`, `y`）へのアクセスを許可します。

 ---

 ### ✅ 最終的なコードイメージ：

 ```cpp
 struct Point {
     int x, y;

     // friend によって << を Point の「友達」にして内部アクセスを許可
     friend std::ostream& operator<<(std::ostream& os, const Point& p);
 };

 std::ostream& operator<<(std::ostream& os, const Point& p) {
     return os << "(" << p.x << ", " << p.y << ")";
 }
 ```

 ---

 ### 🎯 まとめ

 | 要素    | 主語を明確にした説明                                                |
 | ----- | --------------------------------------------------------- |
 | 左辺    | `std::cout` は `std::ostream` 型なので `Point` クラスのメンバ関数にはできない |
 | 関数の場所 | `<<` は **非メンバ関数**として定義しなければならない                           |
 | アクセス権 | 非メンバ関数は `Point` の private メンバにアクセスできない                    |
 | 解決方法  | `Point` クラス内で `<<` を `friend` にして内部アクセスを許可する              |

 ---



 
 
 

 `else throw std::out_of_range("Index must be 0 or 1");`
 は、**例外（エラー）を明示的に発生させる構文**です。

 ---

 ## ✅ この構文の意味を分解すると：

 ### 🔹 `throw`：

 * C++における**例外（exception）を投げるキーワード**です。
 * 何か異常（バグ、入力ミスなど）が発生したときに使います。

 ---

 ### 🔹 `std::out_of_range`：

 * 標準ライブラリに用意された**例外クラス**の一種。
 * `<stdexcept>` ヘッダで定義されています。
 * **「範囲外アクセス」を表すエラー**です。

 ```cpp
 #include <stdexcept>
 ```

 ---

 ### 🔹 `"Index must be 0 or 1"`：

 * 例外オブジェクトの**エラーメッセージ文字列**です。
 * これが例外として表示されます。

 ---

 ## ✅ 全体の意味：

 ```cpp
 else throw std::out_of_range("Index must be 0 or 1");
 ```

 ### 🔸 日本語訳：

 「`index` が 0 でも 1 でもなければ、`out_of_range` 例外を投げて、
 "Index must be 0 or 1"（インデックスは 0 か 1 にしてください）というエラーメッセージを表示せよ」

 ---

 ## 🧪 補足：例外が投げられたらどうなる？

 ```cpp
 try {
     Point p{1, 2};
     std::cout << p[2];  // ← ここで out_of_range が投げられる！
 }
 catch (const std::out_of_range& e) {
     std::cerr << "例外発生: " << e.what() << std::endl;
 }
 ```

 ### 🔸 実行結果：

 ```
 例外発生: Index must be 0 or 1
 ```

 ---

 ## ✅ throw 文のテンプレート構文：

 ```cpp
 throw std::例外クラス("エラーメッセージ");
 ```

 ---

 ## よく使う例外クラス：

 | クラス名                    | 意味          |
 | ----------------------- | ----------- |
 | `std::out_of_range`     | 範囲外アクセス     |
 | `std::invalid_argument` | 引数が不正       |
 | `std::runtime_error`    | 実行時の一般的なエラー |
 | `std::logic_error`      | プログラムの論理ミス  |

 ---

 ご希望あれば、`throw` を使ったエラー処理の全体設計（try-catch含む）も解説します！

 
 
 
 
 
 
 
 
 
 */
