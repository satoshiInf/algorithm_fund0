
/*
 if(!root) return; は、再帰関数の基本的な「終了条件（ベースケース）」です。
 詳しく説明すると：
 root は Node* 型のポインタで、今処理しているノードを指しています。
 !root は、root == nullptr と同じ意味で、「ノードが存在しない（空）」ことを示します。
 つまり、
 if (!root) return;は
 「もしノードが存在しなければ、これ以上処理を続けずに関数から抜ける」
 再帰的に木を辿るときに、末端の子ノード（空の子）に来たら処理をやめる役割を果たします。
 */


#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;
    
    Node(int val): data(val), left(nullptr),right(nullptr){};
};

Node* insert(Node* root,int val) //要素を動かす、一段につき一回回す、再帰関数で下に潜っていく
{
    if(!root) return new Node(val); //最初の1回だけ呼ばれる（もしくは、挿入したい場所＝空の部分を見つけた時だけ呼ばれる）

    if(val < root-> data)
    {
        root-> left = insert( root-> left ,val);//下へ
    }
    else if (val > root-> data)
    {
        root-> right = insert( root-> right ,val);//下へ
    }
    return root; //rootをそのまま引き継いで、関数を更新
}

void displayByPostOrder(Node* root)
{
    if(!root) return; //ノードが空なら、何もしないで終了
    displayByPostOrder(root-> left);
    displayByPostOrder(root-> right);
    std::cout << root-> data;
}

int main()
{
    Node* root = nullptr;
    int arr[] = {1,9,2,8,3,7,4,5};
   
    for(int val: arr)//ここで終了点ができている
    {
        //　各々の要素の走査で一回
        root = insert(root, val);
    }
    displayByPostOrder(root);
    
    return 0;
}

/*
 
 今の木に対して、例えばこういうBSTがあったとします。


       5
      / \
     3   10
 この状態から 8 を入れたいとしましょう。
 insert(root, 8) の呼び出しの流れ
 最初の呼び出し
 引数は root がノード5を指している状態

 val = 8
 if (!root) return new Node(val);  // rootは5だからスルー
 if (8 < 5)  // false
 else if (8 > 5) // true
     root->right = insert(root->right, 8);
 return root;
 つまり、右側の子ノード（10）へ次の再帰呼び出し。

 2回目の呼び出し
 val = 8
 if (!root) return new Node(val);  // rootは10だからスルー
 if (8 < 10)  // true
     root->left = insert(root->left, 8);
 else if (8 > 10)  // false
 return root;
 左の子ノードに次の再帰呼び出し。

 3回目の呼び出し
 引数は root がノードnullptr（10の左子が空）
 val = 8
 if (!root) return new Node(8);  // true、ここで新ノード作成して返す
 新しいノード8を作って返す。
 戻りながら代入される

 3回目の呼び出しから戻って、2回目の呼び出しの root->left = insert(...) の部分に
 新ノードのアドレスがセットされる。
 2回目は return root; でノード10を返す。

 1回目も root->right = insert(...) でノード10のアドレスを再設定し、
 return root; でノード5を返す。

 結果
 BSTはこうなる：

       5
      / \
     3   10
        /
       8
 ポイント
 再帰的に空き場所を探す
 insert 関数は、適切な場所が見つかるまで子ノードの左右に再帰で潜っていきます。

 空き場所に来たら新しいノードを作る
 root == nullptr のときに新ノードを返し、これがその親の left または right に代入されます。

 戻りながら親ノードのポインタを更新していく
 こうして木の構造が正しく更新されていきます。

 もし図やステップごとの変数の中身イメージが欲しかったら教えてください！









 ChatGPT に質問する



 */
