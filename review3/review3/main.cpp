//
//  main.cpp
//  review3
//
//  Created by Satoshi on 7/19/25.
//

#include <iostream>

//polyphorism

class Parent
{
    public:
    
    int x;
    int y;
    //ここをpublicにしないとメインから取り出せない
    Parent(int xvalue,int yvalue): x(xvalue), y(yvalue) //ここでエラー
    {
        //xvalue と yvalue という引数を受け取り、メンバ変数 x, y をその値でそれぞれ初期化する。
        //引数を受け取り、x（引数）、　y（引数）
    }
    
    //Parent(int xvalue, int yvalue):x(xvalue),y（yvalue)
    
    virtual void say()
    {
        std::cout << "Parent" << std::endl;
    }
    
};

class Child: public Parent
{
public: //ここをpublicにしないとメインから取り出せない
    Child(int xvalue, int yvalue) : Parent(xvalue, yvalue) {} //ここでエラー、コンストラクタは別途継承が必要

    
    void say() override
    {
        std::cout << "Child" << std::endl;
        
    }
    
    
    
};


int main()
{
    Parent p1{1,1};
    std::cout << p1.x << " " << p1.y << std::endl;
    
    Parent *ptr = &p1;
    std::cout << ptr->x << " " << ptr->y << std::endl;
    

    Child c1{2,2};
    Parent& ref = c1;
    ref.say();
    c1.say();
    
    Child c2{3,3};
    Parent* ptr2 = &c2;
    ptr2->say();
    c2.say();
    
    
    
    
    
    return 0;
}
