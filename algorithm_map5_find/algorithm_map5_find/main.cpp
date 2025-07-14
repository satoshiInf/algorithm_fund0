/*
 基本形
 std::map<KeyType, Value> mapname
 
 auto it = mapname.find(key)
 
 if(it != mapname.end() )
 {
 
 /*
 ポイント
 it == map.end()    探したキーは存在しない（見つからなかった）
 it != map.end()    探したキーが存在して、その要素を指している（見つかった）
 
 //説明
 map.end() は「最後の要素の次」を指す特別なイテレータ
 つまり、it != mapname.end()は「最後の要素の次」を指す特別なイテレータではない　とき
 「終端（終わり）」を表すイテレータで、要素ではありません。
　find の返り値が map.end() になるのは『見つからなかった』ことの合図
 find は、探したキーがあればその要素のイテレータを返します。
　もし無ければ、「終端」を返します。
　したがって、it != map.end() は
 「見つからなかった終端ではない」＝「要素を指している」
 ＝「見つかった」 と判断できます。
 * /
 
 
 }
 else
 {
 
 }
 
 
 
 */

#include <iostream>
#include <map>

int main()
{
    auto it =
    
    

    return 0;
}
