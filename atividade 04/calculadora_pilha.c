#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

struct Stack {
  double data[MAX_SIZE];
  int top;
};

void init(struct Stack *s) {
  s->top = -1;
}

int isEmpty(struct Stack *s) {
  if (s->top == -1) return 1;
  return 0;
}

int isFull(struct Stack *s) {
  if (s->top == MAX_SIZE - 1) return 1;
  return 0;
}

double peek(struct Stack *s) {
  return s->data[s->top];
}

void push(struct Stack *s, double x) {
  if (isFull(s)) {
    printf("Error: stack is full\n");
    return;
  }
  s->data[++s->top] = x;
}

double pop(struct Stack *s) {
  if (isEmpty(s)) {
    printf("Error: stack is empty\n");
    return -1;
  }
  return s->data[s->top--];
}

double eval(char *exp) {
  struct Stack s;
  init(&s);
  int i = 0;
  while (exp[i]) {
    if (isspace(exp[i])) {
      i++;
      continue;
    }
    if (isdigit(exp[i])) {
      double num = 0;
      while (isdigit(exp[i])) {
        num = num * 10 + (exp[i] - '0');
        i++;
      }
      if (exp[i] == '.') {
        i++;
        double k = 0.1;
        while (isdigit(exp[i])) {
          num += (exp[i] - '0') * k;
          k *= 0.1;
          i++;
        }
      }
      push(&s, num);
      continue;
    }
    double num2 = pop(&s);
    double num1 = pop(&s);
    if (exp[i] == '+') {
      push(&s, num1 + num2);
    } else if (exp[i] == '-') {
      push(&s, num1 - num2);
    } else if (exp[i] == '*') {
      push(&s, num1 * num2);
    } else if (exp[i] == '/') {
      push(&s, num1 / num2);
    } else {
      printf("Error: invalid operator\n");
      return -1;
    }
    i++;
  }
  return pop(&s);
}

int main() {
  char exp[MAX_SIZE];
  printf("Enter an expression: ");
  fgets(exp, MAX_SIZE, stdin);
  printf("Result: %lf\n", eval(exp));
  return 0;
}
