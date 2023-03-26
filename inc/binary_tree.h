#pragma once

// https://www.geeksforgeeks.org/introduction-to-binary-tree-data-structure-and-algorithm-tutorials/

template <typename T> struct TreeNode {
  T value;
  TreeNode<T> *left;
  TreeNode<T> *right;

  // Parameterised Constructor
  TreeNode(T value, TreeNode *left = nullptr, TreeNode *right = nullptr) {
    this->value = value;
    this->right = right;
    this->left = left;
  }
};

template <typename T> class BinaryTree {
public:
  TreeNode<T> *root;

  // Default constructor
  BinaryTree() { root = nullptr; }

  // Adds new node to tree if smaller than actual then left
  void addNode(T newElement);

  // Prints node's values in the given order: current->left->right
  void preOrderTraversal(TreeNode<T> *focusNode);

  // Prints node's values in the given order: left->current->right
  void inOrderTraversal(TreeNode<T> *focusNode);

  // Prints node's values in the given order: left->right->current
  void postOrderTraversal(TreeNode<T> *focusNode);
};

// addNode - Adds new node to tree if smaller than actual then left
template <typename T> void BinaryTree<T>::addNode(T newElement) {
  TreeNode<T> *newNode = new TreeNode<T>(newElement);

  if (root == nullptr) {
    root = newNode;
  } else {
    TreeNode<T> *focusNode = root;
    TreeNode<T> *parent;

    while (true) {
      parent = focusNode;

      if (newElement < focusNode->value) {
        focusNode = focusNode->left;
        if (focusNode == nullptr) {
          parent->left = newNode;
          return;
        }
      } else {
        focusNode = focusNode->right;
        if (focusNode == nullptr) {
          parent->right = newNode;
          return;
        }
      }
    }
  }
}

// Prints node's values in the given order: current->left->right
template <typename T>
void BinaryTree<T>::preOrderTraversal(TreeNode<T> *focusNode) {
  if (focusNode != nullptr) {
    std::cout << focusNode->value << " ";
    preOrderTraversal(focusNode->left);
    preOrderTraversal(focusNode->right);
  }
}

// Prints node's values in the given order: left->current->right
template <typename T>
void BinaryTree<T>::inOrderTraversal(TreeNode<T> *focusNode) {
  if (focusNode != nullptr) {
    preOrderTraversal(focusNode->left);
    std::cout << focusNode->value << " ";
    preOrderTraversal(focusNode->right);
  }
}

// Prints node's values in the given order: left->right->current
template <typename T>
void BinaryTree<T>::postOrderTraversal(TreeNode<T> *focusNode) {
  if (focusNode != nullptr) {
    preOrderTraversal(focusNode->left);
    preOrderTraversal(focusNode->right);
    std::cout << focusNode->value << " ";
  }
}
