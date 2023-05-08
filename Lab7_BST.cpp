#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal function
void traverseInOrder(struct node *root) {
  if (root != NULL) {
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
  }
}

// Insert a node function
struct node *insertNode(struct node *node, int key) {
  // If the tree is empty, create a new node
  
  if (node == NULL) {
    struct node *newNode = new struct node();
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
  }

  // Otherwise, recur down the tree and then insert the key
  
  if (key <= node->key) {
    node->left = insertNode(node->left, key);
  } else if (key > node->key) {
    node->right = insertNode(node->right, key);
  }

  // Return the same unchanged node pointer to the main function
  return node;
}

// Deleting a node from the tree

struct node *deleteNode(struct node *root, int key) {
  // Base case
  if (root == NULL) {
    return root;
  }

  // Recur down the tree
  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  } else {
    
    // Node with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      delete root;
      return temp;
      
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      delete root;
      return temp;
    }

    // For a node with 2 children
    
    struct node *temp = root->right;
    while (temp->left != NULL) {
      temp = temp->left;
    }
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }

  return root;    //return root
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
  
  return 0;
}
