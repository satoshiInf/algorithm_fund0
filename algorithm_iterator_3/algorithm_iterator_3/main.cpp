
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
   
    if(it != scores.end())
    {
        std::cout << it->first << " "<< it ->second;
    }
    

    
    return 0;
}



　/*
for 文は「線形探索」をするための道具。
つまり、配列やリストのように、要素を１つずつ順番に見る構造に適しています。
非線形構造（例：木構造の std::map）は効率的に探索できるため、 for 文を使って全要素を回る必要がありません。
ような探索メソッドを使い、必要な要素に直接アクセスできます。
  
  線形探索（Linear Search）
  index:      0    1    2    3    4
  data:     [A]  [B]  [C]  [D]  [E]
              ↑    ↑    ↑    ↑    ↑
            最初→→→→→→→→→→→→最後

        「E」を探すなら、A→B→C→D→E（最大5回調べる）

  
  「非線形構造（non-linear）」
  C
/   \
A     E
    / \
   D   F

  |       | 線形構造（vector, list）      | 非線形構造（map, tree）  |
  | ----- | ----------------------- | ----------------- |
  | 探し方   | A → B → C → D → E（全部見る） | C → E → F（分岐しながら） |
  | イメージ図 | `A - B - C - D - E`     | \`\`\`            |

  
  */
