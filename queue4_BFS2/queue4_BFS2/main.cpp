
/*
 vector<vector<int>> graph(n);
 vector<bool> visited(n, false);
 queue<int> q;
 
 🔹1. vector<vector<int>> graph
 役割：グラフの隣接リスト（隣接ノードの情報を格納）
 構造：graph[i] はノード i に隣接しているノードの一覧（つまり vector<int>）

 例：
 // 頂点0に1と2がつながっている
 graph[0] = {1, 2};
 目的：ノード i から辿れるノードたちを管理するために使う
 
 🔹2. vector<bool> visited
 役割：ノード i をすでに訪れたかを記録する
 値：true → すでに訪問した、false → 未訪問
 初期状態：すべて false（誰も訪れていない）
 visited[next_node] = true;
 目的：同じノードを何度も訪問しないようにする（無限ループ防止）

 🔹3. queue<int> q
 役割：BFS用の探索キュー。次に探索すべきノードの順番を保持する。
 特徴：FIFO（先に入れたものから順に処理）

 q.push(i)：探索対象として登録
 q.front()：現在の探索対象を見る
 q.pop()：探索対象をキューから取り出す（処理済みにする）
 目的：探索順序をBFS（幅優先）にするために使用


 
 */

#include <iostream>
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
    
    
    std::vector<bool> visited (4, false);
    std::queue<int> q;
    q.push(0);
    visited[0] = true;
    
    /*
     vector<vector<int>> graph =
     {
         {1, 2},  // 0の隣接ノード
         {3},     // 1の隣接ノード
         {3},     // 2の隣接ノード
         {}       // 3の隣接ノードなし
     };
     */
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        std::cout<< node <<"";

        for(int next: graph[node])
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
