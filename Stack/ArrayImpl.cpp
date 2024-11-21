#include <iostream>
using namespace std;

struct MyStack
{
  int size;
  int *arr;
  int top;

  MyStack(int size)
  {
    size = size;
    arr = new int[size];
    top = -1;
  }

  void push(int num)
  {
    top++;
    arr[top] = num;
  }

  int peek()
  {
    return arr[top];
  }

  int pop()
  {
    int res = arr[top];
    top--;
    return res;
  }

  int getSize()
  {
    return top + 1;
  }

  bool isEmpty()
  {
    return top == -1;
  }
};

void printStack(MyStack myStack)
{
  for (int i = 0; i < myStack.getSize(); i++)
  {
    cout << myStack.arr[i] << " ";
  }

  cout << "\n";
}

int main()
{
  MyStack myStack(5);

  myStack.push(1);
  myStack.push(2);
  myStack.push(3);
  myStack.push(4);
  myStack.push(5);

  printStack(myStack);

  myStack.peek();
  cout << "Popped " << myStack.pop() << "\n";
  cout << "Size " << myStack.getSize() << "\n";

  return 0;
}