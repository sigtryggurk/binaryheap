//
//  binheap.cpp
//  BinaryHeap
//
//  Created by Sigtryggur Kjartansson on 5/14/15.
//  Copyright (c) 2015 Sigtryggur Kjartansson. All rights reserved.
//

#include "binheap.h"
#include <iostream>

Heap::Heap(std::function<bool(int,int)> priority)
{
    this->maxsize = START_SIZE;
    this->arr = new int[START_SIZE];
    this->tail = 0;
    this->priority = priority;
}
/* 1-indexed index */
int Heap::indexOf(int *node)
{
    return (int)(node - this->arr) + 1;
}

int *Heap::parent(int *child)
{
    int i = indexOf(child)/2 - 1;
    return this->arr + i ;
}

int *Heap::left(int *node)
{
    int i = 2 * indexOf(node) - 1;
    return this->arr + i;
}

int *Heap::right(int *node)
{
    int i = 2 * indexOf(node) ;
    return this->arr + i;
}

void Heap::print()
{
    std::cout << "{";
    for (int i=0;i<this->tail;i++)
    {
        std::cout << this->arr[i];
        if (i < this->tail -1)
          std::cout << ", ";

    }
    std::cout << "}" << std::endl;
}

void Heap::heapify_up(int *node)
{
    int *parent = this->parent(node);
    while (node != this->arr && this->priority(*node, *parent))
    {
        std::swap(*node, *parent);
        node = parent;
        parent = this->parent(parent);
    }
}

void Heap::heapify_down(int *node)
{
    int *left = this->left(node);
    int *right = this->right(node);
    int *prioritychild = (*left > *right) ? right : left;
    while (indexOf(left) <= this->tail && indexOf(right) <= this->tail && this->priority(*prioritychild, *node))
    {
        std::swap(*node, *prioritychild);
        node = prioritychild;
        left = this->left(node);
        right = this->right(node);
        prioritychild = (this->priority(*right, *left)) ? right : left;
    }
    if (indexOf(left) <= this->tail && this->priority(*left, *node))
    {
        std::swap(*node, *left);
    }
}


void Heap::insert(int node)
{
    if (this->getSize() >= this->maxsize)
        this->double_heap();
    this->arr[this->tail] = node;
    heapify_up(&this->arr[this->tail]);
    ++this->tail;
}

void Heap::insert(int *arr, int size)
{
    for (int i=0;i<size;i++)
        this->insert(arr[i]);
}

int Heap::peek()
{
    return this->arr[0];
}

int Heap::extract()
{
    if (this->getSize() <= this->maxsize/4 && this->maxsize != START_SIZE)
      this->half_heap();
    int root = peek();
    this->arr[0] = this->arr[--this->tail];
    heapify_down(&this->arr[0]);
    return root;
}


int Heap::getSize()
{
    return this->tail;
}

void Heap::double_heap()
{
    this->maxsize *=2;
    int *new_arr;
    new_arr = new int[this->maxsize];
    memcpy(new_arr, this->arr, this->getSize() * sizeof(int));
    this->arr = new_arr;
}

void Heap::half_heap()
{
    this->maxsize /=2;
    int *new_arr;
    new_arr = new int[this->maxsize];
    memcpy(new_arr, this->arr, this->getSize() * sizeof(int));
    this->arr = new_arr;
}


