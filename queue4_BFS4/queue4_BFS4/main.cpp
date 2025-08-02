
#include <iostream>
#include <vector>
#include <queue>

int main()
{
    
    std::vector<std::vector<int>> graph
    =
    {
        {1,2}, //node0
        {3}, //node1
        {3}, //node2
        {} //node3
    };
    
    std::vector<bool> visited (4, false);// node全てにfalse;
    visited[0] = true;
    
    std::queue<int> q;
    q.push(0);
    visited[0] = true;
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        std::cout << node;
        
        
        for(int next: graph[node]) //graphにおける各ノードの中の要素でループ
        {
            if(visited[next])
            {
                q.push(next);
                visited[next]= true;
                
            }
            
            /*
                 0
                / \
                1  2
                \ /
                 3
             
             0:1,2
             1:3
             2:3
             3:なし
             :以降でループ
             */
            
            
        }
        
    }
    
   
    return 0;
}
