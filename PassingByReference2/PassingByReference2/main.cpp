/*
 
 2つの整数 x と y を受け取り、両方に 10 を加える 関数 addTenToBoth を作成せよ。
 関数は void 型とし、返り値は持たないこと。
 引数は両方とも 参照渡し を用いること。
 main 関数で a = 3, b = 7 を用意し、関数呼び出し後に a と b の値を表示して、変更が反映されたことを確認せよ。
 
 実行
 a = 13
 b = 17

 2つの整数 x と y を受け取り　＝　xとyで受け取りの意味
 */
#include <iostream>

void addTenToBoth(int& x , int& y)
{
    x+=10;
    y+=10;
}

int main()
{
    int a = 3;
    int b = 7;
    
    addTenToBoth(a,b);
    
    std::cout << a <<std::endl;
    std::cout << b <<std::endl;

    return 0;
}
