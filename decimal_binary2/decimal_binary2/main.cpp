//
//  main.cpp
//  decimal_binary2
//
//  Created by Satoshi on 7/15/25.
//

#include <iostream>
#include <vector>
#include <string.h>

int main()
{
    //from decimal to binary
    std::cout << "from decimal to binary" << std::endl;
    int decimalNumber;
    std::cin >> decimalNumber;
    std::vector<int> mod1;
    
    
    while(decimalNumber >0)
    {
    //1桁から計算
        mod1.push_back(decimalNumber%2);
        decimalNumber = decimalNumber/2;
    }
    
    //一番の大きい桁から計算
    for(int i =0; i < mod1.size(); i++)
    {
        std::cout << mod1[i];
    }
    
    
    
    //from binary to decimal
    std::cout << "from binary to decimal" << std::endl;
    //111->2^0*1+2^1*1+2^2*1
    std::string binaryNumber;
    std::cin >>binaryNumber;
    
    int resultDecimal = 0;
    int power = 0;
    
    //前提：文字列は「左から右」だと、上位桁 → 下位桁
    for(int i = binaryNumber.size() - 1; i>= 0; --i)
    {
        //一桁目から見ている
        if(binaryNumber[i] =='1')
        {
            resultDecimal += std::pow(2, power);
        }
        ++power;
            
    }
    
    
    return 0;
}
