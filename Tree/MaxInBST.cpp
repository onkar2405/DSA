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

int maxInBST(Node *root)
{
  if (root == NULL)
  {
    return negative_infinity;
  }

  return max(max(maxInBST(root->left), root->val), max(maxInBST(root->right), root->val));
}

int main()
{

  Node *root = new Node(50);
  Node *node1 = new Node(11);
  Node *node2 = new Node(12);
  Node *node3 = new Node(21);
  Node *node4 = new Node(22);
  Node *node5 = new Node(23);
  Node *node6 = new Node(24);

  root->left = node1;
  node1->left = node3;

  node3->left = node5;
  node5->left = node6;
  node6->left = node4;
  node4->left = node2;

  cout << maxInBST(root);

  return 0;
}
