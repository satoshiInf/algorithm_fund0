//
//  main.cpp
/*
 問題：最短距離と経路復元（作成）
 以下のような有向グラフが与えられたとき、ノード 0 から各ノードへの最短距離と経路を表示するプログラムを作成してください。
 std::vector<std::vector<int>> graph = {
     {1, 2},   // 0 → 1, 2
     {3},      // 1 → 3
     {3, 4},   // 2 → 3, 4
     {5},      // 3 → 5
     {},       // 4（終点）
     {}        // 5（終点）
 };
 出力例（期待される出力）
 makefile
 コピーする
 編集する
 ノード 0 からノード 5 への最短距離: 3
 経路: 0 → 1 → 3 → 5
 ノード 0 からノード 4 への最短距離: 2
 経路: 0 → 2 → 4

 （他のノードについても出力）
 🎯 要求されること
 BFS を使って、0 から各ノードへの 最短距離 を求める
 各ノードに対して、どの経路で到達したか を表示する（前のノードを記録する）
 🔧 ヒント
 std::vector<int> distance(n, -1); で距離管理
 std::vector<int> prev(n, -1); で「前のノード」を記録しておくと、経路を逆順にたどって復元できる
 ✏️ 応用アイデア（できたら）
 経路を std::stack や std::vector で逆順から復元
 ユーザーから始点・終点を入力させてもOK

 */
//

#include <iostream>

int main()
{
    std::vector<std::vector<int>> graph =
    {
        {1, 2},   // 0 → 1, 2　graph[0] = {1,2}
        {3},      // 1 → 3
        {3, 4},   // 2 → 3, 4
        {5},      // 3 → 5
        {},       // 4（終点）
        {}        // 5（終点）
    };
   
    int n = static_cast<int>(graph.size() );
    std::vector<bool> visited (n, false);// nこの要素にfalseを代入
    std::vector<int> distance (n, -1);
    //  std::vector<bool> visited={n, false};
    //  std::vector<int> distance={n, -1};は誤り　→ 2要素のベクトル：visited[0] = n, visited[1] = false
    
    std::vector<int> prev(n, -1);
    
    visited[0] = true;
    distance[0] = 0;
    std::queue<int> q;
    q.push(0);
    

    //q.push(0);
    while(!q.empty())
    {
        //graph[0] = {1,2}
        int node = q.front();
        q.pop();
        std::cout << node << std::endl;
        
        for(int next: graph[node]) //node= 0; next = 1,2
        {
            if(!visited[next])
            {
                q.push(next); //q =1,2
                visited[next] = true;
                //distance(1) =distance(0) +1
                //distance(2) =distance(0) +1
                distance[next] = distance[node]+ 1;
                
                /*
                 0 → 1 → 3 → 5
                 prev[1] = 0
                 prev[3] = 1
                 prev[5] = 3
                 「5に来る前は3だった」
                 「3に来る前は1だった」
                 「1に来る前は0だった」
                 → これを逆順にたどることで経路を復元できます。
                 
                 */
                prev[next] = node;
            }
        }
    }
    
    for(int i= 0; i < n; i++)
    {
        std::cout <<"Node:"<< i << " "<< distance[i] <<std::endl;
    }
    
    for(int goal = 0; goal < n; goal++)
    {
        if( goal == 0) //if(distance[goal] == -1|| goal == 0)
        {
            continue;
        }
        
        std::vector<int> path;
        
        for(int cur = goal; cur != -1; cur = prev[cur])
        {
            path.push_back(cur);
        }
        
        std::reverse(path.begin(), path.end() );
        
        std::cout << "0 → " << goal << " の経路: ";
        
        for(size_t i = 0; i < path.size(); i++)
        {
            std::cout << path[i];
            if(i != path.size() -1)
            {
                std::cout << " -> ";
            }
            
        }
            std::cout << std::endl;
    }
    
    
    
    
    
    return 0;
}
