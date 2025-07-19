/*
 まず整理：参照（&）の使い道は主に3つ
変数に別名（エイリアス）をつける
関数の引数を参照にする（コピー回避や直接変更）
関数の戻り値を参照にする（変数を直接返す）
 
参照は変数に別名をつける行為であって、関数に別名をつけることではない。
働きかけるのは変数と引数になる。
よって、int&x =func()　と　int& y = func()で管理する流れになる
 
 */


#include <iostream>


/*
int x =1;
int& func()
{
    return x;
}

// int& x = func()
// x ≡func()
*/


int x = 10;
int& func()
{
    return x;
}

// int&x =func()
// int &y = func();



int main()
{
    /*
    int &y = func(); //y≡func()
    y = 10;
    std::cout << y << "," << x << std::endl;
    
    x =3;
    std::cout << y << "," << x << std::endl;
    //単独の＆でアドレス
    std::cout << &y << "," << &x << std::endl;
    
    //参照そのものを意味するためには左辺に置く必要がある。
    //&a のみではアドレスを意味してしまう。
    //右辺に書く場合は　int *a = &b の形に必ずなる。
    
     */
    
    //int y =100;
    //int& y = func();　誤り
    /*型が違っても、同じ名前の変数を同じスコープ内で2回宣言するのは、C++の文法で禁止されているからです。
    C++は「名前（識別子）単位で一意性」をチェックします。型の違いは関係ありません。
     内容は違うが変数では同名では一回しか宣言できない
     */

    
    int &y = func();
    
    y =100;
    std::cout<< x <<" "<< y << std::endl;
    
    x =200;
    std::cout<< x <<" "<< y << std::endl;
    
    
    
    return 0;
}
