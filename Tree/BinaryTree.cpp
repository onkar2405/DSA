#include <iostream>
using namespace std;

struct Node
{
  int key;
  Node *left = NULL;
  Node *right = NULL;

  Node(int val)
  {
    key = val;
  }
};

void inOrder(Node *root)
{
  if (root != NULL)
  {
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
  }
}

void preOrder(Node *root)
{
  if (root != NULL)
  {
    cout << root->key << " ";
    preOrder(root->left);
    preOrder(root->right);
  }
}

void postOrder(Node *root)
{
  if (root != NULL)
  {
    postOrder(root->left);
    postOrder(root->right);
    cout << root->key << " ";
  }
}

int main()
{
  Node *root = new Node(5);
  root->left = new Node(10);
  root->right = new Node(20);
  root->left->left = new Node(40);

  inOrder(root);
  cout << "\n";
  preOrder(root);
  cout << "\n";
  postOrder(root);
  return 0;
}