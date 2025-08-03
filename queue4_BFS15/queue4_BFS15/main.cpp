//
//  main.cpp
//  queue4_BFS15
//
//  Created by Satoshi on 8/3/25.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

int main()
{
    std::vector<std::vector<int>> graph
    =
    {
        {1,2},
        {3},
        {3},
        {4},
        {}
    };
    
    int n = static_cast<int>(graph.size() );
    std::vector<bool> visited(n,false);
    visited[0] = true;
    
    std::queue<int> q;
    q.push(0);
    
    std::vector<int> distance(n,-1);
    std::vector<int> prev(n,-1); // prev[0]は−１で固定される
    
    std::vector<int> count(n, 0);
    count[0] = 1;
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        std::cout << node <<std::endl; // 階層順に出力
        
        //距離の算出、prevとnodeを繋げる
        for(int next: graph[node])
        {
            if(!visited[next])
            {
                visited[next] = true;
                q.push(next);
                distance[next] = distance[node]+ 1;
                prev[next]= node;
                count[next] = count[node];
            }
            else if(distance[next] == distance[node]+1)
            {
                count[next] += count[node];
                
            }
        }
        
        
    }
    
    std::cout<<"最短距離" ;
    for(int i = 0; i < n ; i++)
    {
        std::cout << "Node " << i <<" 距離:"<< distance[i] <<std::endl;
    }
    
    // 末端から走査
    for(int goal = 0; goal <n ; goal++)
    {
        if(goal == 0)
        {
            continue;
        }
        std::vector<int> path;
        for(int current = goal; current!= -1; current = prev[current])
        {
            //始点には親がいないので、prev[start] = -1 となっている。−１になったら実行せずに中止される
            path.push_back(current);
        }
        //要素の順番を反転させる
        std::reverse(path.begin(), path.end());
            
        /*
         current = prev[current]　// =(前のnode)
         部分                 意味
         int cur = goal      目的地（goal）からスタート
         cur != -1           開始地点までたどり着いていない（≒親がまだある）間はループ継続
         cur = prev[cur]    一つ前のノードに戻る（逆向きにたどる）
         
         cur != -1 の意図（= ループの終了条件）
         経路復元では、prev 配列に「どこから来たか（前のノード）」の情報が入っています。
         つまり、prev[i] はノード i に来る直前のノード。
         始点には親がいないので、prev[start] = -1 となっているのが一般的です。
         だから、cur != -1 の条件は：
         「始点にたどり着いたらループ終了するようにする」＝ 経路の逆順をたどる終了判定
         */
        
        std::cout <<"0 ->" << goal <<" 経路:";
        for(size_t i = 0; i < path.size(); i++)
        {
            std::cout<< path[i];
            if(i +1 < path.size())
            {
                std::cout <<" ->";
            }
        }
        std::cout <<"\n" <<std::endl;
            
    }
    
    std::cout << "--- 最短距離と経路数 ---\n";
    
    for(int i = 0; i < n; i++)
    {
        std::cout<<"ノード"<< i <<"距離"<< distance[i] <<", 経路数=" << count[i] << std::endl;
    }
    
    std::cout << "\n--- 経路復元 ---\n";
    
    for(int goal = 0; goal < n; goal++)
    {
        if(distance[goal] == -1) //-1に達したら終わり
        {
            continue;
        }
        std::vector<int>path;
        for(int current = goal; current != -1; current = prev[current])
        {
            path.push_back(current);
        }
        std::reverse(path.begin(), path.end());
        
        std::cout << "0->" << goal << "経緯 :";
        for(int i = 0; i < path.size(); i++)
        {
            std::cout<< path[i];
            if( i+1 < path.size() )
            {
                std::cout << "->";
            }
            
        }
        std::cout <<"\n";
    }
    
    
    
    return 0;
}
