//
// Created by Алексей  on 2020-03-26.
//
#include "task4-2.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Creating")
{
    for (int i = 0; i < 300; i++)
    {
        Heap heap;
        REQUIRE(heap.para.key == 0);
        REQUIRE(heap.para.value == 0);
    }
}

TEST_CASE("Add")
{
    Heap heap;
    for (int i = 1; i < 1000; i++)
    {
        heap.add(i, 1000 - i);
        REQUIRE(heap.heaplist.size() == i);
        auto iter = heap.heaplist.end();
        iter--;
        REQUIRE(iter->key == i);
        REQUIRE(iter->value == 1000 - i);
    }
}

TEST_CASE("Sort")
{
    Heap heap;

    for (int i = 0; i < 1000; i++)
    {
        heap.add(i, 10);
        heap.sort();
        REQUIRE(heap.check());
    }


}

/*TEST_CASE("Extract")//max для невозрастающей
{
    Heap heap;

    for (int i = 0; i < 1000; i++)
    {
        heap.add(i, 10);
    }

    for (int i = 999; i >= 0 ; i--)
    {
        heap.sort();
        int key_b = heap.heaplist.back().key;

        int max = heap.extract_max();
        int key_f = heap.heaplist.front().key;

        REQUIRE(heap.getsize() == i);
        REQUIRE(key_f == key_b);

        for (auto it = heap.heaplist.begin(); it != heap.heaplist.end(); it++)
        {
            REQUIRE(it->key != max);
        }
    }

    for (int i = 0; i < 100; i++) REQUIRE_THROWS_AS( heap.extract_max() , std::out_of_range);
}*/

TEST_CASE("Extract")//max для невозрастающей
{
    Heap heap;

    for (int i = 0; i < 1000; i++)
    {
        heap.add(i, 10);
    }

    for (int i = 999; i >= 0 ; i--)
    {
        int max = heap.extract_max();

        REQUIRE(heap.getsize() == i);
        REQUIRE(heap.height() == int(log2(i) + 1));

        for (auto it = heap.heaplist.begin(); it != heap.heaplist.end(); it++)
        {
            REQUIRE(it->key != max);
        }
    }

    for (int i = 0; i < 100; i++) REQUIRE_THROWS_AS( heap.extract_max() , std::out_of_range);
}

TEST_CASE("Size")
{
    Heap heap;
    for (int i = 1; i < 1000; i++)
    {
        heap.add(i, 1000 - i);
        REQUIRE(heap.getsize() == i);
    }
}

TEST_CASE("Height")
{
    Heap heap;

    for (int i = 1; i < 1000; i++)
    {
        heap.add(i, 1000 - i);
        REQUIRE(heap.height() == int(log2(i) + 1));
    }

    for (int i = 998; i > 0; i--)
    {
        heap.extract_max();
        REQUIRE(heap.height() == int(log2(i) + 1));
    }
}