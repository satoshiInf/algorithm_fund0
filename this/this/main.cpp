//
//  main.cpp
//  this
//
//  Created by Satoshi on 7/17/25.
//

#include <iostream>

/*
 ざっくり
 int& func()
 {
 
 int& は型（参照型）の一部。型と＆はセットで参照

 
 
 
return x; // この時　func()= (int&)xと読む。
 (int&)x
 //「x はint型の参照 にキャスト（変換）されたもの（別名にしたもの）
 //元の変数の実体は変えずに、型だけ無理やり int の参照として扱う
 //xを変えたら参照先も全てが同様に置き換わる
 
 | 式         | 用途                     | 例                             |
 | --------- | ---------------------- | ----------------------------- |
 | `int& x`  | 参照変数の宣言                | `int a; int& x = a;`          |
 | `(int&)x` | 変数 `x` を int の参照型にキャスト | `double d; int& r = (int&)d;` |

 
 
 
 //
 intに変換した上で参照にしたもの
 double d = 3.14;   //d =3.14
 int x = (int)d;     // まず d を int に変換（値の変換）x=3
 int& r = x;         // x の参照を作る r=3

 
 
 }
 
 
 
 */

//戻り値を参照とする時
/*
 参照は変数の別名のようなものです。
 関数が参照を返すと、「実際の変数そのもの」を返していることになります。
 なので、返された参照を通して元の変数を変更することもできます。
 
 int x = 10;
 
 int& getRef()
 {
     return x;  // xの参照を返す
 }

 int main()
 {
     int& r = getRef();　 //r ≡ getRef()
     r = 20;   // これでxの値が20
     std::cout << x << std::endl;  // 20
 }
 
 
 
 int& r = getRef()　そして　getRef()→int xなので　int& r = getRef()　→xということ
 getRef() は x の参照（＝x の別名）を返す
 & r ＝ getRef() は
 だから int& r = getRef(); は r が x の別名になる という意味


 
 */

/*
 x =10;
 getRef() = (int&) x;
 int& r = getRef();
 
 
 
 */


int x = 10;

int& getRef()
{
    return x;  // xの参照を返す
    
    //int& getRef() =x?　誤り
    //int& x =　getRef() ?　正しい
    
    //リターンの結果はint& x 正しい
    //リターンの結果は(int&) x 誤り
}

int main()
{
    int& r = getRef(); //r ≡ getRef()　//＆r ＝getRef()
    r = 20; // これでxの値が20
    std::cout << x << std::endl;  // 20

    
    //int& r = getRef()
    //r =20;
    //int& x =　getRef()
    
    //x＝20;
    
    
    
    /*
    int a = 10;      // a は int 型の変数（整数の値を持つ）
    int& r = a;      // r は a の参照（別名）で、r も int 型の参照
    int& r と書くことで、「r は int 型の参照（int の別名）」であることを 明示的に示している。
    つまり、r は単なる変数ではなく、ある int 型変数であるa（この場合は a）を参照していることが型により分かる。
     
     int& は型（参照型）の一部。型と＆はセットで参照
     & は演算子（アドレスを取る）として使う。
    */
    
    return 0;
}
