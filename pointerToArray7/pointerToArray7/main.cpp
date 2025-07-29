/*
 | 表現     | 意味                          | ポインタの型例                       | 呼び出し例         |
 | ------ | --------------------------- | ----------------------------- | ------------- |
 | `arr`  | 配列の「先頭要素」のアドレス（個別の最初の要素を指す） | `int*` （int配列の先頭要素へのポインタ）     | `func(arr);`  |
 | `&arr` | 配列「全体」のアドレス（配列全体をまとめて指す）    | `int (*)[N]` （N個のint配列へのポインタ） | `func(&arr);` |

 仮引数がarrはアドレスの先頭
 
 仮引数が&arrは配列全体のアドレス　int (*p)[]と書いたら(*p)のまま使用する
 (*p)[i]は値で、 &(*p)[i] とすれば、その要素のアドレスになる
 
 
 
*/

#include <iostream>

/*
template <size_t N>
void printArr(int (&arr) [N])
{
    std::cout <<"Number of Index :" << N << std::endl;
    for(size_t i = 0; i < N ; i++)
    {
        std::cout <<arr[i] << std::endl;
    }
}
 */
/*
template <size_t N>
void printArr(int (&arr)[N]) //N個のintの配列全体への参照
{
    std::cout << "Number of Index :" << N << std::endl;
    
    for(size_t i = 0; i < N ; i++)
    {
        std::cout<< arr[i] << std::endl;
    }
}
 */


void printArr1(int* p, int size)
{
    for(int i =0 ; i < size; i++)
    {
        
        std::cout <<p[i] << std::endl;//　なぜなら*(p+i) ≡ p[i]
    }
    
}

void printArr2(int (*p)[], int size)
{
    for(int i =0 ; i < size; i++)
    {
        
        std::cout << (*p)[i] << std::endl; //(*p)[i]は値で、 &(*p)[i] とすれば、その要素のアドレスになる。（*p)[i] ≡ *（（*p）＋i)
    }
    
}


int main()
{
    int arr[3]  = {1,2,3};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    printArr1(arr,size);
    
    printArr2(&arr,size);


    
    
    
    
    return 0;
}
