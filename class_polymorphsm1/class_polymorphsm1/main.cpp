/*
継承は関数をそのまま使えるよ　の意味。
その次
関数を同名で上手いこと使いたい。
 ＝＞
この便利な環境　ポリモーフィズム：同じ関数名のものをクラスで独立して使えるようにする
 
 ＝＞ 参照かポインタでインスタンスの宣言をかく必要がある
 子クラスの関数として書いているのに親クラスの関数として動いてしまっている
 スライシング、静的バインディング：子クラスのインスタンスが親インスタンスとして扱われる問題
 
 スライシング :ポリモーフィズム手続きミス
 静的バインディング:virtualを書いていない
 
 ポリモーフィズム　＝　親型ポインタから子の動作を引き出す手続き。結果として子クラスで、親クラス関数のもので異なる挙動
 基本は参照かポインタでかく
 1)インスタンス生成時のポリモーフィズムの手続き
 2)virtualを書く
 3)子クラスにoverrideを記載する。安全装置として
 
 
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
 
 親子クラスではなく、クラス外の関数に対する取り扱い
 別論点
クラス外の関数もメイン関数で使いたい
 ＝＞
フレンド関数
 
 
 【コード例】
 class Parent
 {
 public:
     virtual void speak() { std::cout << "Parent speaking\n"; }
 };

 class Child : public Parent {
 public:
     void speak() override { std::cout << "Child speaking\n"; }
 };

 int main() {
     Parent* a = new Child();　//子クラスのインスタンスの話ではなく関係性を作っているコード
 
     a->speak(); // → "Child speaking"（動的バインディング）
 }

 【補足：バインディングの違い】
 ・静的バインディング：
     - コンパイル時に関数が確定（`virtual` がない場合）
     - `Parent* a = new Child();` → `a->speak()` で親クラスの関数が呼ばれる
 ・動的バインディング：
     - 実行時に関数が確定（`virtual` がある）
     - 子クラスの関数が呼ばれる

 【注意点】
 ・スライシング：値渡しにより子クラスの情報が親クラスに切り詰められる現象
     → 参照またはポインタを使うことで回避

 【番外：クラス外の関数を使いたいとき】
 ・友達（friend）関数を使う
 ・クラスのprivateメンバーにもアクセスできる
 

*/


//手続きの書き方

//親クラスでバーチャル　子クラスでオーバーライド

//virtual void speak()
//void speak() override

#include <iostream>

class Parent {
public:
    virtual void speak()
    {
        std::cout << "Parent speaking\n";
    }
};

class Child : public Parent {
public:
    void speak() override
    {
        std::cout << "Child speaking\n";
    }
};

int main() {
    //採用
    //ポインター型
    std::cout << "=== スタック変数（Parent* a = &c;） ===\n";
    Child c;                 // スタック上に子クラスのオブジェクトを作成
    Parent* a1 = &c;         // 親クラス型ポインタで参照（関係性を作る）
    a1->speak();             // → Child speaking

    //不採用 メモリリーク対策
    std::cout << "\n=== ヒープ変数（Parent* a = new Child();） ===\n";
    Parent* a2 = new Child(); // ヒープに子クラスのオブジェクトを生成し、親クラス型ポインタで受け取る
    a2->speak();              // → Child speaking

    delete a2; // ヒープメモリを解放（忘れるとメモリリーク）
    return 0;
    
    /*
     Child c;
     Parent* ptr = &c;
     ptr->speak();
     */
}




// 参照型
    /*
    std::cout << "=== 参照を使う（Parent& a = c;） ===\n";
    Child c;                // スタックに子クラスのオブジェクト
    Parent& a = c;          // 親クラス型の参照で子を扱う（関係性を作る）
    a.speak();              // → Child speaking（ポリモーフィズム）
    }
    */


//Child c; 子クラスでインスタンスを書く
//Parent* p = &c； pointerがcのアドレスを指し示すようにする
//p->speak()で取り出す


/*
 
 | 比較ポイント      | `&c` 形式                    | `new Child()` 形式           |
 | ----------- | -------------------------- | -------------------------- |
 | オブジェクトの生成場所 | スタック                       | ヒープ                        |
 | 寿命          | `main()`終了時に自動で破棄          | `delete` しないと破棄されずメモリリーク   |
 | 柔軟性         | 固定的（関数内スコープのみ）             | 動的（他関数に渡したり、寿命を延ばせる）       |
 | 実行結果        | `Child speaking`（ポリモーフィズム） | `Child speaking`（ポリモーフィズム） |
 
 
 deleteを書き忘れるだろうからスタックだけ使う
 特に学習中やバグを減らしたい場合、スタックだけ使う（＝new を使わない）という方針は安全性・可読性の両面で優れています。
 
 

//ポリモーフィズムの管理：親クラスから子クラスを紐づける(& or *)　＋　動的binding
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
 
 
 ＋＋＋＋＋＋＋＋＋＋
 1)
 ここまでスタック　＜ー＞　ヒープでの確保の書き方　→smart pointerだけ抑える
 std::unique_ptr<Parent> p = std::make_unique<Child>();
 p->func();
 
 
 
 
 
 
 */
