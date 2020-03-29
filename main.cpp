#include "task4-2.h"

using namespace std;

int main() {

    Heap heap;



for (int i = 10; i > 0; i--)    heap.add(i,10 - i);




  for (int i = 9; i > 0; i--)
  {
      heap.sort();
      for (auto it = heap.heaplist.begin(); it != heap.heaplist.end(); it++) //vivod
      {
          cout << it->key << " ";
      }
      cout << endl;
      heap.extract_max();
      for (auto it = heap.heaplist.begin(); it != heap.heaplist.end(); it++) //vivod
      {
          cout << it->key << " ";
      }
      cout << endl;
  }


    return 0;
}