//
    /*
     0
    / \
    1   2
    |    \
    3     4

    スタート：0
    探索順序：0 → 1 → 2 → 3 → 4
    
     レベル0：    0
                 |
     レベル1：   1  2
               /   \
     レベル2： 3       4
     
     比較
     BFSは「同じ階層のノードを全て調べてから次の階層へ進む」
     Breadth-First Search
     DFSは「一つの枝を深く深く掘り下げていく」

 */


#include <iostream>
#include <vector>
#include <queue>


int main()
{
    std::vector<std::vector<int>>
    graph =
    {
        {1, 2},  // 0の隣接ノード : 0は、1,2と繋がっている
        {3},     // 1の隣接ノード : 1は、3と繋がっている
        {3},     // 2の隣接ノード : 2は、3と繋がっている
        {}       // 3の隣接ノードなし
    };
    
/*
     0
    / \
    1  2
    \ /
     3

 */
    std::vector <bool> visited(4,false);
    //長さが４、全ての要素をfalseで初期化する
    /*
     Index:   0     1     2     3
     Value: false false false false
     */
    std::queue<int> q;
    q.push(0);
    visited[0] = true;
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        std::cout<< node << " ";
        
        for( int next: graph[node])
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
