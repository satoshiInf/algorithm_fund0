//
//  main.cpp
/*
 問題：
 次のような有向グラフが与えられます。このグラフをBFSで探索し、
 各ノードに到達する最短距離（スタートノードからのステップ数）を出力してください。
 🔹 入力グラフ（隣接リスト形式）：
 std::vector<std::vector<int>> graph =
 {
     {1, 2},    // 0番ノード → 1, 2
     {2, 3},    // 1番ノード → 2, 3
     {3},       // 2番ノード → 3
     {4},       // 3番ノード → 4
     {}         // 4番ノード → 終点
 };
 🔹 条件：
 スタートノードは 0
 到達不能なノードは -1 を表示する
 BFSを使って最短距離を求める
 例外処理（try-catch）を含めること

 */


#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

/*
  0 - 2
  | / |
  1   |
  |   |
  3---
  |
  4
 
 番号そのもの
 node0は　{1,2}と繋がっている
 node1は  {2,3}と繋がっている
 node2は  {3}と繋がっている
 node3は  {4}と繋がっている
 
 
 node1までの距離　＝　node0までの距離 + 1
 node2までの距離　=  node0までの距離 + 1
 node3までの距離　＝　node1までの距離 + 1
 node4までの距離　＝  node3までの距離 + 1
 
 
 
 node0の0はnode
 node0に格納されるものはnext
 nodeに格納される要素がnextなので distance[node]+1がdistance[next]になる
 distance[next] = distance[node]+1;
 
 0 - 2
 | / |
 1   |
 |   |
 3---
 |
 4
 
 0
 |
 1 node1では{3}とあり、３と繋がっている、distance[node]は不明
 |
 3 next      node1は3と繋がっている node＝1の時にnextは3になる
 |　　　　    distance[next] = distance[node] +1
 4
 
 
 */

int main()
{
    std::vector<std::vector<int>> graph
    =
    {
        {1, 2},    // 0番ノード → 1, 2
        {2, 3},    // 1番ノード → 2, 3
        {3},       // 2番ノード → 3
        {4},       // 3番ノード → 4
        {}
    };
    
    //int n = graph.size();
    std::vector<int> distance(5, -1);
    std::vector<bool> visited(5, false);
    
    int start = 0;
    distance[start] = 0;
    visited[0] = true;
    
    std::queue<int> q;
    q.push(start);
    
    
    try
    {
        
        /*
         q = [0]
         distance = [0, -1, -1, -1, -1]  // スタートノード0は距離0
         visited = [true, false, false, false, false]
         
         whileループ1回目（node = 0）
         node = q.front() = 0
         q.pop() → q = []
         graph[0] = {1, 2}
         next = 1:
         distance[0]= 0
         !visited[1] → true → qに1を追加、距離は 0 + 1 = 1
         next = 2:
         distance[0]= 0
         !visited[2] → true → qに2を追加、距離は 0 + 1 = 1
         
         
         whileループ2回目（node = 1）
         node = 1
         q.pop() → q = [2]
         graph[1] = {2, 3}
         next = 2: visited[2] == true → スキップ
         next = 3:
         !visited[3] → true → qに3を追加、距離は 1 + 1 = 2
         
         distance[next]= distance[node] + 1;
         distance[3]= distance[1] + 1; // 3までの距離はnode１までの距離＋１
         
         q = [2, 3]
         distance = [0, 1, 1, 2, -1]
         visited = [true, true, true, true, false]

         
         
         */
        while(!q.empty() )
        {
            //追加されたnodeをもとにfor文を回す
            //追加されたqを取得して削除
            int node = q.front();
            q.pop();
            std::cout << node << std::endl;
            
            if( node < 0 || node >= graph.size() )
            {
                throw std::out_of_range("範囲外");
            }
            
            //追加され残っているnodeをもとにnode内に格納された配列の要素でfor文を回す
            
            for(int next: graph[node])
            {
                if(next < 0 || node >= graph.size() )
                {
                    throw std::out_of_range("範囲外");
                }
                
                if(!visited[next])
                {
                    //qに追加する
                    q.push(next);
                    visited[next] = true;
                    distance[next]= distance[node] + 1;
                    
                }
                
                //std::cout <<"Node "<< node << counter << std::endl;
                
                
            }
        }
    }
    catch(const std::out_of_range &error)
    {
        std::cerr << "範囲外"<<error.what() << std::endl;
    }
    catch(const std::exception &error)
    {
        std::cerr << "その他エラー"<<error.what() << std::endl;
    }
    
    for(int i =0; i < 5; i++)
    {
        std::cout << "Node" << i <<" :" << distance[i] <<std::endl;
    }
        
   
    return 0;
}
