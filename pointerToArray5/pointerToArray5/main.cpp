//
//  main.cpp
//  pointerToArray5
//
//  Created by Satoshi on 7/29/25.
//

#include <iostream>

void calculateArr1(int arr[], int size)
{
    for(int i =0; i< size; i++ )
    {
        std::cout<< arr[i] << std::endl;
    }
}

void calculateArr2(int (*p)[],int size)
{
    for(int i =0; i< size; i++ )
    {
        std::cout<< (*p)[i] << std::endl;
    }
}

int main()
{
    int arr[3] = {1,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    calculateArr1(arr, size);
    
    calculateArr2(&arr,size);
    
    

    
    
    return 0;
}
