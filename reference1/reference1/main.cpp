

#include <iostream>

/*
 //xと＆xの関係性について。xがintの値を持つとすると、＆xはint*の型を持つアドレスと定義される
 //よって&xをreturnで返す時、戻り値はintのみでは間違いでint*が必要になる。
 //int x; と定義したら　&xはint*の型を持つという決まり。
 "int*" getValue2()
 {
     static int x = 10;
     return "&x";
 */

//参照渡しの時
int& getValue()
{
    static int x = 10;
    return x; // ❓
}
int getValue1()
{
    int x = 10; //static不要
    return x;
}


int* getValue2()//アドレスを返す　// int*は結果を合わせるだけ　returnの先だけ見る　＆xだな
{
    static int x = 10;
    return &x;//int xの　&xを返すなら自動的にint＊と勝手に決まる
    //xと＆xの関係性について。xがintの値を持つとすると、＆xはint*の型を持つアドレスと定義される
    //int x; と定義したら　&xはint*の型を持つという決まり。
    //&xの型はint*（int型のポインタ)
    //よって戻り値はintのみでは間違いでint*が必要になる。
}

int main()
{
    std::cout <<getValue()<< std::endl; // int* x = getValue(); でxはstaticをつけないとmainの時点でxが消える。この行ではxが消えているのでエラーになる

    std::cout <<getValue1()<< std::endl;;//コピーなのでxの値がコピーされたものがgetValue1()に返される
    
    int value2 = *getValue2() ;// *address でアドレスの値を取り出す //getValue2()のアドレスを拾う
    
    
    std::cout<<value2 << std::endl;
    
    std::cout<<getValue2();
    
    return 0;
}
