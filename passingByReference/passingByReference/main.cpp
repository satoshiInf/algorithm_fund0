/*
 
 次の要件を満たす関数 addTen を作成しなさい。

 整数 x を受け取り、10を加える関数を定義せよ。

 その際、関数に引数を「参照渡し」で渡すことで、関数内の変更が呼び出し元に反映されるようにせよ。

 main 関数内で変数 a = 5 を用意し、それを addTen に渡したあとの a の値を表示すること。
 
 a = 15

 */

#include <iostream>
int addTen(int& num)
{
    num += 10;
    return num;
    
}


int main()
{
    int a =5;
    std::cout<< "a = " <<addTen(a)<<std::endl;

    return 0;
}
