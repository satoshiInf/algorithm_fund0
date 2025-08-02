//
//  main.cpp
/*
 BFS基礎問題：簡単なグラフをBFSで訪問順に出力
 問題文
 以下のようなグラフがあります（ノードは0～3の4つ）：

 0 — 1
 |
 2 — 3
 このグラフの隣接リストは：

 cpp
 コピーする
 編集する
 std::vector<std::vector<int>> graph = {
   {1, 2},  // 0の隣接ノードは1と2
   {0},     // 1の隣接ノードは0
   {0, 3},  // 2の隣接ノードは0と3
   {2}      // 3の隣接ノードは2
 };
 ノード0から幅優先探索（BFS）で順番に訪問したノードを出力してください。

 出力例

 0 1 2 3
 ヒント
 最初にノード0を訪問し、キューに入れます。
 キューから1つずつ取り出し、そのノードに隣接する未訪問ノードをキューに追加していきます。
 訪問済みのノードは再度キューに入れないように気をつけます。
 
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
        {1,2},
        {0},
        {0,3},
        {2}
    };
    
    std::vector<bool> visited(4,false);
    visited[0]=true;
    
    std::queue<int> q;
    q.push(0);
    visited[0] = true;
    
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        std::cout<< node;
    
        for(int next:graph[node])
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
