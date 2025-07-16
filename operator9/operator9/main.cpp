//
//  main.cpp
//  operator9
//
//  Created by Satoshi on 7/16/25.
//

#include <iostream>

struct Point
{
    int x;
    int y;
    
    
    
    int sum() const
    {
        return x + y;
    }
};

int main()
{
    Point p1;
    p1.x = 1;
    p1.y = 2;
    

    
    //直接p1を呼び出せない
    std::cout << p1.x <<","<< p1.y <<std::endl;
    
    /*
    メンバー関数ポインタは普通の関数ポインタと違って、
    func(p1);  // これはメンバー関数ポインタには使えません
    のように直接オブジェクトを引数に渡して呼べません。
     */
    
    /*
    やり方１)
    Point 2{1,2};
    int result =sum(p1);
     
    int sum(Point& p)
     {
        return p.x + p.y;
     }
     
    やり方２）
    // メンバー関数ポインタを取得
    int (Point::*funcPtr)() const = &Point::sum;
    // オブジェクト経由で呼び出す（.*演算子）
    int result = (p1.*funcPtr)();
    std::cout << result << std::endl;
     */
    
    Point p2;
    p2.x = 5;
    p2.y = 5;
    
    int (Point::*funcPtr)() const = &Point::sum;
    int total = (p1.*funcPtr)();
    std::cout << total << std::endl;
    
    /*
     int (Point::*funcPtr)() const = &Point::sum; の意味
     Point::*funcPtr
     → 「Pointクラスのメンバー関数へのポインタ」という意味です。
     ::* は「メンバーへのポインタ」で、ここでは関数のポインタです。
     int (...)() const
     → 戻り値がintで、引数なしのconstメンバー関数を指すという意味
     = &Point::sum;
     → Pointクラスのsumメンバー関数のアドレスを代入している。
     
     
     理解の仕方
     int* p;  // int型変数へのポインタ
     次に
     int Point::* p;  // Pointクラスのint型メンバー変数へのポインタ
     次に関数の場合は、戻り値や引数も指定する必要があり複雑化する
     int (Point::*funcPtr)() const;　//変数の定義名がfuncPtr
     int              // 戻り値の型
     (Point::*)()     // Pointクラスの引数なしメンバー関数へのポインタ
     const            // const修飾された関数
     funcPtr          // ← これが「そのポインタの名前（変数名）」
     int (Point::*funcPtr)()　: int *func()にあたる部分
      PointクラスのfuncPtr
     
     | 用語             | 具体例                                            | 意味                         |
     | -------------- | ---------------------------------------------- | -------------------------- |
     | **オブジェクト**     | `p1`, `p2`, `p3`                               | Pointの実体（変数）               |
     | **メンバー変数**     | `x`, `y`                                       | Pointクラスの中のデータメンバー         |
     | **メンバー変数ポインタ** | `int Point::* px = &Point::x;`                 | Pointクラスのメンバー変数`x`へのポインタ   |
     | **メンバー関数ポインタ** | `int (Point::*funcPtr)() const = &Point::sum;` | Pointクラスのメンバー関数`sum`へのポインタ |


     ____________________________
     int func() {
         return 42;
     }
     int main() {
         int val = func();  // val に 42 が代入される
         std::cout << val << std::endl;
     }
     
     ____________________________

     int global = 100;

     int* func() {
         return &global;
     }

     int main() {
         int* ptr = func();      // ptr は global のアドレス
    std::cout << *ptr << std::endl;  // 100 が表示される（値を参照）
     std::cout << ptr << std::endl;  // アドレスが表示される（例：0x7ffee23a4b3c）
     }

     ____________________________
     */
    
    
    
    
    
    return 0;
}
