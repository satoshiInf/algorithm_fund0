//
//  main.cpp
//  queue4_BFS11
//
//  Created by Satoshi on 8/3/25.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>


int main()
{
   std::vector<std::vector<int>> graph =
    {
        {1,2},//node0
        {2,3},//node1
        {3},
        {4},
        {}
    };
    
    int n = static_cast<int>(graph.size() );
    std::vector<int> distance = {n,false};
    
    // node 段目場所
    // next nodeに書かれた要素
    //nodeの要素にnextが書かれている場合は
    //distance[next] = distance[node] + 1が成り立つ
    
    std::vector<bool> visited(n, false);
    visited[0] = true;
    distance[0]= 0;
   
    std::queue<int>q;
    q.push(0);
    
    while(!q.empty())
    {
        int node = q.front();
        q.push(node);
        q.pop();
        std::cout<< node << std::endl;
        
        for(int next: graph[node])
        {
            
            //初見の時だけ
            if(!visited[next])
            {
                q.push(next);
                visited[next]= true;
                distance[next] = distance[node] + 1;
                
                /*
                 !visited[next]がないと
                 
                 graph =
                 {
                     {1},   // 0 → 1
                     {2},   // 1 → 2
                     {0}    // 2 → 0  ← ⚠️ サイクル（ループ）
                 0 → 1 → 2 → 0 → 1 → 2 → 0 → ... 無限ループ
                 };
                 */
                
            }
        }
        
    }
    
    
    
    return 0;
}
