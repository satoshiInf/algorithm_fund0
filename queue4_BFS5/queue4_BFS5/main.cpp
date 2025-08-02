//
//  main.cpp
//  queue4_BFS5
//
//  Created by Satoshi on 8/2/25.
//

#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::vector<std::vector<int>>
    graph
    
    =
    {
        {1,2},
        {3},
        {3},
        {}
    };
    
    std::vector<bool> visitedOrNot(4,false);
    visitedOrNot[0] = true;
    
    std::queue<int> q;
    q.push(0);
    visitedOrNot[0] = true;
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        std::cout << node; //front()は存在していないといけないのでq.empty()している
        for(int next:graph[node])
        {
            if(!visitedOrNot[next])
            {
                q.push(next);
                visitedOrNot[next] = true;
            }
        }
    }

    return 0;
}
