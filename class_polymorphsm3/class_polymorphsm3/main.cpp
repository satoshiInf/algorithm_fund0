/*
 
ポリモーフィズムの前提　3点セットが終わったあと
 
１.純粋仮想
C++において関数宣言の最後に = 0 を書く意味はとても特別で、それは「純粋仮想関数（pure virtual function）」を意味します。
この = 0 があることで、クラスが抽象クラスになります。＝親クラスは実在しない＝親クラスのインスタンスが作れない
 
 Parent p;は不可になる
 
 Child c;
 Parent＆　p = c;
 
 もしくは
 
 Child c;
 Parent*　p = &c;
とかくことはできる。

 
 
 
 
 2.
 コンストラクタ
 クラス名　インスタンス名で呼び出し。インスタンスの初期化
 
 
 
 */


#include <iostream>
#include <string>

class Parent
{
    public:
    std::string name;
    
//1)
    Parent(std::string n): name(n)
    {
        std::cout<< n << std::endl;
    }
    
//2)
    //デフォルト設定。
    //クラス名（）:ナンバー変数（セットする値）
    //Parent() : name("NO NAME") はParent()が呼ばれた時：以下をセットする
    Parent(): name("NO NAME")
    {
        std::cout<< name << std::endl;
    }
    
    
    
    /* これと同じ
    Parent()
    {
        name = "NO NAME";
     std::cout<< name << std::endl;
    }
     */
 
};

/*
class Child: public Parent
{
    
    
};
*/

 
int main()
{
    
    Parent p0("EVIAN");
    //std::cout << p0.name;
    Parent p1;
    //std::cout << p1.name;
    Parent p2;
    
    

    return 0;
}
