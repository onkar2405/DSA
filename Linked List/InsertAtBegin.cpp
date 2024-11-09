#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;

  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

Node *insertAtStart(int x, Node *head)
{
  Node *node = new Node(500);
  node->next = head;
  head = node;

  return head;
}

Node *insertAtPosition(int x, int position, Node *head)
{
  Node *node = new Node(x);
  if (position == 1)
  {
    node->next = head;
    return node;
  }

  Node *counter = head;
  int i = 1;
  while (i < position - 1)
  {
    if (head == NULL)
    {
      break;
    }
    i++;
    head = head->next;
  }

  node->next = head->next;
  head->next = node;

  return head;
}

void insertAtEnd(int x, Node *head)
{
  Node *node = new Node(x);

  while (head->next != NULL)
  {
    head = head->next;
  }
  head->next = node;
}

void recursiveTraversal(Node *itr)
{
  cout << itr->data << " ";

  if (itr->next == NULL)
  {
    return;
  }
  recursiveTraversal(itr->next);
}

int main()
{

  Node *head = new Node(10);
  Node *temp1 = new Node(100);
  Node *temp2 = new Node(1000);

  head->next = temp1;
  temp1->next = temp2;
  Node *itr = head;
  recursiveTraversal(head);

  head = insertAtStart(50, head);
  cout << "\n";
  recursiveTraversal(head);

  cout << "\n";
  insertAtEnd(501, head);
  recursiveTraversal(head);

  head = insertAtPosition(600, 1, head);
  cout << "\n";
  recursiveTraversal(head);

  return 0;
}