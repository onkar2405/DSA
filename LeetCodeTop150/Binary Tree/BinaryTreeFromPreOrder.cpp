
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

unordered_map<int, int> inOrderMap;

TreeNode *buildTreeHelper(vector<int> &preOrder, int preStart, int preEnd,
                          vector<int> &inOrder, int inStart, int inEnd)
{
  if (inStart > inEnd || preStart > preEnd)
  {
    return NULL;
  }

  int rootIndex = inOrderMap[preOrder[preStart]];
  int leftSide = rootIndex - inStart;

  TreeNode *root = new TreeNode(preOrder[preStart]);

  root->left = buildTreeHelper(preOrder, preStart + 1, leftSide + preStart, inOrder, inStart, rootIndex - 1);
  root->right = buildTreeHelper(preOrder, preStart + leftSide + 1, preEnd, inOrder, rootIndex + 1, preEnd);

  return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
  for (int i = 0; i < inorder.size(); i++)
  {
    inOrderMap[inorder[i]] = i;
  }

  return buildTreeHelper(preorder, 0, preorder.size() - 1,
                         inorder, 0, inorder.size() - 1);
}