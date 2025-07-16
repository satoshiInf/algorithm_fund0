/*
 
 | テーマ         | 内容                               |
 | ----------- | -------------------------------- |
 | 配列の参照渡し     | `int (&arr)[5]` によりサイズ情報を保持      |
 | ポインタ渡し      | `int* arr` + `int size`：柔軟だが注意必要 |
 | vectorの渡し方  | `std::vector<int>&` で高機能かつ安全     |
 | 値渡し vs 参照渡し | 範囲for文での `int` と `int&` の違い      |
 | 安全性・可読性の比較  | STL(vector)、配列、ポインタの利点と欠点の整理     |
 
 次は
 テンプレート関数で任意サイズの配列にも対応させてみる
 2次元配列や構造体＋vectorの例に拡張する

 */
#include <iostream>
#include <vector>

/*
 (int (&arr)[5])
 */

void callingArr(int (&arr)[5])
{
    for(int i = 0; i < 5; i++)
    {
        arr[i] *= 2;
        std::cout << arr[i] << " ";
    }
    
}


void callingArrWithAddress(int* arr,int size)
{
    std::cout <<"\n"<<"Check New" << std::endl;
    for(int i =0; i < size; i++)
    {
        arr[i] *=2;
        std::cout << arr[i] << " ";
    }
}



void callingVecIndex(std::vector<int> &vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        vec[i] *= 2;
        std::cout << vec[i] << " ";
    }
}

// vectorをオブジェクトとして処理、vector全体を受け取る。先頭のアドレスではない！
void callingVecElement(std::vector<int> &vec)
{
    
    /*
     (int (&arr)[5])
     */
    //これはコピー
    
    std::cout <<"int element:vec"<<std::endl;
    for(int element:vec)
    {
        element *=2;
        std::cout << element << " ";
    }
    
    std::cout << "\n"<<"check"<<std::endl;;
    
    for(int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    

    std::cout << "\n"<<"again"<<std::endl;;
    std::cout << "\n"<<"int& element:vec"<<std::endl;;
    for(int& element:vec)
    {
        element *=2;
        std::cout << element << " ";
    }
    
    std::cout << "\n" <<"check"<<std::endl;;
    
    for(int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    
}



int main()
{
    int arr[5] ={1,2,3,4,5}; //void callingArr(int (&arr)[5])の５と一致している必要がある。
    /*int (&arr)[5] は「5個のintからなる配列の参照」という意味です。配列全体をそのままの形で受け取るので、サイズ情報も保たれます。
    //この関数は「正確に5個の要素を持つ配列」しか受け取れません。呼び出し元で int arr[5] である必要があり、
    void callingArr(int (&arr)[5])の５と一致している必要がある。
    （例えば [4] や [6] はNG）
     */
    callingArr(arr);
     
    // 配列の「先頭アドレス」だけが渡される
    callingArrWithAddress(arr,5);// ✅ 正常：5個分のデータを読む
    callingArrWithAddress(arr, 3);// ✅ 正常：先頭3個だけ読む
    
    
    std::cout <<"\n";
   
    std::vector<int>vec = {2,3,4};
    
    callingVecIndex(vec);
    
    std::cout <<"\n";
    
    callingVecElement(vec);
    
    std::cout <<"\n";
    
    return 0;
}
