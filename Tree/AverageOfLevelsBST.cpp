#include <iostream>
#include "../TreeNode.h";
#include <vector>
#include <queue>

using namespace std;

vector<double> calculateAvg(TreeNode<int> *root)
{
  if (root == NULL)
  {
    return {};
  }

  vector<double> result;
  queue<TreeNode<int> *> q;

  q.push(root);

  while (!q.empty())
  {
    int level = q.size();
    double sum = 0;

    for (int i = 0; i < level; i++)
    {
      TreeNode<int> *node = q.front();
      sum += node->val;
      q.pop();

      if (node->left != NULL)
      {
        q.push(node->left);
      }
      if (node->right != NULL)
      {
        q.push(node->right);
      }
    }
    result.push_back(sum / level);
    level++;
  }

  return result;
}

int main()
{

  TreeNode<int> *root = new TreeNode<int>(3);
  root->left = new TreeNode<int>(9);
  root->right = new TreeNode<int>(20);

  root->right->left = new TreeNode<int>(15);
  root->right->right = new TreeNode<int>(7);

  vector<double> result = calculateAvg(root);

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }

  return 0;
}