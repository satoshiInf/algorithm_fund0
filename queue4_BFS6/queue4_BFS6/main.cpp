//
//  main.cpp
/*
 以下のような無向グラフがあります（ノードは 0 から 5 まで）：
 コピーする
 編集する
 0 - 1 - 2
 |   |
 4 - 3
 |
 5
 このグラフを 隣接リスト形式で与えます。
 ノード 0 からノード 2 までの 最短距離（何本の辺を通るか） を、幅優先探索（BFS） を使って求めてください。
 */
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
        {1,4}, //0
        {0,2,3}, //1
        {1}, //2
        {1,4},//3
        {0,3,5},//4
        {4}//5
    };
    
    std::vector<bool> visited(6,false);
    std::vector<int> distance(6,-1);
    visited[0] = true;
    
    std::queue<int> q;
    q.push(0);
    visited[0] = true;
    distance[0] = 0;
    
    while(!q.empty() )
    {
        int node = q.front();
        q.pop();
        
       // std::cout << node << std::endl;
        for(int next: graph[node])
        {
            if(!visited[next])
            {
                q.push(next);
                visited[next] = true;
                distance[next] = distance[node] +1;
                q.push(next);
                
                if(next ==2) //2がゴール
                {
                    std::cout<< "最短距離" << distance[next] << std::endl;
                    return 0;
                }
            }
        }
    }
    std::cout << "error" << std::endl;

    return 0;
}
