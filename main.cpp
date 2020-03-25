#include "task4-2.h"

using namespace std;

int main() {

    Heap heap;

    /*heap.add(1,12);
    //heap.add(15,10);
    heap.add(4,10);
    heap.add(17,10);
    heap.add(18,10);
    heap.add(0,10);
    heap.add(6,10);
    heap.add(15,10);
    for (auto it = heap.heaplist.begin(); it != heap.heaplist.end(); it++) //vivod
    {
        cout << it->key << " ";
    }
    cout << endl;
    heap.sort();

    for (auto it = heap.heaplist.begin(); it != heap.heaplist.end(); it++) //vivod
    {
        cout << it->key << " ";
    }
    cout << endl << heap.getsize() << endl;

    heap.extract_max();

    for (auto it = heap.heaplist.begin(); it != heap.heaplist.end(); it++) //vivod
    {
        cout << it->key << " ";
    }
    cout << endl << heap.getsize() << endl << heap.height();

    auto it = heap.heaplist.begin();
    cout << it->value;*/
    for (int i = 1; i < 1000; i++)
    {
        heap.add(i, 1000 - i);
    }
    heap.sort();
    for (auto it = heap.heaplist.begin(); it != heap.heaplist.end(); it++) //vivod
    {
        cout << it->key << " ";
    }
    return 0;
}