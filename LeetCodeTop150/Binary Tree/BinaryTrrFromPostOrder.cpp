
#include <iostream>
#include <math.h>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?envType=study-plan-v2&envId=top-interview-150
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

unordered_map<int, int> inMap;

TreeNode *buildTreeHelper(vector<int> &inorder, int inStart, int inEnd,
                          vector<int> &postorder, int postStart, int postEnd)
{
  if (inStart > inEnd || postStart > postEnd)
  {
    return NULL;
  }

  int rootVal = postorder[postEnd];
  int rootIndex = inMap[rootVal];
  int leftSide = rootIndex - inStart;

  TreeNode *root = new TreeNode(rootVal);

  root->left = buildTreeHelper(inorder, inStart, rootIndex - 1, postorder, postStart, postStart + leftSide - 1);
  root->right = buildTreeHelper(inorder, rootIndex + 1, inEnd, postorder, postStart + leftSide, postEnd - 1);

  return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
  for (int i = 0; i < inorder.size(); i++)
  {
    inMap[inorder[i]] = i;
  }

  return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}