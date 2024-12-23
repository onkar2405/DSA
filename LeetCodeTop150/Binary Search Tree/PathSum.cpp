#include <iostream>
using namespace std;

/**
 * https://leetcode.com/problems/path-sum/?envType=study-plan-v2&envId=top-interview-150
 */

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool hasPathSum(TreeNode *root, int targetSum)
{
  if (root == NULL)
  {
    return false;
  }
  int remaining = targetSum - root->val;
  if (remaining == 0 && root->left == NULL && root->right == NULL)
  {
    return true;
  }
  return hasPathSum(root->left, remaining) || hasPathSum(root->right, remaining);
}
