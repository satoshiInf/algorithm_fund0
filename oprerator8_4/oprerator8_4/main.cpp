
#include <iostream>

//+
//cout

struct Point
 {
    int x;
    int y;
    
    //Point p3 = p1 + p2;
    Point operator+(Point& other)
    {
        return Point{x+ other.x, y+ other.y};
    }
    
    // std::cout<<p3;
    
    //std::ostream& は型だけ
    friend std::ostream& operator<<(std::ostream& os, Point& point)
    {
        //cout << インスタンス.メンバーを使ってどう記述したいかを具体的に書く
        os <<"("<< point.x <<","<< point.y <<")"<< std::endl;
        return os;
    }
};

int main()
{
    Point p1{1, 2};
    Point p2{3, 4};
    Point p3 = p1 + p2;
    std::cout << p3;
    
    
    return 0;
}

/*
 
 ## ✅ 問題 1：
 問題 1：+演算子の引数の受け取り方に関する正誤問題
 次の記述について、正しければ〇、間違っていれば✕をつけ、理由を説明しなさい：

 Point operator+(Point& other) では、other を 値渡しで受け取っている。
 ### あなたの答え：

 > いいえ、参照渡し

 ✅ **正解です！**

 * `Point& other` は参照渡し（「&」がある）
 * もし `Point other` だったら「値渡し」
 * ただし、**`const Point&` にする方が安全で一般的**（読み取り専用）

 ---

 ## ✅ 問題 2：
 以下のうち、operator+ の戻り値として最も適切なのはどれか。理由も述べよ。
 
 A. Point&
 B. Point
 C. void
 D. const Point&
 ### あなたの答え：

 > Point&

 ❌ **残念、ここは間違いです。**

 ### 正解：**B. `Point`**

 ### 理由：

 * 演算結果は **新しい Point オブジェクト（p1 + p2 = 新しい点）**
 * `Point&` を返すと → 一時的なオブジェクトの参照を返すことになり **未定義動作（危険）**
 * よって「**値で返す（Point）**」が正解！

 ---

 ## ✅ 問題 3：🔶 問題 3：出力演算子のオーバーロードに関する理解
 あなたが書いた次の関数の中で、修正した方が良い点があれば挙げよ。（理由も）

 friend std::ostream& operator<<(std::ostream& os, Point& point)
 ### あなたの答え：

 > `const` 書き忘れている

 ✅ **正解！**

 修正前：

 ```cpp
 friend std::ostream& operator<<(std::ostream& os, Point& point)
 ```

 修正後（推奨）：

 ```cpp
 friend std::ostream& operator<<(std::ostream& os, const Point& point)
 ```

 ### 理由：

 * `<<` ではオブジェクトを書き出すだけ → **読み取り専用でOK**
 * `const` にしないと → `const` な `Point` を出力できなくなる

 ---

 ## ✅ 問題 4：関数呼び出しの順序
 🔶 問題 4：関数の実行順と対応関係
 以下のコードが実行されたとき、呼び出される関数の順序を説明せよ：

 Point p1{1, 2};
 Point p2{3, 4};
 Point p3 = p1 + p2;
 std::cout << p3;

 ### あなたの答え：

 > 上から下

 ✅ **正解！**

 順序としては：

 1. `Point p3 = p1 + p2;`
     → `operator+` が呼ばれる
 2. `std::cout << p3;`
     → `operator<<` が呼ばれる

 **「+」が先、「<<」が後**です。

 ---

 ## ✅ 問題 5：
 次のようなコードを可能にするには、Point構造体に何を追加すればよいか？

 Point p1{1, 2};
 p1 += Point{5, 7};  // 結果: p1 = (6, 9)
 
 Point& operator+=(Point& other)
 {
 x +=other.x;
 y +=other.y;
 return *this; // Point& 戻り値
 }

 ### あなたの答え：

 Point& operator+=(const Point& other)
 {
    x += other.x;
    y += other.y;
    return {x, y};
 これは「Point型の新しいオブジェクトを返している」だけで、
 operator+= は 自分自身（*this）の参照を返すべき
 }
 
 
 Point& operator +(Point& other) {
     return {x + other.x, y + other.y};
 }
 ```

 ❌ **惜しい！ `+` ではなく `+=` のオーバーロードが必要です！**

 ### 正解は：

 ```cpp
 Point& operator+=(const Point& other) {
     x += other.x;
     y += other.y;
     return *this; //　*this　＝ &__　てこと
 
 }
 ```

 * `+` は新しいオブジェクトを返す
 * `+=` は「自分自身を変える」ので、`*this` を返すようにします
 
 *this とは何か？
 this は メンバ関数内で使える特別なポインタで、
 「今操作している自分自身のオブジェクトのアドレス」を指します。
 *this は、this が指す先（ポインタの参照先）なので、
 「今のオブジェクトそのもの、インスタンス」を意味します。

 ---

 ## ✨ 総合評価

 | 問題 | あなたの答え         | 評価 |
 | -- | -------------- | -- |
 | 1  | ✅ 正解           | ◎  |
 | 2  | ❌ `Point&` はNG | △  |
 | 3  | ✅ 正解           | ◎  |
 | 4  | ✅ 正解           | ◎  |
 | 5  | ❌ `+=` の定義ミス   | △  |

 🔚 **全体的にとても良いです！**
 2と5のような細かい違いは、**実装経験を積むと自然に身に付きます**。

 ---

 次は「比較演算子」や「デフォルト引数」などにもチャレンジしますか？
 追加問題も喜んで出します！

 */
