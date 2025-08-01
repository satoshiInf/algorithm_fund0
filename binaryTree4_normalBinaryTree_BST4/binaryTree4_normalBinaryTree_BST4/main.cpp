
/*

 !root とroot == nulptrは同じ意味ですか
 
 はい、`!root` と `root == nullptr` は **同じ意味** です。
 どちらも「`root` が `nullptr`（何も指していない）かどうか」を確認しています。

 ### 🔍 解説
 * `root` はポインタ型（例：`Node* root`）。
 * ポインタには「アドレス」または「nullptr」が入る。

 #### ✅ `root == nullptr`
 👉 「`root` が空（nullptr）か？」という比較。

 #### ✅ `!root`
 👉 「`root` が **false（= nullptr）** か？」という簡略表記。
 ポインタは `nullptr` だと `false`、有効なアドレスなら `true` になる。

 ### ✅ 例（両方とも同じ動作）

 if (root == nullptr)
 {
     std::cout << "空です" << std::endl;
 }

 if (!root)
 {
     std::cout << "これも空です" << std::endl;
 }

 ### 🔧 どちらを使うべき？

 | 書き方               | 読みやすさ     | よく使われる場面         |
 | ----------------- | --------- | ---------------- |
 | `root == nullptr` | 明示的で読みやすい | 初心者向けや可読性重視の場面   |
 | `!root`           | コンパクト     | 条件が多いとき、プロっぽい書き方 |

 ---

 
 
 ### 🧠 ポイント

 * `nullptr` → 「何も指していない」状態のポインタ
 * `!root` → 「`root` が空ですか？」と訊いている

 ---

 必要なら「逆の意味（有効なポインタか）」の書き方や、`if (root)` も説明できますよ。
 
 はい、まったくその通りです！あなたの理解は正確です。
 以下にもう少し丁寧に整理して説明しますね。

 ---
 Node* root = nullptr;
 int arr[] = {10, 5, 15, 3, 7};
 for (int val : arr) {
     root = insert(root, val);  // 1つずつBSTに挿入
 }
 ```

 ---

 ## 🧠 あなたの理解の確認：
 ### ✅ `root` は何？
 * `Node* root` は **BSTの先頭（根）ノードを指すポインタ**。
 * 最初は `nullptr`（まだ木が存在しない）。
 * 挿入が進むたびに `insert()` 関数が木を構築していく。
 ### ✅ `val` は何？
 * `arr` という整数配列から、`val` に順番に値が入る。
 * つまり `val` は `arr[0] → arr[1] → arr[2] ...` という順で値を取る。

 arr[] = {10, 5, 15, 3, 7}
 val = 10 → insert(root, 10) // root が nullptr → 新しくノード作る
 val = 5 → insert(root, 5)   // root が 10 → 5 < 10 → 左に入れる
 val = 15 → insert(root, 15) // 15 > 10 → 右に入れる
 
 ## 🧩 `insert()` 関数がどう働くか
 Node* insert(Node* root, int val)
 * `root` は「今見ているノード」を指す。
 * 再帰的に呼び出されていくことで、`val` を適切な場所に挿入していく。
 ## ✅ 図でイメージ
 配列 `{10, 5, 15, 3, 7}` を挿入していくと、以下のような木ができる：

 ```
         10
        /  \
      5     15
     / \
    3   7
 ```

 ---
 ## ✅ まとめ：あなたの理解

 > この `insert(root, val)` の `val` は `arr` の要素を順番に渡していて、
 > `root` は常にツリーのルートを保持しており、
 > 関数の中で再帰的に `val` を正しい場所に挿入している。
 完全に正解です。
 この流れが理解できていれば、BSTの構築はばっちりですよ。👍

 ---
 必要であれば、次のステップ（探索、削除、再帰の挙動の可視化など）も案内できます！

 あなたのコードとその理解、**完璧です！**
 以下の内容がしっかり押さえられており、BST（Binary Search Tree）と再帰の基本を正確に理解しています：

 ## ✅ 確認ポイントまとめ

 ### 1. `insert()` のロジック

 * `if (!root)` → 空ノードに来たら新しく作成（末端に到達したとき）
 * `val < root->data` → 左の子へ再帰
 * `val > root->data` → 右の子へ再帰
 * `return root` → 子の情報を親ノードが再び受け取る

 ✅ これは「**ポインタを通じてツリー全体を更新するための仕組み**」です。

 ---

 ### 2. `root = insert(root, val);`

 * `insert()` の返り値を **必ず `root` に代入**している
 * こうすることで、もし root が `nullptr`（最初のノード）なら新しく作られる
 * 再帰で下層の更新があっても、**親ノードが新しい構造をしっかり受け取る**

 ✅ これは「**木の構造が変わったとき、それを親まで正しく伝える再帰の基本形**」。

 ---

 ### 3. `displayInOrder()`

 * 左 → 自分 → 右 という順で表示
 * BST の性質上、**常に昇順に並ぶ**

 出力結果も：

 ```
 1
 2
 3
 4
 5
 ```

 ✅ BST + Inorder Traversal の正しい動作確認済み。

 ---

 ## 💡 あなたのコメントにも注目：

 ```cpp
 // rootにinsert(root, val)の戻り値を代入
 // treeの前述したrootとvalを保持した上で再度ループに回す
 ```

 これはまさに「再帰の帰り道で更新されたポインタを上書きしていく」挙動を表しています。
 **データ構造と再帰の理解が深まっている証拠**です。

 ---

 ## ✨ もし次に学ぶなら？

 * ✅ **探索（search）関数**
 * ✅ **最大・最小ノードの取得**
 * ✅ **削除操作（delete）** ← 少し難しいですが次のステップ
 * ✅ **DFS（深さ優先） vs BFS（幅優先）**
 * ✅ **木の高さの計算やバランス**

 ---

 何かピンとこないところがあれば遠慮なく聞いてください。
 ここまで来ていれば、もう **再帰と木構造の基礎はマスター寸前**です！

 
 
 
 */
#include <iostream>

struct Node
{
    
    int data;
    Node* left;
    Node* right;
    
    Node(int val): data(val),left(nullptr), right(nullptr){};
};

Node* insert(Node* root, int val)
{
    
    if(!root) return new Node(val);
    
    if(val < root->data)
    {
        root-> left = insert(root-> left, val);
    }
    else if(root->data < val )
    {
        root-> right = insert( root-> right, val);
    }
    else{};
    
    return root; //情報を引き継いで、再度この関数に入って更新していく
}

void displayInOrder(Node* root)
{
    if(!root)  return;
    displayInOrder(root->left);
    std::cout << root-> data << std::endl;
    displayInOrder(root->right);
}

int main()
{
    Node* root = nullptr;
    int arr[] = {4,2,1,3,5};
    
    for(int val: arr)
    {
        root = insert(root, val); //rootにinsert(root, val)の戻り値を代入
                                　//treeの前述したrootとvalを保持した上で再度ループに回す
    };
    
    displayInOrder(root);
 
    
    return 0;
}
