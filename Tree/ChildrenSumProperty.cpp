#include <iostream>
#include <queue>
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

bool childrenSumCheck(TreeNode *node)
{
  if (node == NULL)
  {
    return false;
  }

  if ((node->left == NULL && node->right == NULL))
  {
    return true;
  }
  int nodeSum = 0;

  if (node->left != NULL)
  {
    nodeSum += node->left->value;
  }

  if (node->right != NULL)
  {
    nodeSum += node->right->value;
  }

  return nodeSum == node->value && childrenSumCheck(node->left) && childrenSumCheck(node->right);
}

int main()
{

  TreeNode *root = new TreeNode(20);
  TreeNode *node1 = new TreeNode(8);
  TreeNode *node2 = new TreeNode(12);
  TreeNode *node3 = new TreeNode(4);
  TreeNode *node4 = new TreeNode(5);
  TreeNode *node5 = new TreeNode(23);
  TreeNode *node6 = new TreeNode(24);

  root->left = node1;
  root->right = node2;

  node1->left = node3;
  node1->right = node4;

  // node2->left = node5;
  // node2->right = node6;

  cout << childrenSumCheck(root);

  return 0;
}