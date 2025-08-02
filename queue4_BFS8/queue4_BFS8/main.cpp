
#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::vector<std::vector<int>> graph
    =
    {
        
        {1,2},
        {3},
        {3},
        {}
    };
    
    std::vector<bool> visited(4,false);
    visited[0] = true;
    
    std::queue<int> q;
    q.push(0);
    visited[0] =true;
    
    while(!q.empty() )
    {
        int node = q.front();
        q.pop();
        std::cout << node <<std::endl;
        
        for(int next : graph[node])
        {
            if(!visited[next])
            {
                q.push(next);
                visited[next] = true;
            }
            
        }
    
    }

    return 0;
}
