
/*
 【設問】演算子オーバーロードを使ったPoint構造体の操作
 以下の条件を満たすC++プログラムを作成してください。
 Pointという構造体を定義し、int x, yのメンバを持つこと。
 Point同士の加算ができるように、+演算子をオーバーロードすること。
 → 2つのPointのx同士、y同士を足し合わせた新しいPointを返す。
 Pointの内容をコンソールに表示できるように、<<演算子をオーバーロードすること。
 → (x, y)の形式で出力する。
 main関数内で2つのPointを作成し、それらの加算結果を画面に出力すること。
 実行例：
 p1 = (1, 2)
 p2 = (3, 4)
 p1 + p2 = (4, 6)
 */

/*
std::cout<< (pnt1 + pnt2);
->
 Point operator+(const Point& other) const// pnt1とpnt2を格納している　メンバーも
 {
     return Point((x + other.x),( y + other.y) );
 }
 
 
 Point p1{1, 2};
 Point p2{3, 4};
 Point p3 = p1 + p2;  でこの型を使うはず
 Point point3 = p1 + p2 なのでPointを返す必要がある
 
*/




#include<iostream>



struct Point
{
    int x;
    int y;
    
    //1)no operator
    void show()
    {
        std::cout << x << "," << y <<std::endl;
    }
    
    /*
     Point operator+(const Point& other) const
     {
            return Point{x + other.x, y + other.y};
        } ここがわからない　＋otherしかしてないように見える。
     
     →
     Point Point::operator+(const Point& other) const
     A + B　をA.operator+(B)と解釈されます。(pnt1 + pnt2)のこと。
     ここで A が「自分自身（this）」で、B が other です。
     return Point{x + other.x, y + other.y};
     実際はこういう意味になります：
     return Point{this->x + other.x, this->y + other.y};
     this->x や this->y とは書かれていませんが、暗黙的に「自分のメンバ x/y」を使っているのです。
     Point p1{1, 2};
     Point p2{3, 4};
     Point result = p1 + p2;
     このとき p1.operator+(p2) が呼ばれます。
     return Point{1 + 3, 2 + 4}; // → Point{4, 6}
     になります
     */
    Point operator+(const Point& other) const
    {
        return Point((x + other.x),( y + other.y) );
    }
        /*
         // pnt1とpnt2を格納しているメンバーも
         暗黙的にreturn Point(this->x + other.x, this->y + other.y);と同じ意味になる
        C++では、クラスや構造体のメンバ関数（この場合 operator+）の中では、
        そのクラスのメンバ変数（x, yなど）に対して this-> を省略してアクセスすることができます。
         
         クラスの外なら
         Point Pointer::operator+(const Point& other) const
         {
             return Point((x + other.x),( y + other.y) );
         }
         */

    
    /*
     これは "explicit object parameter"（明示的オブジェクトパラメータ） と呼ばれる機能で、モダンC++の一部です。
     しかしこれは C++23以降のみ対応ですし、現時点で多くの開発環境（XcodeやGCC、Clang）ではまだ完全対応していないことも多いです。
     auto operator+(this Point self, const Point& other)
     {
         return Point{self.x + other.x, self.y + other.y};
     }
     
     */
    
    
    
    /*
     
     2つ目：const（最後の部分）
    これはメンバ関数に対する修飾で、**「この関数は自分自身（this）を変更しません」**という意味です。
    「読み取り専用の関数である」ことを示しています。
     Point operator+(const Point& other) const {
                    //       ↑↑↑↑↑↑↑↑↑
                    // この const は、this ポインタが const Point* であることを意味する
     }

     */
};



//2)no operator
void show(int&x, int&y)
{
    std::cout << x << "," << y << std::endl;
}


std:: ostream& operator<<(std::ostream& os, const Point& p)
{
    os << p.x <<","<< p.y << std:: endl;
    return os;
}


     




int main()
{
    // Point pnt1{1, 2}; を丁寧に書くと
    Point pnt1;
    pnt1.x =1;
    pnt1.y =2;
    
    Point pnt2{2,4};
    
    
    
//1)no operator
    
    show(pnt1.x, pnt1.y); //グローバル関数 show は int& を引数に取って中身を出力。
    
//2)no operator
    pnt1.show(); //構造体 Point 内のメンバ関数は、引数なしで自分自身のメンバ x と y を表示。
    
    
    //operator
//3)operator to show
    std::cout << pnt1 << std::endl;
    std::cout << pnt2 << std::endl;
    // << pnt2 << 　：<<を繰り返す
    
    
//4)operator to plus
    std::cout<< (pnt1 + pnt2);
    
    //<< std:: endl;
    //object + object ->objectを繰り返す
    
/*
 std::cout << (pnt1 + pnt2);
              ↑ここで operator+ が呼ばれて Point型が作られる
 ↑ここで operator<< が呼ばれて、その Point を出力

 */
    
    
    
   
    return 0;
}




/*
 

 ご質問は：
 > `Point operator+(const Point& other)` では、
 > `a + b` の「a」が省略されているように見えるけど、実際どうなってるの？
 > 暗黙的に `a` が渡ってるの？ → **そう！それが「this」なんです。**

 ---

 ## 🔍 結論：

 `Point operator+(const Point& other)` は、
 `a + b` の「a」が `this` として**暗黙的に渡されている**のです。

 ---

 ## ✅ 詳しく説明します

 ### 例として、次のコードを考えましょう：

 struct Point {
     int x, y;

     Point operator+(const Point& other) const {
         return Point{x + other.x, y + other.y};
     }
 };

 int main() {
     Point a{1, 2};
     Point b{3, 4};
     Point c = a + b;  // ← ここ
 }
 ### ここで `a + b` はどうなるか？

 a + b

 はコンパイラによって次のように解釈されます：

 a.operator+(b)

 * `a` が **呼び出し元** → `this`
 * `b` が **引数** → `other`

 ---

 ### 💡 つまり…

 ```cpp
 Point operator+(const Point& other) const
 は実際には：
 Point Point::operator+(const Point& other) const
 ```
 という形で、「左辺の `a` が `this`」として渡されているのです！

 ## ❓では、非メンバ関数の場合は？

 非メンバ関数として書くと、両方を明示的に受け取ります：

 Point operator+(const Point& a, const Point& b) {
     return Point{a.x + b.x, a.y + b.y};
 }
 ```

 このときは：
 Point c = operator+(a, b);  // または a + b;
 ```

 と明示的に呼びます。**両方の引数が見えている**のが特徴です。

 ---

 ## ✅ まとめ表

 | 書き方             | 解釈                | 使う場面          |
 | --------------- | ----------------- | ------------- |
 | `a + b`（メンバ関数）  | `a.operator+(b)`  | 左辺がクラスのインスタンス |
 | `a + b`（非メンバ関数） | `operator+(a, b)` | 両方を対等に扱うとき    |
 | `this` は省略される   | `x` → `this->x`   | クラス内部で暗黙的に使える |

 ---

 ### 🔧 あなたの理解（省略されてるのでは？）はまさにその通り。

 C++では、「**メンバ関数の呼び出し元（左辺）**」は `this` として**自動的に渡される**ので、あなたが疑問に思ったとおり、

 ```cpp
 operator+(const Point& other)
 ```

 で **「a + b」の a が見えないのにちゃんと使えるのは、this で渡ってるから**です。

 ---

 他の演算子（`-`, `==`, `[]`, `()` など）も同じ考え方で成り立ってます。もっと例が見たい場合はどんどん聞いてください！

 */
