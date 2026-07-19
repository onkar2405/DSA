#ifndef TREENODE_H
#define TREENODE_H

template <typename T>
struct TreeNode
{
  T val;
  TreeNode<T> *left;
  TreeNode<T> *right;

  TreeNode(const T &value = T{}, TreeNode<T> *l = nullptr, TreeNode<T> *r = nullptr)
      : val(value), left(l), right(r) {}
};

#endif
