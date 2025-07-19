//
//  main.cpp
//  review2
//
//  Created by Satoshi on 7/19/25.
//

#include <iostream>
#include <unistd.h>

// staticで関数をでてもaの値を有効化
static int a = 100;
int& func()
{
    return a;
    // int& a = func()
}

int main()
{
    
    int& b = func();
    std::cout<< a <<" "<< b << std::endl;
    
    b = 200;

    std::cout<< a <<" "<< b << std::endl;
    
    a = 300;
  
    std::cout<< a <<" "<< b << std::endl;
    
    return 0;
}
