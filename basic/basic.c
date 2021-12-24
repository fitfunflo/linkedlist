#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int data[3][2] = { {1, 1000}, {2, 1001}, {3, 1002} };

typedef struct Node {
  unsigned int id;
  int data;
  struct Node * next;
} Node;


/*
 * Build linked list
 */
Node * build(Node * head, int data[][2], unsigned int rows) {
  for (unsigned int i = 0; i < rows; i++) {
    // Create node { id, data, next }
    Node node = { data[i][0], data[i][1], head };
    head = malloc(sizeof(Node));
    *head = node;
  }

  return head;
}

/*
 * Delete linked list
 */
void delete(Node * head) {
  while(head) {
    Node * next = head->next;
    free(head);
    head = next;
  }
}

int main() {
  Node * head = NULL;

  head = build(head, data, 3);
  delete(head);

  return 0;
}
