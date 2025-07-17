
#include <iostream>

struct Point
{
    int x;
    int y;
    
    
   /* ざっくり基本
    同じクラスのインスタンス同士ではない
    operatorは戻り値　演算子＝＆引数１　＆引数２
    同じクラスのインスタンス同士
    operatorは戻り値　演算子＝（＆クラスが引数）
    
    
    
   /* 呼び出し方
    メンバ関数として定義,xとyがp1とp2で定義済みである場合のみ。
    p1.operator+(p2)
    
    「引数を使ってメンバーにアクセスする」ときの引数の型は
    必ずそのメンバー（変数や関数）が定義されている　クラスや構造体の型　である
    

    
    という形で考える。
    //Point p3 = p1 + p2;
    //p１とp２が全く同じのメンバー変数で成り立つ時、Point p3 = p1.operator+(p2); と解釈される：
    */
    // 引数をつかってメンバーにアクセスするとき＝引数はメンバーのあるクラスの型
    //上には=は書かない
    Point operator+(const Point& other )
    {
        //第一引数と＋をひっくり返す Point + : Pointのメンバーをx、other.xと書いて使用できる
        
        
        return Point(x + other.x, y + other.y);
        //return Point(x + other.x, y + other.y);でPointが型なので戻り値もPointである
        //Point operator+(const Point& other) の引数が Point 型なのは、「この Point を起点に、x や y を取り出すことができるから」なのか？
        //はい、その理解はかなり本質を突いています！other が Point 型である理由は、相手（右辺）の x や y にアクセスしたい
        //Point operator+(const Point& other)この構文は **「左辺の Point オブジェクトに、右辺の Pointオブジェクトを加える」**という意味です。
        /*
         p1 は this ポインタとして暗黙に渡されている→ this->x, this->y で自分の座標にアクセスできる
         p2 は other という引数として明示的に渡されている→ other.x, other.y で相手の座標にアクセスできる
            Pointを引数にしてメンバーにアクセス。
            x、yにアクセス
            意味
            　x            自分（p1）のx座標（this->x）
             other.x      相手（p2）のx座標
             x + other.x   自分と相手のxを合計
             Point(...)    新しい座標の点を作る
         */
        
        
        /*
        非メンバ関数として定義
        operator+(p1, p2) ：そのまま読める
        
        struct Point
         {
            int x;
            int y;
        };
         
         
         
一方で　非メンバ関数の時は
非メンバ関数として定義（friend でなくてもOK）
         
        Point operator+(const Point& a, const Point& b) {
            return Point{a.x + b.x, a.y + b.y};
         // +と第一をひっくり返して、a + b　の構造
         
        }

        int main() {
            Point p1{1, 2};
            Point p2{3, 4};

            Point p3 = p1 + p2;  // 非メンバ関数が呼ばれる。引数から見る計算　returnが戻り値

            std::cout << "p3: (" << p3.x << ", " << p3.y << ")" << std::endl;
            return 0;
        }
         
         1. operator+(const Point& a, const Point& b) の役割
         この関数は「2つの Point 型の引数（a と b）を受け取り、その合計となる新しい Point を返す」関数です。戻り値は Point 型なので、結果は「座標を足し合わせた新しい点」です。
         
         2. 関数内部の計算過程：a.x + b.x と a.y + b.y
         a.x と b.x はどちらも int型の値です（Point のメンバ変数）。

         そのため a.x + b.x は int同士の加算演算 になります。
         同様に a.y + b.y も int の加算です。

         つまり、
         return Point{a.x + b.x, a.y + b.y};は、
         a と b のそれぞれの x と y の値を int として足している
         その合計値を使って新しい Point インスタンスを作り、返している

         3. 「引数1 + 引数2 に分解される」というイメージ
         関数呼び出しは p1 + p2 の形で行われますが、これは
         operator+(p1, p2);
         の呼び出しと同じ意味です。p1 と p2 はそれぞれ a と b に対応し、
         a.x + b.x, a.y + b.y として計算されるので、
         「引数1のxに引数2のxを足す」計算をしているとイメージできます。

         4. 最後に全体像をまとめると

         p1 + p2
          ↓ （呼び出し）
         operator+(p1, p2)
          ↓ （処理）
           a.x + b.x  → int同士の加算
           a.y + b.y  → int同士の加算
          ↓ （戻り値）
         新しい Point が返される
         
         p3 = p1 + p2; という式では、
         p1 + p2 の部分がまず評価されて、Point 型の一時オブジェクトが作られる
         そのオブジェクトが 代入演算子（operator=） を使って p3 にコピーまたはムーブ代入される
         p3 はその新しい Point の値を持つことになる

         🔍 ステップ分解で解説
         Point p1{1, 2};
         Point p2{3, 4};
         Point p3;

         p3 = p1 + p2;
         Point p3;           // ① 空の p3 を用意
         
         p1 + p2;の演算がスタート

         Point temp = p1 + p2; // ② 一時オブジェクト temp（= Point{4, 6}）ができる

         p3 = temp;          // ③ temp の値が p3 にコピーされる（operator=）
         // temp はこのあと破棄される（スコープが終了）
         
         
         ステップ1：p1 + p2 の評価
         ここで呼ばれるのは operator+(const Point& a, const Point& b)

         中ではこうなる：
         Point temp = Point{p1.x + p2.x, p1.y + p2.y};  // temp = {4, 6}
         ステップ2：代入

         p3 = temp;  // 代入演算（operator=）が呼ばれる
         もし Point に特別な operator= を定義していなければ、コンパイラが自動生成するコピー代入が使われます。

         
         
         
         
         
         
         
         
         
         
         
        */
        
        
        
    }
    
    
    
    
    
    
};

int main()
{
    Point p1{1,1};
    Point p2{2,2};
    
    //インスタンス同士の演算は読み込めない
    Point p3 = p1 + p2;
    // メンバ変数 x と y はインスタンスから直接アクセスできる（p3.x, p3.y）。
    // // 一方、p3 自体に対しては、演算子 + によって生成された新しい Point オブジェクトであり、
    // p3 の中身（x や y）にアクセスして値を取り出すことができるが、
    // p3 を「演算子 + を使って」直接操作・参照することはできない。
    std::cout << p3.x <<" "<< p3.y << std::endl;
    
    //オペレータを使ってp3を取り出す。
    
    
    
    

    
    return 0;
}
