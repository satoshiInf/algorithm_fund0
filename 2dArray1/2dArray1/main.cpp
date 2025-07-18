/*
 配列の基本
 配列の一番後ろの[]は一番内部の{}を指す
 charは””で文字列を格納するから""が一つの{}に該当する
 ""が一位番最後の配列に該当する。char c[][ここ]=
 
 
 
 char *p[]がそれぞれのリテラルの先頭のアドレスを指すと考えれば良い
 char *p[] = {"ABC","DEF","GHI}であれば
 A,D,Gのアドレスをポインタで定義している。
 
 
 
 char *p[] = {"Super", "X", "TRY"};

 p
 ↓
 +-----+     +--------+
 | p[0] | -->| "Super" |
 +-----+     +--------+
 | p[1] | -->| "X"     |
 +-----+     +--------+
 | p[2] | -->| "TRY"   |
 +-----+     +--------+

 
 
 */

#include <iostream>
#include <stdio.h>

int main()

{
    //内部にあるのは””の中、つまり
    char oneWord[10] ={"ONEWORD"};
    char a[][10] = { "Char","String"};
    char *p[] = {"ABC","DEF","GHI"};
    
    /*
     char *p[][] = {"ABC","DEF","GHI"}と書くべきではないのか
     char *p[]とすると
     ポインタの*p[0]は値　p[0]はアドレスを指す
     char p[] ={'A','B','C'};
     char p[]　＝{"ABC"};
     char p[][] = {"ABC","DEF","GHI"};
     と書いたはず。
     
     とすれば　char *p[] = {"ABC","DEF","GHI};って書くのはおかしい
     と感じる。
     
     ポインタの配列を見たら
     char *p[]がそれぞれのリテラルの先頭のアドレスを指すと考えれば良い
     char *p[] = {"ABC","DEF","GHI}であれば
     それぞれの要素の先頭の文字だけとる。
     A,D,Gのアドレスをポインタで定義している。
     
     char *menu[2][3] =
     {
         {"Sushi", "Ramen", "Tempura"},
         {"Burger", "Fries", "Soda"}
     };
     
     menu[0][0] → "Sushi"
     menu[0][1] → "Ramen"
     menu[0][2] → "Tempura"
     menu[1][0] → "Burger"
     menu[1][1] → "Fries"
     menu[1][2] → "Soda"
     型* array[]の形の時は、char*であってもstring＊、int＊も全く同じ構造になる
     
     int a[3] = {10, 20, 30};
     int *p = a;       // a は先頭アドレス → int*
     int (*q)[3] = &a; // q は a全体のポインタ → int (*)[3]

     char c[6] = "Hello";
     char *p = c;         // c は先頭アドレス → char*
     char (*q)[6] = &c;   // q は c全体のポインタ → char (*)[6]


     string s[3] = {"A", "B", "C"};
     string *p = s;          // s は string* 型
     string (*q)[3] = &s;    // q は string[3] へのポインタ

     
     
     */
    
   
    
    
    return 0;
}
