//
//  main.cpp
//  queue4_BFS3
//
//  Created by Satoshi on 8/2/25.
//

#include <iostream>
#include <vector>
#include <queue>

int main()
{
    /*
         0
        / \
        1  2
        \ /
         3

     を作る
     
     片方向
     */
    
    std::vector<std::vector<int>>
    graph
    =
    {
        {1,2}, // node0
        {3},   //node1
        {3},   //node2
        {}  //node3
    };
    
    /*
     vector<bool> visited
     qに入れていないときfalseで入れていたらtrue
     
     役割：ノード i をすでに訪れたかを記録する
     値：true → すでに訪問した、false → 未訪問
     初期状態：すべて false（誰も訪れていない）
     visited[next_node] = true;
     目的：同じノードを何度も訪問しないようにする（無限ループ防止）
     */
    
    //nodeごとにvectorを作る
    std::vector<bool> visited(4, false);
    visited[0] = true;
    
    /*
     visitedのboolをもとにqueueを作る
     */
    
    std::queue<int> q;
    q.push(0);
    visited[0] = true;
    
    while(!q.empty())
    {
        //nodeで出力、frontをpopで削除して次に回す
        //qの削除と出力パート
        int node = q.front();
        q.pop();
        std::cout << node;
        /*
        キューに [10, 1, 2, 3] が入っているとして、ループで上記処理を行うと：
        出力: 10123
        */
        
        
         //qを追加する
        for(int next: graph[node])
        {
            if(!visited[next]) //falseの時のみ追加、すでに追加しているものは含めない
            {
                q.push(next);
                visited[next] =true;
            }
        }
    }
    
    
    return 0;
}
