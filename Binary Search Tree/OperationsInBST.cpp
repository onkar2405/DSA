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

bool searchInBST(Node *root, int num)
{
  if (root == NULL)
  {
    return false;
  }

  if (root->val == num)
  {
    return true;
  }

  if (num > root->val)
  {
    return searchInBST(root->right, num);
  }

  return searchInBST(root->left, num);
}

Node *deleteNode(Node *root)
{
  if (root == NULL)
    return NULL;

  if (root->left == NULL)
  {
    Node *temp = root->right;
    delete root;
    return temp;
  }

  if (root->right == NULL)
  {
    Node *temp = root->left;
    delete root;
    return temp;
  }

  Node *succParent = root;
  Node *succ = root->right;

  // Find in-order successor (smallest in the right subtree)
  while (succ->left != NULL)
  {
    succParent = succ;
    succ = succ->left;
  }

  // Copy the inorder successor's content to this node
  root->val = succ->val;

  // Delete the inorder successor
  if (succParent->left == succ)
  {
    succParent->left = succ->right;
  }
  else
  {
    succParent->right = succ->right;
  }

  delete succ;
  return root;
}

void printInOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  printInOrder(root->left);
  cout << root->val << " ";
  printInOrder(root->right);
}

Node *deleteBST(Node *root, int val)
{
  if (root == NULL)
  {
    return NULL;
  }

  if (val < root->val)
  {
    root->left = deleteBST(root->left, val);
  }
  else if (val > root->val)
  {
    root->right = deleteBST(root->right, val);
  }
  else
  {
    root = deleteNode(root);
  }

  return root;
}

Node *insertInBSTRecursive(Node *root, int val)
{
  if (root == NULL)
  {
    return new Node(val);
  }

  if (root->val < val)
  {
    root->right = insertInBSTRecursive(root->right, val);
  }
  else if (root->val > val)
  {
    root->left = insertInBSTRecursive(root->left, val);
  }

  return root;
}

int main()
{

  Node *root = new Node(15);
  Node *node1 = new Node(5);
  Node *node2 = new Node(20);
  Node *node3 = new Node(18);
  Node *node4 = new Node(80);
  Node *node5 = new Node(16);
  Node *node6 = new Node(24);

  root->left = node1;
  root->right = node2;
  node2->left = node3;
  node2->right = node4;
  node3->left = node5;
  node4->left = node6;

  // cout << searchInBST(root, 24) << "\n";
  // cout << searchInBST(root, 16);

  Node *rootNew = insertInBSTRecursive(root, 10);

  printInOrder(rootNew);
  cout << "\n";
  printInOrder(deleteBST(rootNew, 20));
  return 0;
}
