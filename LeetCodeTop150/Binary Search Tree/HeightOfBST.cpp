#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

struct TreeNode
{
  int value;

  TreeNode *left;
  TreeNode *right;

  TreeNode(int val)
  {
    value = val;
    left = NULL;
    right = NULL;
  }
};

int sizeRecursive(TreeNode *node)
{
  if (node == NULL)
  {
    return 0;
  }

  return 1 + max(sizeRecursive(node->left), sizeRecursive(node->right));
}

int main()
{

  TreeNode *root = new TreeNode(5);
  TreeNode *node1 = new TreeNode(11);
  TreeNode *node2 = new TreeNode(12);
  TreeNode *node3 = new TreeNode(21);
  TreeNode *node4 = new TreeNode(22);
  TreeNode *node5 = new TreeNode(23);
  TreeNode *node6 = new TreeNode(24);

  root->left = node1;

  node1->left = node3;

  node3->left = node5;
  node5->left = node6;
  node6->left = node4;
  node4->left = node2;

  cout << sizeRecursive(root);

  return 0;
}