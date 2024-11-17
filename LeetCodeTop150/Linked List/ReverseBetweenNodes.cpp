#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseBetween(ListNode *head, int left, int right)
{
  if (head == NULL || left == right)
  {
    return head;
  }

  ListNode *newHead = new ListNode(0);
  newHead->next = head;

  ListNode *prev = newHead;

  for (int i = 1; i < left; i++)
  {
    prev = prev->next;
  }

  ListNode *curr = prev->next;

  for (int i = 0; i < right - left; i++)
  {
    ListNode *nextNode = curr->next;
    curr->next = nextNode->next;
    nextNode->next = prev->next;
    prev->next = nextNode;
  }

  return newHead->next;
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

  ListNode *node1 = new ListNode(1);
  ListNode *node2 = new ListNode(2);
  ListNode *node3 = new ListNode(3);
  ListNode *node4 = new ListNode(4);
  ListNode *node5 = new ListNode(5);

  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;

  ListNode *newHead = reverseBetween(node1, 1, 4);

  recursiveTraversal(newHead);

  return 0;
}