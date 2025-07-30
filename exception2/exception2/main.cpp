/*
 文字列 ->exitと数値を扱う-> 数値の時は文字列を数値に変換で対応
 
 
 パターン1：最初から int number に直接入力する場合
 std::cin >> number;
 これは 数値としての入力しか受け付けません。
 ユーザーが "exit" や "abc" と入力すると、cin がエラー状態になり、その後の入力ができなくなることがあります。

 ✅ パターン2：まず std::string input に受け取る場合
 std::string input;
 std::cin >> input;
 入力が "exit" のとき → if (input == "exit") で終了できる
 入力が "123" のとき → std::stoi(input) で int に変換できる
 入力が "abc" のとき → std::stoi が例外を投げて catch に飛ぶ
 つまり、文字列ならすべてのパターンを1回で受け取れるのです。
 
 
 try
 {
    throw std::runtime_error("");
 }
 catch(const std::exception& error)
 {
     std::cout << "excetion: " << error.what() <<std::endl;
 }
 
 number = std::stoi(input);
 
 
*/

#include <iostream>
#include <stdexcept>

int main()
{
    std::string input;
    int number;
    bool inputeEscape = false;
    
    
    while(!inputeEscape)
    {
        //文字列 ->exitと数値を扱う-> 数値の時は文字列を数値に変換で対応
        std::cin >> input;
        if(input == "exit")
        {
            inputeEscape = true;
        }
        else
        {
            number = std::stoi(input);
            int remainder = number % 3;
            
            try
            {
                //inputをintに変換 stoi = string to int（ストリング → int）
                //number = std::stoi(input);
                //int remainder = ((number % 3)+3) %3; //
                //int remainder = number % 3;
            
            
                if(remainder ==0)
                {
                    std::cout << remainder <<std::endl;
                }
                else if(remainder ==1)
                {
                    std::cout << remainder <<std::endl;
                }
                else if(remainder ==2)
                {
                    std::cout << remainder <<std::endl;
                }
                else
                {
                    //throw std::runtime_error();
                    throw std::runtime_error("error occured");
                }
            
            }
            catch(const std::exception& error)
            {
                std::cout << "excetion: " << error.what() <<std::endl;
                // std::cout << "remainder: " << remainder << std::endl;　エラー　remainderのスコープはtryのなか
                std::cout << "remainder: " << remainder << std::endl;
            }
        }
    }
    
    
    
    return 0;
}
