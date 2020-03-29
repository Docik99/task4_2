//
// Created by Алексей  on 2020-03-24.
//
#include "task4-2.h"

Heap::Heap() {
    para.key = 0;
    para.value = 0;
}

void Heap:: add (int key, int value) {
    Pair l;
    l.key = key;
    l.value = value;
    heaplist.push_back(l);
}

void Heap::sort() {
    for (;;) //цикл проверяет не появилось ли новой необходимости в перемещении после уже выполненых перемещений
    {
        int global_col_swap = 0;
        for (int i = 0; i < heaplist.size(); i++) //цикл перебора элементов
        {
            bool swaping = true;
            auto iter_osn = heaplist.begin();
            for (int j = 0; j < i; j++) iter_osn++; //перемещение начального указателя на нужный элемент
            while (swaping != false) //пока происходит перемещение элементов с этой позиции на следующие позиции не переходим
            {
                int col_swap = 0;
                auto iter = iter_osn;
                auto iter_dubl = iter_osn;
                int left_C = 2 * i + 1;
                int right_C = 2 * i + 2;
                //while((left_C <= heaplist.size() - 1) || (right_C <= heaplist.size() - 1))
                for (;;)
                {
                    auto iter1= heaplist.begin();
                    auto iter2 = heaplist.begin();
                    for (int j = 0; j < left_C; j++) iter1++;
                    for (int j = 0; j < right_C; j++) iter2++;

                    if (left_C <= heaplist.size() - 1)
                    {
                        if (right_C <= heaplist.size() - 1)
                        {
                            if ((iter->key > iter1->key) || (iter->key > iter2->key))
                            {
                                if ((iter1->key - iter2->key) < 0)
                                {
                                    iter_dubl = iter1;
                                    swap(*iter,*iter1);
                                    right_C = 2 * left_C + 2;
                                    left_C = 2 * left_C + 1;
                                    iter = iter_dubl;
                                    col_swap++;
                                    global_col_swap++;
                                }
                                else
                                {
                                    iter_dubl = iter2;
                                    swap(*iter, *iter2);
                                    left_C = 2 * right_C + 1;
                                    right_C = 2 * right_C + 2;
                                    iter = iter_dubl;
                                    col_swap++;
                                    global_col_swap++;
                                }
                            }
                            else break;
                        }
                        else if (right_C > heaplist.size() - 1)
                        {
                            if (iter->key > iter1->key)
                            {
                                swap(*iter,*iter1);
                                col_swap++;
                                global_col_swap++;
                            }
                            else break;
                        }
                    }
                    else break;
                }
                if (col_swap == 0) swaping = false;
            }
        }
        if (global_col_swap == 0) break;
    }
}

int Heap::extract_max()
{
    sort();
    if (!heaplist.empty())
    {
        int max = heaplist.front().key;
        auto iter_m = heaplist.begin();
        for (auto iter = heaplist.begin(); iter != heaplist.end(); iter++)
        {
            if (iter->key > max)
            {
                max = iter->key;
                iter_m = iter;
            }
        }
        heaplist.erase(iter_m);
        return max;
    }
    else throw std::out_of_range("Empty");
}

int Heap::getsize()
{
    return heaplist.size();
}

int Heap::height()
{
    return int(log2(heaplist.size()) + 1);
}

bool Heap::check()
{
    for (int i = 0; i < heaplist.size(); i++) //проверка того что каждый потомок больше родителя
    {
        auto iter = heaplist.begin();
        for (int j = 0; j < i; j++) iter++;

        int left_C = 2 * i + 1;
        int right_C = 2 * i + 2;

        auto iterL= heaplist.begin();
        auto iterR = heaplist.begin();
        for (int j = 0; j < left_C; j++) iterL++;
        for (int j = 0; j < right_C; j++) iterR++;

        if (left_C <= heaplist.size() - 1)
        {
            if (iterL->key < iter->key) return false;
        }

        if (right_C <= heaplist.size() - 1)
        {
            if (iterR->key < iter->key) return false;
        }
    }
    return true;
}