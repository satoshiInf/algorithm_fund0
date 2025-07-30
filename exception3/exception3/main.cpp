/*
 ## 【練習問題】数値の3で割った余り判定と例外処理

 ### 問題文

 ユーザーから整数を何度も入力させてください。
 入力された値を3で割った余りに応じて以下を出力します。
 * 余りが0 → 「余りはゼロです」
 * 余りが1 → 「余りはイチです」
 * 余りが2 → 「余りはニです」
 ただし、余りが0〜2以外の場合は **例外を投げて**、例外メッセージを表示してください。
 また、ユーザーが `"exit"` と入力したらプログラムを終了してください。

 ---

 ### 要件

 * 入力は文字列で受け取る（`std::string`）
 * 入力が数字の場合は `std::stoi` で整数に変換する
 * 変換失敗（数字以外）や余りが想定外の場合は例外処理する
 * `try-catch` で例外を捕まえ、メッセージを表示する
 * ループ処理で何度も入力を受け付ける

 ---

 ### サンプル出力例

 ```
 整数を入力してください（終了するには exit と入力）: 5
 余りはニです
 整数を入力してください（終了するには exit と入力）: 3
 余りはゼロです
 整数を入力してください（終了するには exit と入力）: abc
 例外発生: invalid stoi argument
 整数を入力してください（終了するには exit と入力）: exit
 終了します。
 ```
 
 
 try {
     // 例外が起きる可能性がある処理
 }
 catch (const std::invalid_argument& e) {
     // 入力が数値でないとき
 }
 catch (const std::out_of_range& e) {
     // 数値がintの範囲外のとき
 }
 catch (const std::exception& e) {
     // その他、上記に該当しない一般的な例外
 }
 
 
 example)
 
 catch (const std::invalid_argument& e)
         {
             std::cout << "例外発生: 数字ではありません。" << std::endl;
         }
         catch (const std::out_of_range& e)
         {
             std::cout << "例外発生: 数値が大きすぎます。" << std::endl;
         }
         catch (const std::exception& e)
         {
             std::cout << "例外発生: " << e.what() << std::endl;
         }
 
 
 
 catch (const std::invalid_argument& e)
 catch (const std::out_of_range& e)
 catch (const std::exception& e)

 | catch句                  | 意味                | 起きる例                    |
 | ----------------------- | ----------------- | ----------------------- |
 | `std::invalid_argument` | 数字に変換できない文字列      | "abc", "12a", "one" など  |
 | `std::out_of_range`     | 数字として扱えるが範囲を超えている | "999999999999999999" など |
 | `std::exception`        | その他の一般的な例外を受ける保険枠 | 自作例外、runtime\_errorなど   |


 */

#include <iostream>
#include<stdexcept>


int main()
{
    bool inputExit = false;
    std::string input;
    int number;
    
    
    while(!inputExit)
    {
        std::cout<<" 整数を入力してください（終了するには exit と入力）: " ;
        std::cin >> input;
        
        if(input == "exit")
        {
            inputExit = true;
            std::cout<<" 終了します。\n" ;
            break;
        }
        
        try
        {
            number = std::stoi(input);
            int remainder = number % 3 ;
            // ーを入れるとあまりがマイナスになりエラーを起こす
            
            if(remainder==0)
            {
                std::cout << "余りはゼロです" <<std::endl;
                
            }
            else if(remainder==1)
            {
                std::cout << "余りはイチです" <<std::endl;
                
            }
            else if(remainder==2)
            {
                std::cout << "余りはニです" <<std::endl;
            }
            else
            {
                throw std::runtime_error("例外発生: invalid stoi argument");
                
            }
        }
        /*
        catch(const std::exception& error)
        {
            std::cout<<"exception :" << error.what() << std::endl;
        }
         */
        
        
        catch(const std::invalid_argument& e)
        {
            std::cout << "数字ではないのでエラー";
        }
        catch(const std::out_of_range& e)
        {
            std::cout << "入力された数字が範囲外なのでエラー";
        }
        catch(const std::exception &e)
        {
            std::cout <<"その他の一般的なエラー";
        }
        
    }
    
    
    
  
    return 0;
}
