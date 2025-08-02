
#include <iostream>
#include <queue>

/*
 キューから順に出力したいときは、その都度 pop() を行う
 pushで追加、popで削除、frontで表示、
 */

int main()
{
    std::queue<int> q;
    
    q.push(10);
    q.push(20);
    q.push(30);
    
    std::cout << q.front();
    q.pop();
    std::cout << q.front();
    q.pop();
    std::cout << q.front();
    q.pop();
    //std::cout << q.front(); //frontを使用する時は必ずqが入っていないといけない。入っていない場合はクラッシュする
    
    std::cout<< q.empty();
    
    
   
    return 0;
}
