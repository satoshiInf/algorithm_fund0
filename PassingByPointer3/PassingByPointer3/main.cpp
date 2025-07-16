//やり直す

/*
 配列 arr の要素をすべて2倍にする関数 doubleArray をポインタ渡しで作り、main で呼び出して結果を表示してください。
 
 +++++++++++++++++++++++++++++++++++++++++
 pointer 配列indexの　i番目のアドレスを二つ書け
 
 index+i            （index+i)と読む
 &(index[i]) ：値のアドレス
 +++++++++++++++++++++++++++++++++++++++++
 pointer 配列indexの　i番目の要素を二つ書け
 
 index[i] :決まりごと
 *(index+i)         上のアドレスの指し示す値
 +++++++++++++++++++++++++++++++++++++++++
 
 
 pointer indexの要素の”値”は
 index[i] or *(index+i)と書く
 
 pointer indexの要素のアドレスは&(index[i]) or index+i
 &(index[i]) == index + i ← ✅ 正しい（意味：i番目の要素のアドレス）
 &(要素の値)なのでアドレス
 index + i = (”index” + i)：インデックスのアドレスをi個先のアドレス
 
 index[i]が値であることを考える
 
 &(index + i)               ← ❌ 不正確・間違い（型エラーの原因にもなる）
 
 */




/*
ポイント
index[i] は「ポインタ index が指す i 番目の要素の”値”」
*= 2 は「その値を2倍する」
つまり：「アドレスを2倍」ではない！
ポインタ[i]->
 

 index[i] *= 2;
 本質的にはこうなっている：
 
 
 index[i]  ≡  *(index + i)と覚える
 index[i] *= 2;
 *(index + i) *= 2;
 
 | 式                    | 意味                      |
 | -------------------- | ----------------------- |
 | `index[i] *= 2;`     | indexのi番目の **値**を2倍する   |
 | `*(index + i) *= 2;` | 上とまったく同じ意味              |
 | `index += 2;`        | ポインタ（アドレス）自体を2つ先に進める    |
 | `&index[i]`          | i番目の **アドレスを取得**する      |
 | `*index`             | 現在のポインタが指している **値** を参照 |

 */

#include <iostream>

void DoubleArr(int *index,int size)
{
    //indexがアドレス
    //*（index）が値のはず
    
    for(int i = 0; i <size; i++)
    {
        //index[i] *= 2;// index[i] *=2;
        *(index +i) *=2;
    }
    
}

int main()
{
    int arr[5] ={1,2,3,4,5};
    
    for(int i = 0; i < 5; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    
    std::cout << "\n" << std::endl;
    // cout
    
    DoubleArr(arr,5);
    
    for(int i = 0; i < 5; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    
    
    
    
    return 0;
}
