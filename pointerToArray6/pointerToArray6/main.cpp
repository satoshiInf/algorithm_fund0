
/*
 
 (*p）は配列全体へのポインター：（）で配列のうちの、、、
 (*p)[5]　配列のpの５番目の値を取得
 
 *pは配列のうちの各要素を指し示すポインター
 p[i]か*(p+i)で取得する
 
 
 
 1. (*p)[i] のイメージ
 
 int arr[5] = {10,20,30,40,50};
 int (*p)[5] = &arr;

 p ──► ┌─────────────┐
         │ arr (配列5個)│
         │ +---+---+---+---+---+
         │ |10|20|30|40|50|
         │ +---+---+---+---+---+
         └─────────────┘

 (*p)[i] は p が指す配列の i 番目の要素を示す

 例： (*p)[2] = 30

 p は「配列全体へのポインタ」
 (*p) で配列自体にアクセスし、その [i] で要素を読む
 
 
 
 2. *p[i] のイメージ
 
 int a = 1, b = 2, c = 3;
 int* p[3] = {&a, &b, &c};

 p (配列) ──► ┌─────┬─────┬─────┐
            　│ &a  │ &b  │ &c  │
            　└─────┴─────┴─────┘

 *p[i] は p[i] が指すアドレスの値を示す

 例： *p[1] = b の値 = 2

 
 p は「ポインタの配列」（各要素がポインタ）
 p[i] は i 番目のポインタ（例えば &b）
 *p[i] はそのポインタが指す値（b の値 2）
 
 
 
 
 */




#include <iostream>


void printArr1(int* p,int size)
{
    for(int i = 0; i< size; i++ )
        {
            //pはint＊へのポインター、＊pはint型の値
            
            std::cout << p[i] <<std::endl;// (*p)[i]
            std::cout << *(p+i) <<std::endl;
            //std::cout << (*p)[i] <<std::endl; 誤り
            
            // pの型はint*であり、*p[i] は「p[i] がポインタである」場合に使う記法
        }
    
}

/*
 
 (*p)[i]    p が 配列へのポインタ のとき    p の型：int (*)[N] など
 *p[i]    p が ポインタの配列 のとき    p の型：int*[] や int**
 
 
 | 書き方     | 意味                                    |
 | ------- | ------------------------------------- |
 | `p[i]`  | `*(p + i)` → 値を読む                     |
 | `*p[i]` | `*(p[i])` → 「ポインタの配列」のときの使い方。今回とは無関係。 |
 
 今回のコードで *p[i] がダメな理由
 今回の p はこうでした：

 void printArr1(int* p, int size)
 p は int* です（int 型の値を指すポインタ）。
 なので p[i] は *(p + i) と同じく int 型の値。
 つまり p[i] は すでに値 であって、ポインタではない！
 → だから *p[i] は：

 *p[i] ≡ *(p[i]) → *(int) → ❌ 誤り
 整数を * で参照しようとしているので、文法的に誤りです。
 
 */

void printArr2(int (*p)[], int size)
{
    for(int i = 0; i< size; i++ )
        {
            std::cout << (*p)[i]<< std::endl;
        }
    
}

void printArr3()
{
    
    
}



int main()
{
    int arr[3] = {1,2,3};
    
    int sizeOfArr = sizeof(arr)/sizeof(arr[0]);
    
    std::cout<<"Numbers of Index: " <<sizeOfArr << std::endl;
    std::cout<<"\n" << std::endl;
    
    printArr1(arr,sizeOfArr); //decayでint* arrになる
    
    printArr2(&arr,sizeOfArr);
    
    printArr3();
    
    
    return 0;
}


