//
// Created by Алексей  on 2020-03-24.
//
#include <list>
#include <iostream>
#include <cmath>
using namespace std;

class Heap
{
public:
    struct Pair
    {
        int key;
        int value;
    };
    Pair para;
    list <struct Pair> heaplist;

    Heap();
    void add(int key, int value);
    void sort();
    void extract_max();
    int getsize();
    int height();
};