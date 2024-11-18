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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
  ListNode *dummy = new ListNode(0);
  dummy->next = head;

  ListNode *slow = dummy;
  ListNode *fast = dummy;

  for (int i = 0; i <= n; i++)
  {
    fast = fast->next;
  }

  while (fast != NULL)
  {
    fast = fast->next;
    slow = slow->next;
  }

  slow->next = slow->next->next;
  return dummy->next;
}

ListNode *removeNthFromEndNaive(ListNode *head, int n)
{
  if (head == NULL)
  {
    return NULL;
  }

  if (head->next == NULL)
  {
    return NULL;
  }

  int total = 0;
  ListNode *curr = head;

  while (curr != NULL)
  {
    total++;
    curr = curr->next;
  }

  int i = total - n;

  if (i == 0)
  {
    return head->next;
  }

  curr = head;
  while (i > 1)
  {
    curr = curr->next;
    i--;
  }

  curr->next = curr->next->next;
  return head;
}

void recursiveTraversal(ListNode *itr)
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
  ListNode *head = new ListNode(1);
  ListNode *node1 = new ListNode(2);
  ListNode *node2 = new ListNode(3);
  ListNode *node3 = new ListNode(4);
  ListNode *node4 = new ListNode(5);

  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;

  ListNode *L3 = removeNthFromEnd(head, 5);
  recursiveTraversal(L3);
  return 0;
}