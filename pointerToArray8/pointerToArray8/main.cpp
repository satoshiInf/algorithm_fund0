/*
 int (*p)[5] 型の配列全体へのポインタを受け取る関数 printArray を作成し、配列の全要素を出力しなさい。
 main 関数内で、長さ5の整数配列を作り、printArray に配列のアドレスを渡して呼び出しなさい。
 
 
 C++の型システムでは、配列のサイズも型の一部とみなします。
 つまり、int (*)[5] とint (*)[]
はまったく異なる型として扱われます。

 
 
 */

#include <iostream>

//int (*p)[ー]ではサイズを明示しないといけない -> テンプレートを使う
void printArray(int (*p)[5],int size)//int (*p)[]は誤り -> このことからテンプレートを使う必要性ある。マジックナンバー
{
    for(int i =0 ; i < size; i++)
    {
        //std::cout<< *((*p)+i) <<std::endl;
        std::cout<< (*p)[i] <<std::endl;
    }
}

/*
void printArr(int* ptr, int size)
{
    
}
 */

//template <size_t N>




int main()
{
    int arr[5] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    //配列全体の参照の時,引数のint (*p)[]　の(*p)以外の箇所が型である。
    //仮引数が&arrの時だけ、arrは違う
    //よってint (*p)[]とint (*p)[5]は別物である。
    //配列はサイズを明示しなければならない。　int arr[5];
    //int (*p1)[5] = &arr;  // OK（サイズが5で一致）
    //int (*p2)[] = &arr;   // エラー（サイズ不明の配列ポインタにサイズ5の配列を渡そうとしている）

    
    printArray(&arr,size); //配列のアドレスを渡す
    
    //printArr(arr,size); //
    
    
    return 0;
}
