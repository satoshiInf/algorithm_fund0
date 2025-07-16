
#include <iostream>

struct Point
{
    int x;
    int y;
    
    int sum() const
    {
        return x+y;
    }
    
};

//関数のポインタ
int main()
{
    Point p1;
    p1.x =1;
    p1.y =2;
    
    // メンバー関数ポインタの定義と代入
    //左辺＝これは「int型を1つ受け取ってintを返すconstメンバー関数」へのポインタ
    //左辺はポインタなので右辺はアドレスである必要がある
    //int (Point::*Pointername) () const;
    //関数のアドレスを書くときは&クラス名::関数名 の形で書きます。
    int (Point::*Ptr)() const= &Point::sum;　//関数の指定
    //int result = (p1.*Ptr)();
    //std::cout << result;
    
    
    //int(Point::*ptr)()const =& Point::sum; //Point.sumじゃない
    //int result = (p1.*ptr)();
    //std::cout << result;
    
    
    
    int (Point::*ptr)() const = &Point::sum;
    //左辺関数に対するポインタ、sum,substraction,,etc。そのうちのsumの関数のアドレスを右辺で指定
    int result = (p1.*ptr)(); //ポインター関数の呼び出しは(インスタンス.*ポインタ)()
    std::cout << result;
    
    /*
     
     1)
     () は「関数の引数リスト」
     () は「このメンバー関数が引数を取らない」ことを示します。
     例えば、
     int sum() const;
     というメンバー関数のシグネチャ（宣言）があれば、
     この関数は「引数ゼロ個の const メンバー関数」だと分かりますよね？
     2)
     だからメンバー関数ポインタの型宣言はこうなる
     int (Point::*Ptr)() const;
     int：戻り値の型
     (Point::*)：Pointクラスのメンバーへのポインタ
     ()：引数リスト（この場合は引数なし）
     const：メンバー関数が const 修飾されている
     
     3)
     引数がある場合は？
     もし引数があるメンバー関数の場合、例えば
     int foo(int a, double b) const;
     なら、ポインタの型は
     int (Point::*Ptr)(int, double) const;
     */
    
    
    return 0;
}
