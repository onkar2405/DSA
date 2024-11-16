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

int searchNode(Node *head, int num)
{
  int index = 0;
  while (head != NULL)
  {
    if (head->val == num)
    {
      return ++index;
    }
    head = head->next;
    index++;
  }

  return -1;
}

int searchNodeRecursive(Node *node, int num, int index)
{
  if (node == NULL)
  {
    return -1;
  }
  if (node->val == num)
  {
    return ++index;
  }
  index = index + 1;
  return searchNodeRecursive(node->next, num, index);
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
  Node *node4 = new Node(40);

  node1->next = node2;
  node2->next = node3;
  node3->next = node4;

  cout << searchNode(node1, 50);
  cout << "\n"
       << searchNode(node1, 13);

  cout << "\n"
       << searchNodeRecursive(node1, 50, 0);
  cout << "\n"
       << searchNodeRecursive(node1, 13, 0);
  return 0;
}