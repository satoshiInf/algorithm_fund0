//
//  main.cpp
//  pointerToArray2
//
//  Created by Satoshi on 7/27/25.
//

#include <iostream>

int main()
{

    int arr[5] = {10, 20, 30, 40, 50};
    
    //型はint*,配列名は暗黙的に＆配列名[0]になる。
    std::cout << arr << std::endl;       //　アドレスは同じはず
    //型はint (*)[5]。アドレス自体は配列全体のアドレス、これは先頭を指すから＆配列名[0]
    //配列名は全体を見ている、あくまで仕様としてarrのアドレスがarrの先頭に位置する
    std::cout << &arr << std::endl;      //
    //明示的な先頭のアドレス、型はint*
    std::cout << &arr[0] << std::endl;   //

    
    
    return 0;
}
