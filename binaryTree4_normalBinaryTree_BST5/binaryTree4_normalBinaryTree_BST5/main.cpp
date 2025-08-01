//
//  main.cpp
//  binaryTree4_normalBinaryTree_BST5
//
//  Created by Satoshi on 8/1/25.
//




/*
はい、**この `root` は一貫して同じ**です。ただし、**中身は更新されていく**可能性があります。
### 🔍 具体的にどういうこと？

```cpp
Node* root = nullptr;  // 最初は空の木
for (int val : arr) {
    root = insert(root, val); // 毎回、insertの戻り値でrootを更新
}
```

### ✅ ここで重要なのは：

* `root` という変数は **最初から最後まで同じポインタ変数（同じ名前・同じ場所）**。
* ただし、`insert` の戻り値によって「木の構造の先頭（ルート）」が更新されることがあるため、
  `root = insert(root, val);` のように **戻り値を代入するのが必須**です。

### 🌱 例：最初の1回


root = insert(nullptr, 4);
```

* これは「新しいノード（値4）」を作って、それを `root` に代入する。

### 🌳 次の挿入

```cpp
root = insert(root, 2);
```

* このとき `insert` 関数の内部で左にノード2を追加。
* 返ってくるのは「更新されたルートノード」なので、再度 `root` に代入してる。

| 挿入値 | rootの中身 | 説明               |
| --- | ------- | ---------------- |
| 4   | ノード4を指す | 最初の挿入で新しく作成      |
| 2   | ノード4を指す | 変わらないが、左に2が追加された |
| 1   | ノード4を指す | さらに左に1が追加された     |
| ... | ...     | 以降も同じ要領          |

`root` は同じ「箱（ポインタ）」だけど、中身の構造はどんどん木として拡張されていく。

---
必要があれば、再帰の流れも図で説明できますよ！

*/


#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;
    
};

Node* insert(Node* root,int val)
{
    if(!root) return new Node(val); //rootの作成
    
    if(val < root->data)
    {
        root-> left = insert(root-> left ,val);
    }
    else if(root->data < val)
    {
        root-> right = insert(root-> right ,val);
    }
    else{};
        
    return root;
}

void displayArrByPost(Node* root)
{
    if(!root) return;
    displayArrByPost(root-> left);
    displayArrByPost(root-> right);
    std::cout << root-> data;
}

int main()
{
    Node* root = nullptr;
    int arr[] = {1,3,5,2,4};
    
    for(int val : arr)
    {
        root = insert(root, val); //rootはNodeポインタの型なので、insertもNodeポインタの型
    }
    
    
    displayArrByPost(root);
   
    /*
        1
            3
          2    5
              4
     */
    
    
    return 0;
}
