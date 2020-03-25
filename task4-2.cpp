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
                while((left_C <= heaplist.size() - 1) || (right_C <= heaplist.size() - 1))
                {
                    auto iter1= heaplist.begin();
                    auto iter2 = heaplist.begin();
                    for (int j = 0; j < left_C; j++) iter1++;
                    for (int j = 0; j < right_C; j++) iter2++;

                    if ((iter->key < iter1->key) || (iter->key < iter2->key))
                    {
                        if ((iter1->key - iter2->key) > 0)
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
                if (col_swap == 0) swaping = false;
            }
        }
        if (global_col_swap == 0) break;
    }
}

void Heap::extract_max()
{
    if (!heaplist.empty())
    {
        auto iter_b = heaplist.begin();
        auto iter_e = heaplist.end();
        iter_e--;
        swap(*iter_b, *iter_e);
        heaplist.pop_back();
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