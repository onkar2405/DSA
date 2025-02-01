
#include <iostream>
#include <math.h>
#include <limits>

using namespace std;

/**
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/?envType=study-plan-v2&envId=top-interview-150
 */
struct TreeNode
{
  int val;

  TreeNode *left;
  TreeNode *right;

  TreeNode(int v)
  {
    val = v;
    left = NULL;
    right = NULL;
  }
};

int maxDepth(TreeNode *root)
{
  if (root == NULL)
  {
    return 0;
  }

  return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
}