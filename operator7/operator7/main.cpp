
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

#include <iostream>


struct Point
{
    int x;
    int y;
    
    //when a and  are member variables. a+b -> a.operator + b
    // a is omitted.(p1 =a, p2=b)
    Point operator+(const Point& other)
    {
        return Point((x + other.x), (y + other.y));
    }
    
    

    
};

std::ostream& operator<<(std::ostream& os ,const Point& p)
{
    os <<"("<< p.x <<"," << p.y <<")" ;
    return os;
}

int main()
{
    Point p1{1,2};
    Point p2{2,4};
    
    std::cout << p1 <<std::endl;
    std::cout << p2 <<std::endl;
    
    /*
     (std::cout << p1) <<std::endl
     (std::cout << p1 <<std::endl)
     */
    
    
    std::cout << (p1+ p2) << std:: endl;
    //access to number_variables;
    
    
    
    return 0;
}
