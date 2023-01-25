#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct TreeNode {
  char *val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *create_node(char *val) {
  struct TreeNode *node = malloc(sizeof(struct TreeNode));
  node->val = val;
  node->left = NULL;
  node->right = NULL;
  return node;
}

double eval(struct TreeNode *root) {
  if (!root) return 0;
  if (!root->left && !root->right) {
    return atof(root->val);
  }
  double left = eval(root->left);
  double right = eval(root->right);
  if (strcmp(root->val, "+") == 0) {
    return left + right;
  } else if (strcmp(root->val, "-") == 0) {
    return left - right;
  } else if (strcmp(root->val, "*") == 0) {
    return left * right;
  } else if (strcmp(root->val, "/") == 0) {
    return left / right;
  }
  return 0;
}

struct TreeNode *parse_expr(char **p) {
  char *expr = *p;
  while (isspace(*expr)) expr++;
  if (isdigit(*expr)) {
    char *end;
    double val = strtod(expr, &end);
    char str[20];
    sprintf(str, "%.10g", val);
    *p = end;
    return create_node(strdup(str));
  }
  if (*expr == '(') {
    expr++;
    struct TreeNode *node = parse_sum(p);
    if (*expr == ')') {
      expr++;
    }
    *p = expr;
    return node;
  }
  return NULL;
}

struct TreeNode *parse_prod(char **p) {
  struct TreeNode *node = parse_expr(p);
  char *expr = *p;
  while (*expr == '*' || *expr == '/') {
    char op[2] = {*expr, '\0'};
    expr++;
    struct TreeNode *right = parse_expr(&expr);
    node = create_node(strdup(op));
    node->left = node;
    node->right = right;
  }
  *p = expr;
  return node;
}

struct TreeNode *parse_sum(char **p) {
  struct TreeNode *node = parse_prod(p);
  char *expr = *p;
  while (*expr == '+' || *expr == '-') {
    char op[2] = {*expr, '\0'};
    expr++;
    struct TreeNode *right = parse_prod(&expr);
    node = create_node(strdup(op));
    node->left = node;
    node->right = right;
  }
  *p = expr;
  return node;
}

int main() {
  char expr[100];
  printf("Enter an expression: ");
  fgets(expr, 100, stdin);
  char *p = expr;
  struct TreeNode *root = parse_sum(&p);
  printf("Result: %lf\n", eval(root));
  return 0;
}
