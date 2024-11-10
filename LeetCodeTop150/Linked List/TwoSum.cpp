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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
  ListNode *resultHead = new ListNode();
  ListNode *resultPtr = resultHead;
  ListNode *resultTail = new ListNode();
  int carry = 0;
  while (l1 || l2 || carry)
  {
    int l1Val = l1 == NULL ? 0 : l1->val;
    int l2Val = l2 == NULL ? 0 : l2->val;

    int sum = l1Val + l2Val + carry;
    ListNode *newNode = new ListNode();
    resultPtr->val = sum % 10;
    resultPtr->next = newNode;
    carry = sum / 10;
    resultTail = resultPtr;
    resultPtr = newNode;
    if (l1 != NULL)
    {
      l1 = l1->next;
    }
    if (l2 != NULL)
    {
      l2 = l2->next;
    }
  }
  delete (resultPtr);
  resultTail->next = NULL;
  return resultHead;
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
  ListNode *head = new ListNode(9);
  ListNode *temp1 = new ListNode(9);
  ListNode *temp2 = new ListNode(9);

  head->next = temp1;
  temp1->next = temp2;
  ListNode *head1 = new ListNode(9);
  ListNode *temp3 = new ListNode(9);

  head1->next = temp3;

  ListNode *L3 = addTwoNumbers(head, head1);
  recursiveTraversal(L3);
  return 0;
}