//
/*
 
 【練習問題②】配列の平均を計算する関数（テンプレート）
 問題文：
 テンプレート関数 average を作成し、任意のサイズの double 配列を受け取って、**平均値（double）**を返す関数を作りなさい。
 
 
 
 

 配列はダブルってありなの？アイ列のインデックスの数がダブル？
**はい、ありです。**

 double arr[3] = {1.2, 3.4, 5.6};  // double型の配列
 この `arr` は「double型の要素を3つ持つ配列」であり、全く問題なく使えます。

 ---

 ## 🔶 Q2: 「インデックスの数が double」ってあり得るの？
 → **いいえ、それはできません。配列のサイズ（インデックスの範囲）は整数でなければなりません。**
 配列のサイズ（要素数）は `int` や `size_t` のような **整数型**でなければいけません。
 ### ❌ NGな例（これはコンパイルエラー）:
 double n = 3.5;
 double arr[n];  // ← エラー！配列サイズは整数でないとダメ
 ```

 ---

 ## ✅ インデックスとは何か（復習）

 配列のインデックスとは、**0 から始まる整数番号**です。

 ```cpp
 double arr[3] = {1.0, 2.0, 3.0};

 std::cout << arr[0]; // 1.0
 std::cout << arr[2]; // 3.0
 ```

 この `[0]`, `[1]`, `[2]` が **インデックス**です。
 `arr[1.5]` のような書き方は **存在しません（エラー）**。

 ---

 ## 🧠 結論まとめ

 | 内容                        | OK / NG | 備考                     |
 | ------------------------- | ------- | ---------------------- |
 | `double arr[5]`           | ✅ OK    | 要素が `double` 型の配列      |
 | `arr[2]`（整数インデックス）        | ✅ OK    | 正しいインデックスの使い方          |
 | `arr[1.5]`（小数）            | ❌ NG    | インデックスに `double` は使えない |
 | `double n = 5.0; arr[n];` | ❌ NG    | 配列サイズ・インデックスには整数が必要    |

 ---

 */

#include <iostream>

template<size_t N>
double averageArr(double (&p)[N])
{
    double total =0;
    for(size_t i =0; i < N; i++)
    {
        total += p[i];
    };
    
    double average = total/N;
    
    return average;
}

int main()
{
    double arr[3] = {1,2,3};
    double average = averageArr(arr);
    std::cout <<average << std::endl;
   
    return 0;
}
