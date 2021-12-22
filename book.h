#if !defined(_STDBOOL_H)
#include <stdbool.h>
#define _STDBOOL_H
#endif

#define LIMIT 1024

typedef struct Book {
  unsigned int id;
  char title[256];
  char author[256];
  char description[2048];
  unsigned int year;
} Book;

Book BOOK_COLLECTION[LIMIT];

unsigned int LAST_INSERT_ID = 0;

bool book_id_valid(unsigned int book_id) {
  return (book_id > 0 && book_id < LIMIT);
}

void book_print(Book book) {
  printf("ID:\t%d\t", book.id);
  printf("Title:\t%s\t", book.title);
  printf("Author:\t%s\t", book.author);
  printf("Description:\t%s\t", book.description);
  printf("Year:\t%d\n", book.year);
}

void book_insert(Book book) {
  if (LAST_INSERT_ID + 1 < LIMIT) {
    book.id = ++LAST_INSERT_ID;
    BOOK_COLLECTION[book.id] = book;
  }
}

Book book_select(unsigned int book_id) {
  if (book_id_valid(book_id)) {
    return BOOK_COLLECTION[book_id];
  }
  Book book_null = {0, "", "", "", 0};
  return book_null;
}

void book_update(Book book) {
  if (book_id_valid(book.id)) {
    BOOK_COLLECTION[book.id] = book;
  }
}

void book_delete(unsigned int book_id) {
  if (book_id_valid(book_id)) {
    Book book_null = {0, "", "", "", 0};
    BOOK_COLLECTION[book_id] = book_null;
  }
}
