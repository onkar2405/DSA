#include <iostream>
using namespace std;

struct Dequeue
{
  int size, cap;
  int *arr;

  Dequeue(int s)
  {
    cap = s;
    size = 0;
    arr = new int[s];
  }

  void insertRear(int val)
  {
    if (!isFull())
    {
      this->arr[this->size] = val;
      this->size++;
    }
    else
    {
      cout << "Q is Full" << "\n";
    }
  }

  void deleteRear()
  {
    if (!isEmpty())
    {
      this->size--;
    }
  }

  void insertFront(int val)
  {
    if (isFull())
    {
      cout << "Q is full" << "\n";
    }
    else
    {
      if (!isEmpty())
      {
        for (int i = this->size; i > 0; i--)
        {
          this->arr[i] = this->arr[i - 1];
        }
      }
      this->arr[0] = val;
      this->size++;
    }
  }

  void deleteFront()
  {
    if (isEmpty())
    {
      cout << "Q is empty" << "\n";
    }
    else
    {
      for (int i = 0; i < this->size - 1; i++)
      {
        this->arr[i] = this->arr[i + 1];
      }

      this->size--;
    }
  }

  void printQ()
  {
    if (isEmpty())
    {
      cout << "Q is empty";
    }
    else
    {
      for (int i = 0; i < this->size; i++)
      {
        cout << this->arr[i] << " ";
      }
    }
    cout << "\n";
  }

  bool isEmpty()
  {
    return this->size == 0;
  }

  bool isFull()
  {
    return this->cap == this->size;
  }
};

int main()
{

  Dequeue d(5);

  d.insertFront(1);
  d.insertFront(2);
  d.insertFront(20);
  d.insertRear(3);
  d.insertRear(30);
  d.insertRear(34);

  d.printQ();
  d.deleteFront();
  d.printQ();
  d.deleteFront();
  d.printQ();
  d.deleteFront();
  d.printQ();
  d.deleteRear();
  d.printQ();
  return 0;
}