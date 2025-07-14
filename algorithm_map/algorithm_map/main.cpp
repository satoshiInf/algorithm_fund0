//
//  main.cpp
//  algorithm_map
//
//  Created by Satoshi on 7/14/25.
//

#include <iostream>
//#include <algorithm>
#include <map>

int main()
{
    std::map<std::string,int> scores;
    scores["name1"] = 10;
    scores["name2"] = 20;
    scores["name3"] = 30;
    
    for(auto& [name,score]:scores) //
    {
        std::cout << "name: " << name  <<  " score: "<< score << std::endl;
    }
    
    std::cout << "\n";
    
    // check sort
    std::map<std::string,int> scores2;
    scores2["Cname1"] = 10;
    scores2["Bname2"] = 20;
    scores2["Aname3"] = 30;
    
    for(auto& [name,score]:scores2) //
    {
        std::cout << "name: " << name  <<  " score: "<< score << std::endl;
    }
    
    
    //std::map<std::key, value> scores3;
    std::map<std::string, int> scores3; //std::map< std:: type, type> nameOfMap
    scores3["A"]= 100;
    scores3["B"]= 90;
    scores3["C"]= 80;
    
    /*
     なぜ参照（&）なのか？
     コピーではなく、元のデータを直接操作・参照するため。
     詳しく：
     map の中身は大量のデータ（ペア）が入っています。
     ループ内で毎回コピーすると処理が重くなるし、メモリも余計に使う。
     参照を使うと「実体（本物）」にアクセスできるので、読み書きが速くて効率的。
     */
    
    for(auto& [key,value]: scores3)// scores3のkey = A, score3のvalue 100　をコピーせずに使用
    {
        std::cout <<"name:" << key <<"\nscore: " << value << std::endl;
        
    }
    
    /*
     なぜ参照（&）なのか？
     コピーではなく、元のデータを直接操作・参照するため。
     詳しく：
     map の中身は大量のデータ（ペア）が入っています。
     ループ内で毎回コピーすると処理が重くなるし、メモリも余計に使う。
     参照を使うと「実体（本物）」にアクセスできるので、読み書きが速くて効率的。
     */
    
    
    
    
    

    return 0;
}
