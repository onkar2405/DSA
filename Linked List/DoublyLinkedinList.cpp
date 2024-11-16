#include <iostream>
using namespace std;

struct Node
{
  /* data */
  int val;
  Node *next = NULL;
  Node *prev = NULL;

  Node(int val)
  {
    this->val = val;
  }
};

void recursiveTraversal(Node *itr)
{
  cout << itr->val << " ";

  if (itr->next == NULL)
  {
    return;
  }
  recursiveTraversal(itr->next);
}

void reversePrintRecursive(Node *last)
{
  cout << last->val << " ";

  if (last->prev == NULL)
  {
    return;
  }

  reversePrintRecursive(last->prev);
}

int main()
{

  Node *node1 = new Node(4);
  Node *node2 = new Node(1);
  Node *node3 = new Node(13);
  Node *node4 = new Node(24);
  Node *node5 = new Node(20);

  node1->next = node2;
  node2->prev = node1;
  node2->next = node3;
  node3->prev = node2;
  node3->next = node4;
  node4->prev = node3;
  node4->next = node5;
  node5->prev = node4;

  reversePrintRecursive(node5);
  return 0;
}