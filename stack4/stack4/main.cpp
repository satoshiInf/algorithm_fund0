

#include <iostream>
#define MAX 5

/*
#include <stdexcept>
// 最低限、以下の3つを押さえておくと十分応用できます：
throw std::underflow_error("空です");
throw std::overflow_error("いっぱいです");
throw std::runtime_error("実行時エラー");
 
 | 使う場所        | 推奨される例外クラス                                 | 理由              |
 | ----------- | ------------------------------------------ | --------------- |
 | `pop()` で空  | `std::underflow_error`                     | データがない          |
 | `push()` で満 | `std::overflow_error`                      | 容量オーバー          |
 | 不正な peek    | `std::runtime_error` or `invalid_argument` | データが存在しないのにアクセス |

 */


struct Stack
{
    int data[MAX];
    int top;
    
    Stack(): top(-1){};
    
    
    void push(int val)
    {
        if(top >= MAX)
        {
            throw std::overflow_error("エラー発生");
        }
        data[++top] = val;
    }
    
    void pop()
    {
        if(top == -1)
        {
            throw std::underflow_error("エラー発生");
        }
        top--;
    }
    
    int peek()
    {
        if(top == -1)
        {
            std::cout << "スタックは空です"<< std::endl;
        }
        return data[top];
    }
    
    bool empty()
    {
        
        //throw("エラー発生");
        return top== -1;
    }
    
};

int main()
{
    Stack s;
    
    try
    {
        s.push(5);
        s.push(10);
        s.push(7);
        s.push(1);
        s.pop();
        s.pop();

    }
    
    catch(const std::underflow_error &error)
    {
        std::cerr <<"スタックがありません"<< error.what() <<std::endl;
    }
    catch(const std::overflow_error &error)
    {
        std::cerr <<"スタックがつめません"<< error.what() <<std::endl;
    }
    catch(const std::exception &error)
    {
        std::cerr <<"その他のエラー"<< error.what() <<std::endl;
    }
    
 
    return 0;
}
