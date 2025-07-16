//
//  main.cpp
//  PassingByPointer7
//
//  Created by Satoshi on 7/16/25.
//

#include <iostream>



void DoubleArr1(int* index, int size)
{
    for(int i = 0 ; i < size; i++)
    {
        //*(index + i) *=2;
        index[i] *= 2;
        std::cout << *(index + i) <<std::endl;
    }
}


int main()
{
    //PassingByPointer3
   
    int arr1[3] = {1,2,3};
    
    for(int i = 0; i < 3; i++)
    {
        std::cout << arr1[i] ;
    }
    
    DoubleArr1(arr1,3);
    
    
   
    
    
    
    
    return 0;
}
