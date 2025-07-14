//
//  main.cpp
//  operator6_template
//
//  Created by Satoshi on 7/14/25.
//

#include <iostream>

int main()
{
    return 0;
}

/*

 ## 🔧 よく使う演算子オーバーロードのテンプレ集
 ### ✅ 1. 加算（`+`）

 ```cpp
 struct Point {
     int x, y;

     Point operator+(const Point& other) const {
         return Point{x + other.x, y + other.y};
     }
 };
 ```


 ### ✅ 2. 出力（`<<`）

 #include <iostream>

 struct Point
 {
     int x, y;

     // 加算もつけておくと便利
     Point operator+(const Point& other) const
    {
         return Point{x + other.x, y + other.y};
     }

     // 出力：友達関係（friend）にして外からアクセス
     friend std::ostream& operator<<(std::ostream& os, const Point& p) {
         return os << "(" << p.x << ", " << p.y << ")";
     }
 };
 📌 **`<<` は friend にしないと `std::cout << p;` が書けない**から注意！

 ---

 ### ✅ 3. 等価比較（`==`）

 ```cpp
 struct Point {
     int x, y;

     bool operator==(const Point& other) const {
         return x == other.x && y == other.y;
     }
 };
 ```

 ---

 ### ✅ 4. 配列アクセス（`[]`）※配列やベクターっぽいクラスに使う

 ```cpp
 struct MyArray {
     int data[10];

     int& operator[](int index) {
         return data[index];
     }

     const int& operator[](int index) const {
         return data[index];
     }
 };
 ```

 ---

 ### ✅ 5. 関数のように呼びたい（`()`）

 ```cpp
 struct Adder {
     int base;

     int operator()(int x) const {
         return base + x;
     }
 };
 ```

 ---

 ## 🔁 実務で使う頻度（参考）

 | 演算子  | よく使う度 | 理由・場面               |
 | ---- | ----- | ------------------- |
 | `+`  | ★★★★☆ | 数値・座標・サイズの足し算       |
 | `<<` | ★★★★★ | デバッグや表示で超重要         |
 | `==` | ★★★★☆ | 比較・検索処理で必須          |
 | `[]` | ★★★☆☆ | 自作コンテナや配列風の使い方      |
 | `()` | ★★☆☆☆ | 関数オブジェクト（ラムダっぽく）で使う |

 ---

 ## ✅ 最低限これだけ覚えればOKセット

 ```cpp
 struct Point {
     int x, y;

     Point operator+(const Point& other) const {
         return Point{x + other.x, y + other.y};
     }

     friend std::ostream& operator<<(std::ostream& os, const Point& p) {
         return os << "(" << p.x << ", " << p.y << ")";
     }

     bool operator==(const Point& other) const {
         return x == other.x && y == other.y;
     }
 };
 ```

 ---

 ## 📦 使い方（main関数）

 ```cpp
 int main() {
     Point p1{1, 2};
     Point p2{3, 4};
     Point p3 = p1 + p2;

     std::cout << "p1 = " << p1 << std::endl;
     std::cout << "p2 = " << p2 << std::endl;
     std::cout << "p1 + p2 = " << p3 << std::endl;

     if (p3 == Point{4, 6}) {
         std::cout << "等しいです！" << std::endl;
     }
 }
 ```

 ---

 必要に応じて、印刷して貼っておくとか、スニペット登録しておくと便利ですよ！

 「これの次はどれ練習したらいい？」ってのも気軽に聞いてくださいね。

 
 */
