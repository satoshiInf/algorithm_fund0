//
//  main.cpp
//  decimal_binary1
//
//  Created by Satoshi on 7/15/25.
//

#include <iostream>
#include <cmath> // pow
#include <string.h>
#include <vector>


/*
 string
 char& operator[](std::size_t pos);
 const char& operator[](std::size_t pos) const;
 */

int main()
{
    //binary to decimal

    std::string binary;
    std::cin >> binary;
    int resultdecimal = 0;
    int power = 0;
    
    //1010 -> 1*2^3 + 1*2^1
    // binary
    for(int i = binary.size() - 1; i >=0; i--)
    {
        if(binary[i] =='1')
        {
            resultdecimal += std::pow(2,power);
        }
        ++power;
    }
    
    std::cout << resultdecimal<< std::endl;
    
    
    
    //decimal to binary
   
        /*
        13%2の値の1が２^0桁に入り、これの商が６で次の計算に
        6%2の値値の0が２^１桁に入り、これの商が３で次の計算に
        3%2の値の１が２^2桁に入り、これの商が1で次の計算に
        1%２の値の1が２^3桁に入り、これの商が1で次の計算に..終わり
         
        | 今の値（number| number ÷ 2 | 余り（bit） | 意味     |
         | ----------- | ---------- | ------- | ------    |
         | 13          | 6          | 1       | 2⁰の桁が1 | 余りを記録
         | 6           | 3          | 0       | 2¹の桁が0 |
         | 3           | 1          | 1       | 2²の桁が1 |
         | 1           | 0          | 1       | 2³の桁が1 |

         */
    
    // decimal to binary
        int decimalNumber;
        std::cin >> decimalNumber;
        std::vector<int> rest;
        while(decimalNumber > 0)
        {
                rest.push_back(decimalNumber % 2); // 余りを記録
                decimalNumber /= 2;                // 商で上の桁へ
        }
            
    
        for(int i = rest.size() - 1; i >= 0; -- i)
        {
                std::cout << rest[i];
        }
                std::cout << std::endl;
        

        return 0;
}
