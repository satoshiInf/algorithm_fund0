//
//  main.cpp
//  queue4_BFS14
//
//  Created by Satoshi on 8/3/25.
//

#include <iostream>
#include <queue>
#include <vector>

int main()
{
    std::vector<std::vector<int>> graph
    =
    {
        {1, 2},     // 0 → 1, 2
        {3},        // 1 → 3
        {3},        // 2 → 3
        {4},        // 3 → 4
        {}          // 4（終点）
    };
    
    int n = static_cast<int>(graph.size() );
    std::vector<int> distance(n, -1);
    std::vector<int> count(n, 0);
    std::vector<int> prev(n, -1);
    
    std::queue<int> q;
    distance[0] = 0;
    count[0] = 1;//経路数をカウントする
    q.push(0);
    
    
    while(!q.empty() )
    {
        int node = q.front();
        q.pop();
        
        std::cout<< node <<std::endl;
        
        for(int next : graph[node])
        {
            if(distance[next]== -1) //初期状態で、まだ距離が未確定のノードは -1 に設定。
            {
                distance[next] = distance[node] +1;
                count[next] = count[node];
                prev[next] = node;
                q.push(next);
                /*
                 背景
                 count[i] は ノード i に最短距離で到達する経路の本数 を表します。
                 BFSでノードを訪れるとき、最短距離が決まったと同時に、そのノードに到達する経路の数も計算します。
                 なぜ count[next] = count[node]; なのか？
                 ノード next に 初めて 最短距離が確定したとき、
                 next へは 今のノード node を経由して到達 するので、
                 node までの経路数がそのまま next への経路数になります。
                 つまり、
                 count[next] = count[node];は
                 「ノード next に最短距離で到達する経路数は、今いるノード node までの経路数と同じだよ」
                 という意味です。
                 もしノード0からノード1へは経路数が1通り（0→1）
                 ノード1からノード3へ新たに到達したとき、
                 ノード3に対する経路数は、ノード1までの経路数（1通り）と同じ数になります。
                 まとめ
                 count[next] = count[node]; は 初めてそのノードに到達したときの経路数の初期化 の役割です。
                 これ以降、同じ最短距離で他の経路からも到達可能なら、経路数を加算していきます。
                 */
                
                
            }
            else if(distance[next] == distance[node]+1)
            {
                count[next] += count[node];
                
            }
                /*
                
                  _ 4通り
               1 |_|
                 3
                 
                 あなたの図を使って、もう少し詳しく解説しますね：
                       0
                      / \
                     1   2
                      \ /
                       3
                       |
                       4
                 🌱 状況の流れ（ノードごと）
                 最初にスタート：
                 count[0] = 1（開始点なので）
                 ノード1と2に到達：
                 両方とも距離 = 1、count[1] = count[2] = 1

                 ノード3に到達（1→3のとき）：
                 distance[3] = 2
                 count[3] = count[1] = 1（初めて到達）

                 ノード3にもう一度到達（2→3のとき）：
                 distance[3] == distance[2] + 1 が成立 → 同じ最短距離
                 ⇒ count[3] += count[2]
                 ⇒ count[3] = 1（もともと） + 1 = 2

                 ノード4に到達（3→4）：
                 count[4] = count[3] = 2（ノード3から2通り来られる）
                 */
    
            }
        }
    
    std::cout << "--- 最短距離と経路数 ---\n";
    
    for(int i = 0 ; i < n; i++)
    {
        std::cout<<"ノード" << i <<"距離"<< distance[i] << ", 経路数 = " << count[i] << "\n";
    }
    
    std::cout << "\n--- 経路復元 ---\n";
    for(int goal = 0; goal < n; goal++)
    {
        if(distance[goal] == -1)
        {
            continue;
        }
        std::vector<int>path;
        for(int cur = goal; cur!= -1; cur = prev[cur])
        {
            path.push_back(cur);
        }
        std::reverse(path.begin(), path.end());
        std::cout<< "0->" <<goal <<"経緯";
        for(size_t i = 0; i <path.size(); i++)
        {
            std::cout<< path[i];
            if(i+1 < path.size())
            {
                std::cout<< "->";
            }
        }
        std::cout << "\n";
    }
    
    
    return 0;
}
