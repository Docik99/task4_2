//
// Created by Алексей  on 2020-03-24.
//
#include <list>
#include <iostream>
#include <cmath>
using namespace std;

class Heap
{
    struct Pair
    {
        int key;
        int value;
    };

public:

    Pair para;
    list <struct Pair> heaplist;

    Heap();
    void add(int key, int value);
    void sort();
    int extract_max();
    int getsize();
    int height();
    bool check();
};