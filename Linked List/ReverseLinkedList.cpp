#include <iostream>
using namespace std;

struct Node
{
  /* data */
  int val;
  Node *next;

  Node(int val)
  {
    this->val = val;
    this->next = NULL;
  }
};

// 4 -> 3 -> 2 -> 1

//              3  4

Node *reverseLL(Node *head)
{
  Node *newHead = head;
  Node *prev = NULL;

  while (newHead != NULL)
  {
    Node *next = newHead->next;
    newHead->next = prev;
    prev = newHead;
    newHead = next;
  }

  return prev;
}

void recursiveTraversal(Node *itr)
{
  cout << itr->val << " ";

  if (itr->next == NULL)
  {
    return;
  }
  recursiveTraversal(itr->next);
}

int main()
{

  Node *node1 = new Node(4);
  Node *node2 = new Node(1);
  Node *node3 = new Node(13);
  Node *node4 = new Node(24);
  Node *node5 = new Node(20);
  Node *node6 = new Node(44);
  Node *node7 = new Node(22);

  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  node5->next = node6;
  node6->next = node7;

  Node *newHead = reverseLL(node1);

  recursiveTraversal(newHead);

  return 0;
}