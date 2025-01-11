#include <iostream>

using namespace std;

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

int maxLevel = 0;

void printLeftView(Node *root, int level)
{
  if (root == NULL)
  {
    return;
  }

  if (maxLevel < level)
  {
    cout << root->val << " ";
    maxLevel = level;
  }

  printLeftView(root->left, level + 1);
  printLeftView(root->right, level + 1);
}

int main()
{

  Node *root = new Node(5);
  Node *node1 = new Node(11);
  Node *node2 = new Node(12);
  Node *node3 = new Node(21);
  Node *node4 = new Node(22);
  Node *node5 = new Node(23);
  Node *node6 = new Node(24);

  root->left = node1;
  root->right = node2;

  node1->left = node3;
  node1->right = node4;

  node2->left = node5;
  node2->right = node6;

  printLeftView(root, 1);
  return 0;
}