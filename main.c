#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "node.h"

int main() {
  Book books[3] = {
    { 1, "Gone with the Wind", "A classic book.", 99, "Margaret Mitchell" },
    { 2, "The Sun Also Rises", "A classic book.", 100, "Ernest Hemmingway" },
    { 3, "The Iliad", "A classic book.", 101, "Homer" },
  };
  size_t book_size = sizeof(Book);
  Node * head = malloc(sizeof(Node) * 3);
  node_build(books, book_size, head, 3);
  node_all(head);
  free(head);
  return 0;
}
