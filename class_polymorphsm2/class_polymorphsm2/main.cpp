/*
 ポリモーフィズムとは何だ？
 
 親クラスで定義した関数を、子クラスの同名の関数で独自の関数とさせること
 or同名でも異なる型を使ったら独自の関数とさせること
 
 ポリモーフィズムに必要な3点セット
 1. class 子クラス:public parent　で親の箱とこの箱を繋げる
 2. Parent *p＝&c で親子間で親から子へのカーソルを作る
 3. 親クラスにvirtual、子クラスにoverrideでfunc()が子クラスにアクセスできるようにする
 
 
 
1)
スタックでの書き方
Child c;
Parent p =c //コピーしているだけなのでだめ、Parent pがChild cにアクセスできない
Parent*p =c .. p->func()
Parent&p =c .. p.func()
で呼び出す。静的バインディング。func（）が子クラスにアクセスできない。
 
2)
virtualを親クラスに書く
overrideを子クラスに書く
func()が子クラスにアクセスできるようになる
 

 1)
 ここまでスタック　＜ー＞　ヒープでの確保の書き方　→smart pointerだけ抑える
 std::unique_ptr<Parent> p = std::make_unique<Child>();
 p->func();
 
 
 
 
 
 
 */


#include <iostream>
#include <string>

class Parent
{
    public:
    virtual std::string func()
    {
        return "Parent";
    }
};

class Child : public Parent //: public Parent
{
    public:
    std::string func() override
    {
        return "child";
    }
};

int main()
{
    Child c;
    Parent*ptr = &c;
    
    std::cout<<  ptr->func();
    
    Child c2;
    Parent&ref = c2;
    std::cout<< ref.func();
   
    return 0;
}
