typedef struct Node {
  Data data;
  struct Node * next;
  struct Node * previous;
} Node;

void node_build(void * data_array, size_t data_size, Node * head, unsigned int size) {
  Node * previous = NULL;
  for (unsigned int i = 0; i < size; i++) {
    Node node = { data_array + data_size * i, NULL, previous };
    Node * addr = head + i;
    *addr = node;
    previous = addr;
    if (node.previous) {
      (node.previous)->next = addr;
    }
  }
}

void node_print(Node * node) {
  printf("Data:\t\t%p\n", node->data);
  printf("ID:\t\t%s\n", ((Book*)(node->data))->title);
}

void node_all(Node * head) {
  while (head) {
    node_print(head);
    head = head->next;
  }
}
