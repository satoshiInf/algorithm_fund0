//
//  main.cpp
//  exception1
//
//  Created by Satoshi on 7/30/25.
//

#include <iostream>
#include <stdexcept>

/*

 try ブロックで囲むのは、if 文による「場合分け」よりも上の階層（外側）」でOKです。
 つまり：if の中ではなく、
 if を含む大きなブロックを try で囲むのが基本的な書き方です。
 try を if文全体の外側＝上の階層に置くのは、将来的に条件が増える・処理が変わる可能性を見越しての設計です。
 */

int main()
{
    int number;
    std::cin>> number;
    
    //int remainder = ((number % 3)+3) %3;
    int remainder = ((number % 3)) %3; //-10を入力すると-1になりexceptionになるはず
    
    try
    {
        if(remainder ==0)
        {
            std::cout <<remainder<< std::endl;
        }
        else if(remainder ==1)
        {
            std::cout <<remainder<< std::endl;
        }
        else if(remainder ==2)
        {
            std::cout <<remainder<< std::endl;
        }
        else
        {
            throw std::runtime_error("Error occured");
        }
        
    }
    catch (const std::exception& error)
    {
        std::cout<< "exception:" << error.what()<<" remainder:" << remainder << std::endl;
    }
    
    
    return 0;
}
