#include <iostream>
#include <cmath>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
  if (head == NULL || k == 0)
  {
    return head;
  }
  int totalNodes = 0;
  ListNode *curr = head;
  while (curr != NULL)
  {
    totalNodes++;
    curr = curr->next;
  }
  k = k % totalNodes;
  ListNode *slow = head;
  ListNode *fast = head;

  if (k == 0)
  {
    return head;
  }

  for (int i = 0; i < k; i++)
  {
    if (fast->next == NULL)
    {
      fast = head;
    }
    else
    {
      fast = fast->next;
    }
  }

  while (fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next;
  }
  ListNode *newHead = slow->next;
  fast->next = head;
  slow->next = NULL;

  return newHead;
}

int main()
{
  ListNode *head = new ListNode(1);
  ListNode *node1 = new ListNode(2);
  ListNode *node2 = new ListNode(3);
  ListNode *node3 = new ListNode(4);
  ListNode *node4 = new ListNode(5);

  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;

  ListNode *L3 = rotateRight(head, 2);
  return 0;
}