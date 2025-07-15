//
//  main.cpp
//  PassingByReference3
//
//  Created by Satoshi on 7/15/25.

/*
 5つの整数からなる配列 arr を受け取り、そのすべての要素を 2倍にする関数 doubleElements を作成すること。
 配列の受け渡しには 参照渡し（int (&arr)[5] の形式） を用いること。
 関数の戻り値は void型 とし、返り値は使わないこと。
 main 関数内で {1, 2, 3, 4, 5} という配列を用意し、それを doubleElements に渡して処理を実行すること。
 処理後、配列の全要素を main 関数で出力して、すべての要素が2倍になっていることを確認すること。
 
 
 
 ポイント
 関数引数として int arr[] または int* arr と書いた時点で、それは「ポインタ」になり、配列のサイズ情報が失われる。
 
 １）printArray(a, 5);
 void printArray(int arr[], int size)
 {
     for (int i = 0; i < size; ++i) std::cout << arr[i] << " ";
 }
 
 ２）func(a, 5);
 void func(const std::vector<int>& vec)
 {
     std::cout << vec.size() << std::endl;  // OK: 内部にサイズ情報を持つ
 }
 
 */
//

#include <iostream>
#include <vector>
//サイズの情報を失ってしまうので
void voidDoubleElements1(int (&arr)[5])
{
    for(int i = 0; i < 5; i++)
    {
        arr[i] *= 2;
    }

}
/*
void voidDoubleElements2(int &arr,int index)
{
    for(int index = 0; index < 5; index++)
    {
        arr[index] *= 2;
    }

}
 */

void voidVectorElements2(std::vector<int>&vec )
{
// 　for(int element :vec) これはコピー
    for(int& element : vec)
    {
        element *= 2;
    }
    
    for(int& element : vec)
    {
        std::cout << element << " ";
    }
    
    std::cout << "\n";
}


void voidVectorElements3(std::vector<int>& vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        vec[i] *=2;
    }
    
    for(int i = 0; i < vec.size(); i++)
    {
        std:: cout <<vec[i] << " ";
    }
    
    std::cout << "\n";
}


int main()
{
    int arr[5] ={1,2,3,4,5};
    voidDoubleElements1(arr);//配列全体で仮引数を作る
    
    
    /*
     void voidDoubleElements(int (&arr)[5])
     {
         for(int i = 0; i < 5; i++)
         {
             arr[i] *= 2;
         }
     }
     */
    for(int i = 0; i < 5; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    
    std::cout << "\n next" << std::endl;
    
    std::cout << "\n";
    
    std::vector<int>vec ={1,2,3,4,5};
    
    voidVectorElements2(vec) ;
    
    std::cout << "\n";
    
    voidVectorElements3(vec) ;
    
    std::cout << "\n";
    
    
    
    
    
    
    
    return 0;
}


/*
 
 仮引数がarr（配列全体をさせるのはなぜ）
 関数の引数は「渡したい値（実引数）」を受け取るための変数（仮引数）を用意する必要がある
 → 例えば void func(int x) なら、x が仮引数
 配列を関数に渡すときは、
 通常は「配列の先頭のアドレス（ポインタ）」が渡される
 C++では「配列の参照」を使うと、配列のサイズ情報を保持したまま参照できる
 なので、関数の仮引数に配列の名前（arr）を使って、
 呼び出し元の配列を「参照」または「ポインタ」で受け取るための変数として宣言する
 
 C++では配列全体を参照として関数に渡すことができます。
 配列全体を指定するとは？
 配列は連続したメモリ領域に要素が並んでいます。
 例えば int arr[5]; は5個のintが連続している領域です。
 関数の仮引数を「配列の参照」にすると、その配列全体を一つの単位として関数に渡せるのです。


 */

