/*
 問題：名前・住所・コメントの入力と出力プログラムを作成せよ
 🎯 要件
 char 配列を使って 名前（最大30文字） を std::cin.getline() で受け取る。
 std::string を使って 住所 を std::getline() で受け取る。
 std::string を使って コメント を std::getline() で受け取る。
 入力されたすべての情報を整えて出力する。
 ⛏ 制約条件
 名前は char name[31]; を使い、std::cin.getline() を使って読み取る。
 住所・コメントは std::string で、std::getline() を使うこと。
 出力時には改行で区切ってすべて表示する。
 
 
 名前を入力してください（30文字以内）：山田太郎
 住所を入力してください：東京都新宿区西新宿1-1-1
 コメントを入力してください：よろしくお願いします。

 【入力内容】
 名前：山田太郎
 住所：東京都新宿区西新宿1-1-1
 コメント：よろしくお願いします。

 */


#include <iostream>
#include <string>

int main()
{
    std::cout <<"名前を入力してください（30文字以内）：" << std::endl;
    char name[31];
    std::cin.getline(name, 31); //最後に\0が格納されるので最大＋１でかく

    std::cout <<"住所を入力してください：" << std::endl;
    std::string place;
    std::getline(std::cin, place);
    
    std::cout <<"コメントを入力してください：" << std::endl;
    std::string comment;
    std::getline(std::cin, comment);
    
    
    std::cout<<"出力内容" <<std::endl;
    std::cout<<name <<std::endl;
    std::cout<<place <<std::endl;
    std::cout<<comment <<std::endl;
    
    
    return 0;
}
