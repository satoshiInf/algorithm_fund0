//
//  main.cpp
//  operator3
//
//  Created by Satoshi on 7/14/25.
//

/*
ポイント：

1. この変換式
 std::ostream& operator<<(std::ostream& os, const Axis& p)
   {内容}
 
2. //第一引数を返すことで複数の<<を連続させることができる
     return os;
 
 
 
*/

/* std::a& operator<<(std::a& os, const classname & p)
{
    //content
 
    return os;
}
 */


#include <iostream>

struct Axis
{
    int x;
    int y;
};




std::ostream& operator<<(std::ostream& os, const Axis& p)
{
    os <<"("<< p.x << ","<< p.y <<")" << std::endl;
    
    return os; //第一引数を返すことで連続させることができる
};

/*
 | 戻り値の型           | 何が起きる？                         |
 | --------------- | ------------------------------ |
 | `void`          | 連続した `<<` の呼び出しができなくなる         |
 | `std::ostream&` | 連続した `<<` の呼び出しが可能になる（チェーンできる） |
 
 
 ## なぜ戻り値を `std::ostream&` にするのか？voidじゃダメなの？
 ### 1. 連続した出力を可能にするため
 例えば、
 std::cout << p1 << " is a point." << std::endl;
 これは実は、
 ((std::cout << p1) << " is a point.") << std::endl;
 ```

 という連続した演算の連鎖です。

 * もし `operator<<` の戻り値が `void` だったら、
 * `std::cout << p1` の結果が何も返らず、
 * 次の `<< " is a point."` に繋げられなくなります。

 ---

 ### 2. `std::ostream&` を返すことで、呼び出し元にストリームを返し、次の `<<` に繋げられる

 つまり、

 * 戻り値に `std::ostream&` を返すことで、
 * `operator<<` の呼び出しを\*\*連鎖（チェーン）\*\*させることができる。

 ---

 ### まとめ

 | 戻り値の型           | 何が起きる？                         |
 | --------------- | ------------------------------ |
 | `void`          | 連続した `<<` の呼び出しができなくなる         |
 | `std::ostream&` | 連続した `<<` の呼び出しが可能になる（チェーンできる） |

 ---

 ### 例

 ```cpp
 std::cout << p1 << " is a point." << std::endl;
 ```

 が

 std::cout.operator<<(p1).operator<<(" is a point.").operator<<(std::endl);


 のように、戻り値が次の呼び出しの対象になるイメージです。

 ---

 もしもっと具体的に呼び出しの流れを図解してほしいなどあれば言ってくださいね！


 */



int main()
{
    Axis point1;
    point1.x = 1;
    point1.y = 2;
    
    //1
    std::cout <<"("<< point1.x<<","<< point1.y <<")"<<std::endl;
    
    //2
    std::cout << point1;
   
    
    
    return 0;
}
