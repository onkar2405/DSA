#include <iostream>
using namespace std;

struct Queue
{
  int *arr;
  int size, front, rear, cap;

  Queue(int c)
  {
    arr = new int[c];
    size = 0;
    cap = c;
    front = 0;
    rear = 0;
  }

  void enqueue(int num)
  {
    if (isFull())
    {
      cout << "Queue is Full" << "\n";
      return;
    }
    int index = this->rear % this->cap;
    this->arr[index] = num;
    this->rear++;
    this->size++;
  }

  void dequeue()
  {
    if (isEmpty())
    {
      cout << "Queue is empty" << "\n";

      return;
    }
    this->arr[this->front % this->cap] = -1;
    this->front++;
    this->size--;
  }

  void printQueue()
  {
    if (isEmpty())
    {
      cout << "Queue is empty" << "\n";

      return;
    }

    int frontInd = this->front;
    int cap = this->cap;
    int rearInd = this->rear;

    for (int i = frontInd; i < rearInd; i++)
    {
      cout << this->arr[i % cap] << " ";
    }

    cout << "\n";
  }

  bool isEmpty()
  {
    return size == 0;
  }

  bool isFull()
  {
    return size == cap;
  }
};

int main()
{
  Queue q(5);

  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  q.printQueue();
  q.enqueue(5);

  q.printQueue();

  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.dequeue();

  q.printQueue();

  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);

  q.printQueue();

  q.dequeue();
  q.enqueue(10);
  q.enqueue(20);

  q.printQueue();

  return 0;
}