/*
 
 
 | 目的           | コンテナ                    | 向いている場合                                        |
 | ------------ | ----------------------- | ---------------------------------------------- |
 | **順序付きのリスト** | `vector`                | 番号で管理したいとき（例: `scores[0]`）                     |
 | **キーと値の対応**  | `map` / `unordered_map` | keyからアクセスしたい時に使用する。
 名前やIDなど「ラベル」で値にアクセスしたいとき（例: `scores["Alice"]`） |
 
 ポイント：
 valueだけで管理するならvectorでkeyとvalueで管理するならmap

 */

#include <iostream>
#include <vector>


int main()
{
    std::vector<int> scores ={100,90,80};
    
    for(int i = 0; i < scores.size() ; i++)
    {
        std::cout  << i << " has :"<< scores[i] << std::endl;
        
        
    }
    
    return 0;
}
