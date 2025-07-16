//
//  main.cpp
//  oprerator8_2
//
//  Created by Satoshi on 7/16/25.
//

#include <iostream>

struct Point
{
    
    int x;
    int y;
    
    std::string sum()
    {
        return "(x ,y)";
    }
    
    int sum2()
    {
        return x+y;
    }
    
    
    //structの中にオペレータを記述する
    //Point p3 = p1 + p2;
    Point operator+(const Point & other)
    {
        return Point{x + other.x ,y +other.y};
    }
    
    //coutには<<にはfriendをつける
    //std::cout << p3;
    friend std::ostream& operator<<(std::ostream& os,const Point &p )
    {
        os <<"(" << p.x << "," << p.y <<")"  << std::endl;
        return os;
    }
    /*
     std::cout << p3;    operator<<(std::ostream& os, const Point& p)
     std::cout    os（第1引数）
     p3    p（第2引数）

     std::cout << p3;
     ↓
     operator<<(std::cout, p3);  ←こう呼ばれる
     
     std::cout << p3;
     │         │   │
     │         │   └─→ const Point& p（第2引数）
     │         └────→ std::ostream& os（第1引数）
     └────────────→ operator<<（関数呼び出し）

     最初のstd::ostream&は戻り値
     <<をチェインして連続して出力できるようにするため
     std::cout << p1 << p2 << "done";

     */
    
};

int main()
{
    //pointer_member
    Point p1;
    p1.x = 1;
    p1.y = 3;
    
    std::cout << "("<< p1.x << ","<< p1.y<<")"<< std:: endl;
    
    std::string(Point::*ptr)() = &Point::sum; //左は関数ポインタなので（）がある
    (p1.*ptr)();
    std::cout <<(p1.*ptr)() << std::endl;

    int(Point::*ptr2)() = &Point::sum2; // ptrと被ると定義できないのでptr2にする
    std::cout << (p1.*ptr2)() << std::endl;
    
    //pointer_operator
    
    Point p2{5,5};
    Point p3 = p1 + p2;　//main関数のみでは意味をなさない
    //これにオペレータが必要なのはこれがインスタンス同士の計算で、この階層では意味をなさないからだ
    //インスタンス同士の演算は「意味を教える」ためにオペレーターオーバーロードが必須
    std::cout << p3;
    
    
    
    
    return 0;
}
