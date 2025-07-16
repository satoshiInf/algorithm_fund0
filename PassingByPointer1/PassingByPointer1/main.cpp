

/*
 基本形
 func(&a);
 void func(int* x)
 配列の時
 func(p);
 int* p = &a;
 
 アドレスを仮引数として渡して、ポインターを引数に取る
 */


#include <iostream>

void func(int* x)
{
    *x =100;
}

int main()
{
    int a = 10;
    std::cout << a;
    std::cout << "\n"<<std::endl;
    //アドレスなので&で記載。しかし配列の場合は配列名＝先頭のアドレスなのでarrになる
    func(&a);
    std::cout << a <<std::endl;

    return 0;
}

/*
 基本形
 func(&a);
 void func(int* x)
 配列の時
 func(p);
 int* p = &a;

 */
