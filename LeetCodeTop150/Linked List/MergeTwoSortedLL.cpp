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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{

  if (list1 == NULL)
  {
    return list2;
  }
  if (list2 == NULL)
  {
    return list1;
  }

  ListNode *sortedList = list1;
  if (list1->val > list2->val)
  {
    sortedList = list2;
    list2 = list2->next;
  }
  else
  {
    list1 = list1->next;
  }

  ListNode *curr = sortedList;

  while (list1 && list2)
  {
    if (list1->val < list2->val)
    {
      curr->next = list1;
      list1 = list1->next;
    }
    else
    {
      curr->next = list2;
      list2 = list2->next;
    }
    curr = curr->next;
  }
  if (!list1)
  {
    curr->next = list2;
  }
  if (!list2)
  {
    curr->next = list1;
  }

  return sortedList;
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
  ListNode *head = new ListNode(-9);
  ListNode *temp1 = new ListNode(2);
  // ListNode *temp2 = new ListNode(4);

  head->next = temp1;
  // temp1->next = temp2;

  ListNode *head1 = new ListNode(4);
  ListNode *temp3 = new ListNode(6);
  // ListNode *temp4 = new ListNode(4);

  head1->next = temp3;
  // temp3->next = temp4;

  ListNode *L3 = mergeTwoLists(head, head1);
  recursiveTraversal(L3);
  return 0;
}