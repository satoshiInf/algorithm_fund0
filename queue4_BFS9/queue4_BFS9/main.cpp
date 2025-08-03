//
//  main.cpp
//  queue4_BFS9
//
//  Created by Satoshi on 8/3/25.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

int main()
{
    try
    {
        std::vector<std::vector<int>> graph =
        {
            {1,2},
            {3},
            {3},
            {}
        };
        
        std::vector<bool> visited(4, false);
        visited[0] = true;
        
        std::queue<int> q;
        q.push(0);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            std::cout << node << std::endl;
            
            if(node <0 || node >= graph.size() )
            {
                throw std::out_of_range("データなし");
            }
            
            for(int next: graph[node])
            {
                if(next <0 || next >= visited.size())
                {
                    throw std::out_of_range("範囲外");
                }
                
                if(!visited[next])
                {
                    q.push(next);
                    visited[next] = true;
                }
            }
            
        }
        
    }
    catch( const std::out_of_range& error)
    {
        std::cout << " " << error.what() << std::endl;
    }
    catch( const std::exception& error)
    {
        std::cout << " " << error.what() << std::endl;
    }
    
    
    return 0;
}
