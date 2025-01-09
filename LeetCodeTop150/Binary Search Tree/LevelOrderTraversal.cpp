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

void levelOrderTraversal(TreeNode *node)
{
  if (node == NULL)
  {
    return;
  }

  queue<TreeNode *> q;
  q.push(node);
  q.push(NULL);

  while (q.size() > 1)
  {
    TreeNode *curr = q.front();

    q.pop();

    if (curr == NULL)
    {
      cout << "\n";
      q.push(NULL);
      continue;
    }

    cout << curr->value << " ";

    if (curr->left != NULL)
    {
      q.push(curr->left);
    }
    if (curr->right != NULL)
    {
      q.push(curr->right);
    }
  }
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
  root->right = node2;

  node1->left = node3;
  node1->right = node4;

  node2->left = node5;
  node2->right = node6;

  levelOrderTraversal(root);

  return 0;
}