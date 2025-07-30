//
/*
 了解です！
 「ノーマルなバイナリーツリーのメモリ解放を含む基礎問題」を作りますね。

 ## 【問題】バイナリーツリーの構築とメモリ解放

 ### 問題文
 以下の条件を満たすプログラムを作成しなさい。
 1. ノードの構造体 `Node` を定義し、コンストラクタで `data` と左右の子ポインタ（初期は `nullptr`）をセットすること。
 2. 手動で下記のバイナリーツリーを構築すること。

 ```
        10
       /  \
      5    15
     / \     \
    3   7     20
 ```

 3. **中間順（inorder）探索**でノードの値を出力する関数 `inorder(Node* root)` を作成すること。
 4. **再帰的に木のすべてのノードをメモリ解放する関数** `deleteTree(Node* root)` を作成すること。
 5. `main` 関数内でツリーを作り、`inorder` で値を表示し、最後に `deleteTree` でメモリを解放すること。

 ---

 ### 【期待される出力】

 ```
 3 5 7 10 15 20
 ```

 ---

 ### 【ヒント】

 * `inorder` は左、親、右の順にノードを表示する再帰関数です。
 * `deleteTree` は左、右の子を先に削除してから親を `delete` する再帰関数です。

 */


#include <iostream>

struct Node
{
    /*
     
     left は「住所（メモリアドレス）」を保存する箱
     *left は「その住所にあるモノ（実体）」を指す
     left->data は (*left).data の短縮形（「ポインタが指すモノのメンバにアクセス」）
     
     ポインターの初期化は
     left ＝nullptrとかく　leftはアドレスを持たない　＝何も指していない
     *left = nullptr は何もさしていない場所の中身を代入しようとしているので危険、誤り
     left = nullptr;は
     「ポインタ変数 left に 何も指していない状態（空のアドレス） を代入する」という意味です。
     left 自体はアドレス（メモリ上の位置）を格納する変数なので、
     「left はアドレスを持つ変数」です。
     だから、left = nullptr; は「leftがアドレスを持っていない（どこも指していない）」ことを表します。
     
     
     ポイント
     left(nullptr)は　ポインタであるleftがアドレスを持っていない＝（どこも指していない）
     */
    
    int data;
    Node* left;
    Node* right;
    
    Node(int val): data(val), left(nullptr),right(nullptr){};
    /*
     Node(int val) : data(val), left(nullptr), right(nullptr) {}
     ここで left(nullptr) と書くのは、
     「このノードの左の子はまだ存在しません（何も指していません）」 と意味する
     つまり、left が**「どこも指していない」状態（nullptr）**で初期化される
     指し示すものがnullptrではなくて、指し示すアドレスがないということ
     */
};

void inorder(Node* root)
{
    if (root== nullptr) return;
        inorder(root->left);
    std::cout<< root-> data << std::endl;
        inorder(root->right);
}

void deleteTree(Node* root)
{
    if(root == nullptr) return;
    deleteTree( root->right);
    deleteTree( root->left);
    delete root;
}

/*
 DFS：中間順（Inorder）探索の例
 inorder
 左部分木 → 現在のノード → 右部分木
 木の構造：

       10
      /  \
     5    15
    / \
   3   7
 nullになるまで下に行く　左から親　親から右
 この時、inorder(root); を呼ぶとこう動きます：
 左の子（5）に行く
 さらに左の子（3）に行く
 left=nullptr なので return → 3 を出力
 親（5）を出力
 右の子（7）に行く → 7 を出力
 親（10）に戻って出力
 右の子（15）に行って出力
 出力結果は：3 5 7 10 15

 */

int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root -> left-> right = new Node(7);
    root -> left-> left = new Node(3);
    root -> right-> right = new Node(20);
    
    inorder(root);
    
    deleteTree(root);
    
    
    return 0;
}
