
#include <iostream>

/*
 class B : public A   // public継承
 class B : protected A  // protected継承
 class B : private A   // private継承
 
 クラスの再利用性を高める仕組みで、あるクラス（親クラス＝基底クラス）の機能を別のクラス（子クラス＝派生クラス）が引き継ぐこと。
 具体的には
 継承（Inheritance） は、
 親クラス（基底クラス）が持つ「メンバー関数（= メソッド）やメンバー変数（= フィールド）」などの機能や状態を、子クラス（派生クラス）が引き継ぐ（使えるようになる）仕組みのことを指します。
 */

class Parent
{
    public:
    void say()
    {
        std::cout <<"Shut your mouth" << std::endl;
    }
};

class Child :public Parent // Parentのpublicの関数と変数にアクセスを許可する
{
public:
    void sayexcuse()
    {
        std::cout <<"It is not my fault" << std::endl;
    }
    
};

int main()
{
    Parent strictP;
    std::cout <<"Parent class" << std::endl;
    strictP.say();
    
    
    Child spoiledC;
    std::cout <<"child class" << std::endl;
    spoiledC.say();
    spoiledC.sayexcuse();
    
    
    
    
    
    return 0;
}
