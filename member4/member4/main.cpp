/*
継承は関数をそのまま使えるよ　の意味。
 
 
 
その次
関数を同名で上手いこと使いたい。
 ＝＞
この便利な環境　ポリモーフィズム：同じ関数名のものをクラスで独立して使えるようにする
 ＝＞ 参照かポインタでインスタンスの宣言をかく必要がある
 
 子クラスの関数として書いているのに親クラスの関数として動いてしまっている
 スライシング、静的バインディング：子クラスのインスタンスが親インスタンスとして扱われる問題

 ポリモーフィズム　＝　親型ポインタから子の動作を引き出す手続き。結果として子クラスで、親クラス関数のもので異なる挙動
 基本は参照かポインタでかく
 Parent* a =new Child();
 a->speak();　//静的バインディング
 このままだと　親クラスが呼び出される
 
 
 継承 → 「構造」をもらう（コードを使いまわせる）
 オーバーライド → 「振る舞い」を変える（同じ関数名でも意味を変える）
 ポリモーフィズム → 「親型ポインタから子の動作を引き出す」（virtual＋override）
 
 
 //動的バインディング
 virtualを書くと認識される関数の範囲が親クラスから親クラス＋子クラスに広がるので
 a->speak();　//動的バインディング
　子クラスが呼び出される
 
 オーバーライドを書く。子クラスで書く。継承
 オーバーライド　子クラスの関数のvoid speak（） override{}
 と書く。
 
 
 
クラス外の関数もメイン関数で使いたい
 ＝＞
フレンド関数
 
 
 
 
 
*/

#include <iostream>
#include <string>


class Animal
{
    protected:
    public:
    std::string name;
    
    void speak()
    {
        std::cout <<"I bark"<< std::endl;
    }
    
    /*
     friend addname をクラス内に書く
     addnameをクラス外で定義する　void
     メイン関数から呼び出す
     
     メイン関数におけるコードの関数の呼び出しで
     クラス外で定義された関数を使うことができる。
     */
    
    
    friend void addName(Animal& a);
};

void addName(Animal& a)
{
    std::cout << a.name <<"addname" << std::endl;
}



int main()
{
    //親クラスのインスタンスをそのまま
    Animal animal1;
    animal1.name ="This"; //publicだけアクセスできる
    animal1.speak();
    
    //クラス外の関数を使ってからAnimalクラスのものを使う
    
    addName(animal1);
    
    
    
    

    return 0;
}
