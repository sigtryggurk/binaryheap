//
//  binheap.h
//  BinaryHeap
//
//  Created by Sigtryggur Kjartansson on 5/14/15.
//  Copyright (c) 2015 Sigtryggur Kjartansson. All rights reserved.
//

#ifndef __BinaryHeap__binheap__
#define __BinaryHeap__binheap__

#include <stdio.h>
#include <functional>

#define START_SIZE (1<<10)

class Heap
{
private:
    int *arr;
    int tail;
    int maxsize;
    std::function<bool(int,int)> priority;
    int *parent(int *child);
    int *left(int *node);
    int *right(int *node);
    void heapify_down(int *node);
    void heapify_up(int *node);
    int indexOf(int *node);
    void double_heap();
    void half_heap();
public:
    Heap(std::function<bool(int,int)> priority);
    int getSize();
    int peek();
    int extract();
    void insert(int node);
    void insert(int *arr, int size);
    void print();
};




#endif /* defined(__BinaryHeap__binheap__) */
