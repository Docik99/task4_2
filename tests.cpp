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

}

/*TEST_CASE("Extract")
{
    Heap heap;

    for (int i = 1; i < 1000; i++)
    {
        heap.add(i, 1000 - i);
    }

    for (int i = 998; i > 0; i--)
    {
        heap.sort();
        auto iter_e = heap.heaplist.end();
        //iter_e--;
        heap.extract_max();
        auto iter_b = heap.heaplist.begin();
        REQUIRE(heap.getsize() == i);
        REQUIRE(iter_b->key == iter_e->key);
        REQUIRE(iter_b->value == iter_e->value);
    }
    for (int i = 0; i < 100; i++) REQUIRE_THROWS_AS( heap.extract_max() , std::out_of_range);
}*/

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