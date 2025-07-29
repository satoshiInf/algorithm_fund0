/*
 ✅【練習問題③】最大値を返す汎用関数（int, float など）
 問題文：
 テンプレート関数 findMax を作成し、あらゆる型の配列（int, double, float など）から最大値を返すようにしなさい。
 例：
 int a[] = {4, 8, 2};
 double d[] = {1.5, 9.9, 4.4};

 findMax(a) → 8
 findMax(d) → 9.9
 
 応用課題
 // T型の任意の数値型に対応できるようにテンプレートを改造せよ
 template <typename T, size_t N>
 double averageArr(const T (&arr)[N]);

*/

#include <iostream>

template <typename T, size_t N>
T findMax(const T (&p)[N])
{
    T maxValue = p[0];
    for(int i = 0; i <N ; i++)
    {
        if(maxValue < p[i])
            maxValue = p[i];
    }
    
    //std::cout << maxValue <<std:: endl;
    
    return maxValue;
}


int main()
{
    
    int a[3] = {4, 8, 2};
    double d[3] = {1.5, 9.9, 4.4};
    
    std::cout<<findMax(a) << std::endl;
    std::cout<<findMax(d) << std::endl;
   
    
    
    return 0;
}
