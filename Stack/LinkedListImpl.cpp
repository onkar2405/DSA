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

struct MyList
{
  Node *node;
  Node *top = new Node(-1);
  int size;
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

  cout << searchNode(node1, 50);
  cout << "\n"
       << searchNode(node1, 13);

  cout << "\n"
       << searchNodeRecursive(node1, 20, 0);
  cout << "\n"
       << searchNodeRecursive(node1, 22, 0);
  return 0;
}