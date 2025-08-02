//
//  main.cpp
//  stack3
//
//  Created by Satoshi on 8/1/25.
//

#include <iostream>

#define MAX 5

struct Stack
{
    int data[MAX];
    int top;
    
    Stack(): top(-1){}//topに−１をセットする cf. right(nullptr)と同じ理屈
    /*
     Stack(){　top = -1;　} と同じ意味
     */
    
    void push(int val)
    {
        if(top >= MAX -1)
        {
            std::cout<<"容量オーバー"<<std::endl;
            return;
        }
        else
        {
            data[++top] = val;
        }
    }
    
    void pop()
    {
       if(top <= -1)
       {
           std::cout<<"これ以上減らせません"<<std::endl;
           return;
       }
       else
       {
           top--;
       }
    }
    
    //例外処理に改良する
    int peek()
    {
        if(top == -1)
        {
            throw std::runtime_error("スタックが空である");
            //return -1;
        }
        else
        {
            return data[top];
        }
    }
    
    bool empty()
    {
        //topが−１の時true
        return top == -1;
    }
};



int main()
{
    Stack s;
    
    
    /*
     メイン関数でtryとcatchを書いて　throwは呼び出しの関数内で例外に該当したものを書く
     */
    
    try
    {
        s.push(5);
        s.push(10);
        std::cout <<s.peek()<<std::endl;
        s.pop();
        s.pop();
        std::cout <<s.peek()<<std::endl;
        
    }
    catch(const std::exception &error)
    {
        std::cout << "error : " << error.what() << std::endl;
    }
      
    return 0;
}
