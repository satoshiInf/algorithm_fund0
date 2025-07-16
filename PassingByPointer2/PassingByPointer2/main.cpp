/*
 以下の関数 increment は、引数として渡された整数の値を1増やします。
関数の定義と main 関数内での呼び出しを完成させてください。
 */


#include <iostream>

void increment(int *x)
{
    *x +=1;
}

int main()
{
    int num =10;
    increment(&num);
    std::cout << num;
    
    
    return 0;
}
