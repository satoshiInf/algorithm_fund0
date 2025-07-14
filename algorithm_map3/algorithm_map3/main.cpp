//
//  main.cpp
//  algorithm_map2
//
//  Created by Satoshi on 7/14/25.
//

#include <iostream>
//#include <map>
#include <unordered_map>

int main()
{
    // map - type - name of map
    std::unordered_map<std::string, int> scores;
    
    //input data
    //name[first] = seond
    scores["Aname"] = 100;
    scores["Cname"] = 10;
    scores["Bname"] = 1;
    
    /*
     
    //it で管理
    //auto 変数＝マップ名.begin()で管理可能
    auto it = scores.begin();
    //pがイテレータもしくはポインターの時　it->firstでかける
    std::cout << it -> first << "  " << it -> second << std::endl;
     
     */
    
    //ポイント；順序がバラバラになる
     
    for(auto &[name,point]:scores)
    {
        std::cout << name << " : " << point << " \n";
    }
    
    std::cout << "\n";
    
    
    for(const auto& p: scores )
    {
        //pはオブジェクトなので、p.first
        std::cout<<  p.first << ":" << p.second <<std::endl;
        
        
    }
    
    // if(scores.find("Aname"))
    

    return 0;
}
