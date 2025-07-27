//
//
/*
 
 配列を使った関数の扱いを今一度チェック
 
 arr は int[5] だけど、関数に渡すとき…
 C++では、配列は関数に渡すときに自動的にポインタに変換されます（デカイ）：
 arr → &arr[0] → int*
 この変換のことを「配列からポインタへの暗黙変換（decay）」といいます。
 

 void func(int* p)          ポインタ（arr など）
 void func(int arr[])       同上（int*と同じ）
 void func(int (&arr)[5])   5個のintからなる配列の参照
 void func(int (*p)[5])     配列全体へのポインタ
 
 
 
 関数の引数に int arr[] と書いても、それは**「ポインタ」への退化（decay）**が起きて int* になります。
 つまり、関数内ではサイズ情報が失われます！
 void func(int arr[])  // 実際は → void func(int* arr)
 void func(int* arr)   // 同じ意味
 
 
 | 関数名             | 引数の型                                                    | 特徴                    | サイズ情報       |
 | --------------- | ------------------------------------------------------- | --------------------- | ----------- |
 | `printArr`      | `int (*p)[5]`                                           | 配列全体への**ポインタ**        | 〇（保持）       |
 | `printArr2`     | `int* p`                                                | 配列 → ポインタに**退化**      | ✕（失う）       |
 | `printArr3`     | `int (&arr)[5]`                                         | 配列への**参照**（正確な型）      | 〇（保持）       |
 | `printArr4`     | `int arr[], int size`                                   | 通常のC風書き方（要サイズ明示）      | ✕（明示必要）     |
 | **`printArr5`** | **`template <size_t N> void printArr5(int (&arr)[N])`** | **テンプレートで配列サイズを自動取得** | **〇（自動取得）** |

 */


#include <iostream>

void printArr(int (*p)[5])
{
    for(int i = 0; i< 5; i++ )
    std::cout << (*p)[i] << std::endl;
}

void printArr2(int* p)
{
    for(int i = 0; i< 5; i++ )
    {
        
        //std::cout << *p << std::endl;
        //p[i] ≡ *(p + i)
        std::cout << p[i] << std::endl;
        std::cout << *(p+i)<< std::endl;
    }
}

void printArr3(int (&arr)[5])
{
    for(int i = 0; i< 5; i++ )
    {
        
        //std::cout << *p << std::endl;
        //p[i] ≡ *(p + i)
        
        std::cout << arr[i] << std::endl;
    }
    
}

void printArr4( int arr[], int size)
{
    for(int i = 0; i< size; i++ )
    {
        std::cout <<""<< std::endl;
    }
    
}


//インデックス数を管理して動かす
template <size_t N>
void printArr5(int (&arr)[N])
{
    std::cout << "size = " << N << std::endl;
    for (size_t i = 0; i < N; ++i)
    std::cout << arr[i] << std::endl;
}



int main()
{
    int arr[5]  = {1,2,3,4,5};
    //配列そのものにアクセスすることを意図するとする
    // arrや＆arr[0]は誤り
    
    // int(*p)[5]　= &arr;
    printArr(&arr);
    
    // int* に変換される int* p = arr;
    printArr2(arr);
    
    
    /*
    arr[0] をそのまま仮引数に使うことはない
    なぜなら arr[0] は「単なる int 値（配列の1要素）」だからです。
    */
    
    printArr3(arr);
    
    
    printArr4(arr, 5);
    
    
    printArr5(arr);
    
    
    
    return 0;
}
