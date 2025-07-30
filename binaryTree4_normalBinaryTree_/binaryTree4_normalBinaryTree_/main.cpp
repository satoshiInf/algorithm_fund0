
/*
 Binary Search Tree（二分探索木）は：
「左に小さく、右に大きく」というルールで値を配置した特殊なバイナリーツリーです。
🔑 ルール（超重要）
各ノードについて：
左の子 → そのノードより 小さい値
右の子 → そのノードより 大きい値
このルールがすべてのノードに当てはまる
✅ BSTにすると何がいいの？
値の 検索（search）
値の 挿入（insert）
値の 削除（delete）
これらがうまくできる！（※バランスが良ければ O(log n)）
 
 自分で手動で入れることができないやつ（自分で勝手に入れられない）がBST
 
 BSTでは値の入れ方にルールがあって答えが一つに定まる！！！
 
 BST のルールは：
 左の子には「自分より小さい値」
 右の子には「自分より大きい値」

 
 */


#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr),right(nullptr){};
    //ポインターは際し示すものの値がないと書くのは間違い、指し示す先のアドレスがないとかく
};

Node* insert(Node* root, int val)
{
    
    
}

int main()
{
    
    
    
    
    
    
    return 0;
}
