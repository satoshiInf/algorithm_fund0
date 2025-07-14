
/*
 
 scanfやcinでは\nを使用しない
 
 // it ->firstでアクセスする
 
 */






#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<std::string, int> scores;
    scores["A"] = 100;
    scores["B"] = 10;
    scores["C"] = 1;
    scores["D"] = 0;
    
    std::string key;
    std::cin>> key;
    
    //二分探索を実行する
    auto it = scores.find(key);
    // std::map<std::string, int>::iterator it = scores.find(name);

    //このコード自体が二分探索を実行するのでfor文を使う必要がな
    
    if(it != scores.end()) //itが要素の外にない= みつかった
    {
        //find
        // it ->firstでアクセスする
        std::cout << it->first <<" = "<< it->second << std::endl;
        
        //std::cout << it;  :error
        /*auto it = scores.find(key); の意味
        it は変数であり、型は std::map<std::string, int>::iterator
        つまり map<string, int> の「1要素を指すポインタのようなもの」なので普通の変数と異なることが明示される
         */
        //イテレータはほとんどの場合でポインタとして使用できるがポインタに直す作業に必要
        //*itは値、＆でアドレス化される。void＊はポインター型に変換
        
        std::cout << static_cast<void*> (&(it)) << std::endl; //it自体
        std::cout << static_cast<void*> (&(*it)) << std::endl; // itが指し示すアドレス
    }
    else
    {
         //not find
    }
    
    

    
    return 0;
}
