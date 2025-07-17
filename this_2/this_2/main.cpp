//
//  main.cpp
//  this_2
//
//  Created by Satoshi on 7/17/25.
//

#include <iostream>
/*
 
 this ポインタとは？
 //メンバー関数の中で使用する
 
 C++のメンバー関数の中に自動的に渡される特別なポインタです。
 **「その関数が呼ばれたオブジェクト自身のアドレス」**を指します。
 メンバー関数内で this を使うと、自分自身のオブジェクトを操作できます。
 
 インスタンス.メンバー関数　インスタンスを使って呼び出す時、　メンバー関数内のメンバーの値をthis→変数で表す
 */

struct Point
{
    int x;
    int y;
    
    // 2) p1.setXY(1,2)から呼ばれたらp1のポインタをthisとみなす
    //this == &p1
    void setXY(int x,int y)
    {
        this->x = x;//p1->x
        this->y = y;//p1->y
    }
    int sum()
    {
        return x + y;
    }
    
    int sum2()
    {
        return this->x + this->y;
    }
    
    
    
    /*
     thisを使わないで書くと
     void setXY(Point* p, int x, int y)
     {
         p->x = x;
         p->y = y;
     }
     int main()
     {
         Point p1;
         setXY(&p1, 1, 2);  // ポインタを渡して操作　＜＝＞p1.setXY(1,2);
     }
     */
    
};

int main()
{
    Point p1;
    p1.setXY(1,2); // 1) p1の時の（p１のオブジェクトの）setXYをセットする
    //Point::setXY(&p1,1,2)という意味になる
    
    //Point::sum(&p1);と解釈される　文法的には誤り
    p1.sum();
    std::cout << p1.sum();
    
    //this->メンバー変数で当該インスタンスのメンバーの値を取り出す
    p1.sum2();
    std::cout << p1.sum2();
    
    //正しく書くと
    int (Point::*ptr)() =&Point::sum;
    std::cout << (p1.*ptr)();
    
    
    
    
  
    return 0;
}
