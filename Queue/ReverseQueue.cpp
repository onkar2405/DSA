#include <iostream>
#include <queue>
using namespace std;

void reverse(queue<int> &q)
{
  if (q.empty())
  {
    return;
  }

  int x = q.front();
  q.pop();
  reverse(q);
  q.push(x);
}

void printQ(queue<int> q)
{
  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }
}

int main()
{
  queue<int> q;

  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);

  reverse(q);
  printQ(q);

  return 0;
}