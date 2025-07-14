
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
#include<iostream>
//2)
void show(int&x, int&y)
{
    std::cout << x << "," << y << std::endl;
}


struct Point
{
    int x;
    int y;
    
    
    //1)
    void show()
    {
        std::cout << x << "," << y <<std::endl;
    }
    
};

#include <iostream>

int main()
{
    Point pnt1;
    
    pnt1.x =1;
    pnt1.y =2;
    
    //no operator
    //1)
    show(pnt1.x, pnt1.y); //グローバル関数 show は int& を引数に取って中身を出力。
    
    //no operator
    //2)
    pnt1.show(); //構造体 Point 内のメンバ関数は、引数なしで自分自身のメンバ x と y を表示。
    
   
    return 0;
}
