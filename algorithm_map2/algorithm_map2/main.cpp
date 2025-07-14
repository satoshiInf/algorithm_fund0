//
//  main.cpp
//  algorithm_map2
//
//  Created by Satoshi on 7/14/25.
//

#include <iostream>
#include <map>

int main()
{
    // map - type - name of map
    std::map<std::string, int> scores;
    
    //input data
    //name[first] = seond
    scores["Cname"] = 100;
    scores["Bname"] = 10;
    scores["Aname"] = 1;
    
    
    //it で管理
    //auto 変数＝マップ名.begin()で管理可能
    auto it = scores.begin();
    
    //pがイテレータもしくはポインターの時　it->firstでかける
    std::cout << it -> first << "  " << it -> second << std::endl;
    
    //sorted
    for(auto &[name,point]:scores)
    {
        std::cout << name << " : " << point << " \n";
    }
    
    for(const auto& p: scores )
    {
        //pはオブジェクトなので、p.first
        std::cout<<  p.first << ":" << p.second <<std::endl;
        
        
    }
    
    // if(scores.find("Aname"))
    

    return 0;
}
