
#include <iostream>

/*
アドレス→()なし、関数として呼び出す（）を書く
 
 */
//ポインター関数の定義
//型（　クラス::*ポインター名) () = 右辺はアドレス　=　& クラス.関数()なし
//int( Point::*ptr)()　= &Point.sum;
//ポインター関数の呼び出しは（インスタンス.ポインター関数名）　()あり
//(point1.*ptr)();
//関数で、()をつけるのは呼び出すとき、定義ではつけない

struct Point
{
    
    int x;
    int y;
    
    int sum()
    {
        return x+y;
    }
};

int main()
{
    Point point1;
    point1.x =1;
    point1.y =2;
    
    int(Point::*ptr)() = &Point::sum; //関数の指定
    int result = (point1.*ptr)(); //2回括弧を書く
    
    std::cout << result << std::endl; //ポインター関数での呼び出し
    std::cout<< point1.sum()<< std::endl;　//インスタンスでの呼び出し

    return 0;
}
