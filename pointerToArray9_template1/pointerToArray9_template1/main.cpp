/*
 テンプレートは配列全体の引数なので&arr, int (*p)[index]の時
 template <size_t N>
 void func(int (&arr)[N] )
 {
 }
 
配列の要素を出力する関数（テンプレート版）
問題文：
 テンプレート関数 printArray を作成し、引数として「任意のサイズの int 配列の参照」を受け取り、全要素を出力しなさい。
 制約：
 printArray の仮引数はテンプレートを用いて書くこと
 要素数 N も出力する
 
 
 //cin
 std::cin >> N
 
 //配列の入力の型
 int arr[3];
 for (int i = 0; i < 3; ++i)
     std::cin >> arr[i];
 
 //char
 char name[100];
 std::cin.getline(name, 100);
 
 nameの先頭アドレスを取得、name文字列を格納するための char配列の先頭アドレス
 100　最大読み取り文字数（終端文字 '\0' を含めて）つまり 99文字＋終端
 
 
 //string
 std::string name2;
 std::getline(std::cin, name2);
 
 std::cin：  入力元（ストリーム）
 name2： 入力先（std::string 変数）
 改行までcinを読み取って name2 に格納する
getline(入力、格納）の関係
 
*/

//#include <template>
#include <iostream>

template<size_t N>
void printArr(int (&ptr)[N])//配列のサイズ情報を保持したまま関数を配列に渡す
{
    std::cout <<"Number of index : "<< N<< std::endl ;
    for(size_t i =0; i <N; i++)
    {
        std::cout<<ptr[i] << std::endl;
    }
    
}

int main()
{
    int arr[3];
    for(int i =0; i <3; ++i)
    {
        std::cin >> arr[i];
    }
    
    std::cout<< "\n";
    printArr(arr);
    
    
 
    return 0;
}
