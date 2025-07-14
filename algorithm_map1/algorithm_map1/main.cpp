

#include <iostream>
#include <map>

int main()
{
    //変数をここで宣言しない、型はここ
    std::map<std::string, int> scores;
    scores["name1"] =1000;
    
    //ここで変数名を作る
    for(auto& [key,value]:scores)
    {
        std::cout<< key << " : " << value << "\n " <<std::endl;
    }
    
    //こっちも変数なし
    //イテレータは→を使う
    auto it = scores.begin();
    std::cout << std::endl;
    std::cout<< it->first << std::endl;
    std::cout<< it->second << std::endl;
    
    for(const auto& p: scores)
    // これはpをオブジェクトとして,オブジェクトの時はobject.first object.second
    {
        std::cout << p.first << ": " << p.second << std::endl;
        
    }
    
    
    
  
    return 0;
}


