#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
  Queue<char> queue;
  char charIn;

  cout << "Entre com a string: ";
  cin.get(charIn);

  while (charIn != '\n' && !queue.isFull())
  {
    queue.enqueue(charIn);
    cin.get(charIn);
  }

  queue.print();

  while (!queue.isEmpty())
  {
    cout << queue.dequeue() << endl;
  }

  return 0;
}