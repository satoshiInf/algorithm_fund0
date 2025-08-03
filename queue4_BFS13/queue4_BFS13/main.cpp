//
//  main.cpp
/*
 では、先ほどの「最短距離と経路復元（BFS）」の理解をさらに深めるための **作成問題（類題）** を出します。
 ## 🎯 類題：最短距離と複数経路数のカウント
 ### 問題
 以下の有向グラフが与えられます：

 
 std::vector<std::vector<int>> graph =
 {
     {1, 2},     // 0 → 1, 2
     {3},        // 1 → 3
     {3},        // 2 → 3
     {4},        // 3 → 4
     {}          // 4（終点）
 };
 
 ノード 0 から各ノードへの **最短距離** に加えて、
 **最短距離で到達する経路の本数** も求めてください。

 ---
 ### 🔧 要求されること
 * BFSを使って、ノード0からの最短距離を求める
 * 同時に「その距離で到達する方法が何通りあるか」を数える
 * 出力例のように、各ノードについて表示する
 ---
 ### ✅ 出力例
 ノード 0: 距離 = 0, 経路数 = 1
 ノード 1: 距離 = 1, 経路数 = 1
 ノード 2: 距離 = 1, 経路数 = 1
 ノード 3: 距離 = 2, 経路数 = 2
 ノード 4: 距離 = 3, 経路数 = 2

 > ノード3へは、0→1→3 と 0→2→3 の2通りあります
 > 同様に、ノード4へも2通りです

 ---

 ### 🧠 ヒント

 * `std::vector<int> distance(n, -1);`
 * `std::vector<int> count(n, 0);` ← 経路数
 * 最初は `distance[0] = 0`, `count[0] = 1`
 * `next` を訪問する際：

 ```cpp
 if (distance[next] == -1) {
     distance[next] = distance[node] + 1;
     count[next] = count[node];
     q.push(next);
 } else if (distance[next] == distance[node] + 1) {
     count[next] += count[node]; // 同じ最短距離なら加算
 }

 ### ✏️ 応用アイデア（余裕があれば）

 * 到達できないノード（`distance[i] == -1`）の扱いも出力
 * グラフをファイルから読み込んでもOK

 「実装してみたい」「答え合わせしたい」と思ったら、続きを一緒に作れますよ。やってみますか？

 */


//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

int main()
{
    std::vector<std::vector<int>> graph
    =
    {
        {1, 2},     // 0 → 1, 2
          {3},        // 1 → 3
          {3},        // 2 → 3
          {4},        // 3 → 4
          {}
    };
    
    int n = static_cast<int>(graph.size() );
    std::vector<bool> visited(n,false);
    visited[0] = true;
    
    std::queue<int> q;
    q.push(0);
    
    std::vector<int> distance(n, -1);
    std::vector<int> prev(n, -1);
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        std::cout << node << std::endl;
        
        //nodeの要素に対する処理
        for(int next: graph[node])
        {
            if(!visited[next])
            {
                visited[next] =true;
                q.push(next);
                distance[next] = distance[node]+ 1;
                prev[next] = node;
            }
        }
    }
    
    //到達したい目的地ノードをnodeとする
    //goalが０の時〜４の時まで
    
    std::cout << "--- 最短距離 ---\n";
    for(int i = 0; i < n ; i++)
    {
        std::cout << "Node " << i << ": 距離 = " << distance[i] << std::endl;
    }
        
    
        /*
         goal から出発して、prev をたどって「前のノード」に戻っていく
         たどりながら path に順番に追加していく
         最後は prev[cur] == -1 になり、ループ終了（出発点に到達）
         */
        
    std::cout << "\n--- 経路復元 ---\n";
    for (int goal = 0; goal < n; goal++)
        {
            if (distance[goal] == -1 || goal == 0)
                continue; // 未到達 or 自分自身はスキップ　 //次の値でまたループを回す

            std::vector<int> path;
            for (int cur = goal; cur != -1; cur = prev[cur])
            {
                path.push_back(cur);
            }
            std::reverse(path.begin(), path.end());//そのままpathを入れ替える
            /*
            たとえば：
            もし goal = 5 のとき、prev の中身が次のようになっていたら：
            prev[5] = 3
            prev[3] = 1
            prev[1] = 0
            prev[0] = -1
            この for のループで：
            cur = 5 → 3 → 1 → 0 → 終了
            この時点の path は [5, 3, 1, 0] になります（逆順）
            */
            
            std::cout << "0 → " << goal << " の経路: ";
            for (size_t i = 0; i < path.size(); i++)
            {
                std::cout << path[i];
                if (i + 1 < path.size()) std::cout << " → ";
            }
            std::cout << "\n";
    }

      
    return 0;
}
