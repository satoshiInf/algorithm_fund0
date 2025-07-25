/*
 Binary Tree（二分木）
 * 左右に子ノードを持っても持たなくてもよい
 * 値の大小に規則なし
 * 構造が自由
 * BFS（幅優先探索）やDFS（深さ優先探索）などの「木の形全体を辿る探索」が必要
 
 binary treeは三つ抑える
 Binary treeとBFS
 Binary treeとDFS
 BTS
 
 もちろんです！`insert` 関数の中身をステップごとにわかりやすく説明しますね。


 Node* insert(Node* root, int value)
 {
     if (root == nullptr) {
         return new Node(value);
     }
     if (value < root->data) {
         root->left = insert(root->left, value);
     } else {
         root->right = insert(root->right, value);
     }
     return root;
 }
 
 ---

 ### 1. `if (root == nullptr)`
 * **意味:** 現在のノード（`root`）が存在しない（空）ならば、
   * 新しいノードを作ってそこに `value` を入れる。
   * つまり、ここが新しいノードを挿入する場所。
 * **動作:**
   * `new Node(value)` で新しいノードがヒープ上に作られ、
   * そのノードのポインタを返す。

 ---

 ### 2. `if (value < root->data)`

 * **意味:** 挿入したい値 (`value`) が、現在のノードの値 (`root->data`) より小さいか？

 * **動作:**

   * 小さいなら、**左の部分木**に挿入しに行く。
   * つまり、`root->left` を基点として再帰的に `insert` を呼び出す。

 * **ポイント:**

   * `root->left = insert(root->left, value);` としているのは、
   * 挿入後に更新された部分木の根（`root->left`）を正しく繋ぎ直すため。

 ---

 ### 3. `else`

 * **意味:** 挿入したい値が現在のノードの値以上（大きいか等しい）場合。

 * **動作:**

   * **右の部分木**に挿入しに行く。
   * `root->right = insert(root->right, value);` として右の部分木の更新を繋ぎ直す。

 ---

 ### 4. `return root;`

 * **意味:** 現在の部分木の根（`root`）を返す。

 * **役割:**

   * 再帰が戻るときに、部分木の正しい根を親ノードに返し、ツリーの構造を維持する。

 ---

 ## まとめ

 * 空の場所に来たら新しいノードを作る。
 * そうでなければ、値の大小で左か右の子ノードに挿入処理を再帰的に進める。
 * 挿入後は部分木の根を返すことで、親ノードが正しい子ノードを指すようにしている。

 このロジックにより、**二分探索木 (BST)** のルールを守って値を挿入できます。

 ---

 もしもっと細かくやコードの挙動を例で説明したり、図にしたりしたい場合も教えてください！

 
 空の場所に来たら新しいノードを作る。
 そうでなければ、値の大小で左か右の子ノードに挿入処理を再帰的に進める。
 挿入後は部分木の根を返すことで、親ノードが正しい子ノードを指すようにしている。
 このロジックにより、二分探索木 (BST) のルールを守って値を挿入できます。
 
 
 if (root == nullptr)
 意味: 現在のノード（root）が存在しない（空）ならば、
 新しいノードを作ってそこに value を入れる。
 つまり、ここが新しいノードを挿入する場所。
 new Node(value) で新しいノードがヒープ上に作られ、
 そのノードのポインタを返す。
 
 if (value < root->data)
 意味: 挿入したい値 (value) が、現在のノードの値 (root->data) より小さいか？
 小さいなら、左の部分木に挿入しに行く。
 つまり、root->left を基点として再帰的に insert を呼び出す。
 root->left = insert(root->left, value); としているのは、
 挿入後に更新された部分木の根（root->left）を正しく繋ぎ直すため。
 
 
 else
 意味: 挿入したい値が現在のノードの値以上（大きいか等しい）場合。
 右の部分木に挿入しに行く。
 root->right = insert(root->right, value); として右の部分木の更新を繋ぎ直す。
 
 return root;
 意味: 現在の部分木の根（root）を返す。
 再帰が戻るときに、部分木の正しい根を親ノードに返し、ツリーの構造を維持する。
 
 
 
 
 
 バイナリサーチツリー（BST）に値を追加する関数です。
 BSTのルールは：
 左の子は「親より小さい値」

 
 
 
 BFS
 */


#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value): data(value), left(nullptr),right(nullptr){};
    
};


//小さいは左、大きいは右
Node* insert(Node* root, int value)
{
    if(root == nullptr)
    {
        return new Node(value);
    }
    if(value < root-> data)
    {
        root-> left = insert(root->left, value);
    }
    else
    {
        root-> right = insert(root->right, value);
    }
    return root;//更新した場所をrootに代入する
    
}

void inorder(Node* root)
{
    if(root == nullptr) return;
    inorder(root->left);
    std::cout<< root-> data << std::endl;
    inorder(root->right);

}

int main()
{
    Node* root = nullptr;
    
    // 10-> 3 ->7 ->1 -> 4
    //
    root = insert(root, 5); //rootがNode*だから
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    insert(root, 4);
    
    
    inorder(root);
    std::cout<< std::endl;
    
    
    return 0;
}
