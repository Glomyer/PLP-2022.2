#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *create_node(int val) {
  struct TreeNode *node = malloc(sizeof(struct TreeNode));
  node->val = val;
  node->left = NULL;
  node->right = NULL;
  return node;
}

struct TreeNode *insert(struct TreeNode *root, int val) {
  if (!root) return create_node(val);
  if (val < root->val) {
    root->left = insert(root->left, val);
  } else if (val > root->val) {
    root->right = insert(root->right, val);
  } else {
    return root;
  }
  return root;
}

int search(struct TreeNode *root, int val) {
  if (!root) return 0;
  if (root->val == val) return 1;
  if (val < root->val) {
    return search(root->left, val);
  } else {
    return search(root->right, val);
  }
}

void inorder(struct TreeNode *root) {
  if (!root) return;
  inorder(root->left);
  printf("%d ", root->val);
  inorder(root->right);
}

void preorder(struct TreeNode *root) {
  if (!root) return;
  printf("%d ", root->val);
  preorder(root->left);
  preorder(root->right);
}

void postorder(struct TreeNode *root) {
  if (!root) return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->val);
}

int main() {
  struct TreeNode *root = NULL;
  root = insert(root, 5);
  insert(root, 3);
  insert(root, 2);
  insert(root, 4);
  insert(root, 7);
  insert(root, 6);
  insert(root, 8);
  printf("Inorder: ");
  inorder(root);
  printf("\n");
  printf("Preorder: ");
  preorder(root);
  printf("\n");
  printf("Postorder: ");
  postorder(root);
  printf("\n");
  printf("Search 3: %d\n", search(root, 3));
  printf("Search 9: %d\n", search(root, 9));
  return 0;
}
