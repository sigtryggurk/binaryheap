//
//  main.cpp
//  BinaryHeap
//
//  Created by Sigtryggur Kjartansson on 5/14/15.
//  Copyright (c) 2015 Sigtryggur Kjartansson. All rights reserved.
//

#include <iostream>
#include "binheap.h"
#include <climits>
using namespace std;

bool lt(int a, int b)
{
    return a<b;
}

bool gt(int a, int b)
{
    return a>b;
}

void basictest()
{
    // insert code here...

    
    Heap pq(lt);
    
    for (int i=INT_MAX; i>0; i/=2)
    {
        pq.insert(i);
    }
    for (int i=INT_MIN; i<0; i/=2)
    {
        pq.insert(i);
    }
    pq.print();
    // cout << pq.extractMin();
    
    int cmin = pq.extract();
    int nmin;
    while (pq.getSize())
    {
        nmin = pq.extract();
        if (nmin < cmin)
        {
            cout<< "Skamm" << endl;
        }
        cmin = nmin;
    }
    cout << "DONE " << endl;
    
}


void heap_sort(int *arr, int size, bool asc=true)
{
    std::function<bool(int,int)> comp = (asc) ? lt : gt;
    Heap heap(comp);
    heap.insert(arr, size);
    for (int i=0;i<size; i++)
        arr[i] = heap.extract();


}

void printArray(int *arr, int size)
{
    std::cout << "{";
    for (int i=0;i<size;i++)
    {
        std::cout << arr[i];
        if (i < size -1)
            std::cout << ", ";
        
    }
    std::cout << "}" << std::endl;
}


int main(int argc, const char * argv[])
{
    //basictest();
    
    int arr[] = {5,-4, 7, 4, 10, 5, 4, -9};
    heap_sort(arr, 8, false);
    printArray(arr, 8);
    return 1;
}
