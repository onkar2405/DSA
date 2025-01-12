#include <iostream>
#include <math.h>
#include <limits>

using namespace std;

double negative_infinity = -numeric_limits<double>::infinity();

struct Node
{
  int val;

  Node *left;
  Node *right;

  Node(int v)
  {
    val = v;
    left = NULL;
    right = NULL;
  }
};

bool searchInBST(Node *root, int num)
{
  if (root == NULL)
  {
    return false;
  }

  if (root->val == num)
  {
    return true;
  }

  if (num > root->val)
  {
    return searchInBST(root->right, num);
  }

  return searchInBST(root->left, num);
}

int main()
{

  Node *root = new Node(15);
  Node *node1 = new Node(5);
  Node *node2 = new Node(20);
  Node *node3 = new Node(18);
  Node *node4 = new Node(80);
  Node *node5 = new Node(16);
  Node *node6 = new Node(24);

  root->left = node1;
  root->right = node2;
  node2->left = node3;
  node2->right = node4;
  node3->left = node5;
  node4->left = node6;

  cout << searchInBST(root, 24) << "\n";
  cout << searchInBST(root, 16);

  return 0;
}
