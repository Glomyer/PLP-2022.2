#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
  int data[MAX_SIZE];
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

int peek(struct Stack *s) {
  return s->data[s->top];
}

void push(struct Stack *s, int x) {
  if (isFull(s)) {
    printf("Error: stack is full\n");
    return;
  }
  s->data[++s->top] = x;
}

int pop(struct Stack *s) {
  if (isEmpty(s)) {
    printf("Error: stack is empty\n");
    return -1;
  }
  return s->data[s->top--];
}

int main() {
  struct Stack s;
  init(&s);
  push(&s, 1);
  push(&s, 2);
  push(&s, 3);
  printf("%d\n", pop(&s));
  printf("%d\n", pop(&s));
  printf("%d\n", pop(&s));
  return 0;
}
