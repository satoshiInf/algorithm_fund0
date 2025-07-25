//
//  main.cpp
//  loop_typical_mistake2
//
//  Created by Satoshi on 7/25/25.
//

#include <iostream>

int main()
{
    bool counterEqualFour = false;
    int counter = 0;
    
    //counterが、iとするとforループないのみ有効
    //真偽チェック→カウンターを＋１してからfor文を実行
    // counter =4である時、カウンターを＋１＝５になる、そしてfor文の中身を実行
    for(;counter <= 4; ++counter)
    {
        if(counter == 4)
        {
            counterEqualFour = true;
        }
    };
    
    if(counterEqualFour)
    {
        std::cout << counter << std::endl;
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << counter << std::endl;
        std::cout << "False" << std::endl;
    }
    
    
    
    return 0;
}
