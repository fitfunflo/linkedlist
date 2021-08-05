#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../book.h"

void assert_same(Book book1, Book book2) {
  assert(strcmp(book1.title, book2.title) == 0);
  assert(strcmp(book1.author, book2.author) == 0);
  assert(strcmp(book1.description, book2.description) == 0);
  assert(book1.year == book2.year);
}

void test_book() {
  // Test Book data fields
  Book book = { 1, "Book Title", "Book Author", "Book Description", 1999 };
  assert(book.id == 1);
  assert(strcmp(book.title, "Book Title") == 0);
  assert(strcmp(book.author, "Book Author") == 0);
  assert(strcmp(book.description, "Book Description") == 0);
  assert(book.year == 1999);
}

void test_book_insert() {
  // Insert 1 book and assert last inserted book
  Book book = { 0, "Book Title 2", "Book Author 2", "Book Description 2", 2001 };
  book_insert(book);
  Book book_last_insert = BOOK_COLLECTION[LAST_INSERT_ID];
  assert(LAST_INSERT_ID == 1);
  assert_same(book, book_last_insert);

  // Insert another book and assert last inserted book
  book = (Book){ 0, "Book Title 3", "Book Author 3", "Book Description 3", 2003 };
  book_insert(book);
  book_last_insert = BOOK_COLLECTION[LAST_INSERT_ID];
  assert(LAST_INSERT_ID == 2);
  assert_same(book, book_last_insert);
}

void test_book_select() {
  // Initialize book, insert, select, then assert selected book
  Book book = { 0, "Book Title 4", "Book Author 4", "Book Description 4", 2005 };
  book_insert(book);
  Book book_selected = book_select(LAST_INSERT_ID);
  assert_same(book, book_selected);
}

void test_book_update() {
  // Initialize book, insert, and select
  Book book = { 0, "Book Title 5", "Book Author 5", "Book Description 5", 2007 };
  book_insert(book);
  book = book_select(LAST_INSERT_ID);

  // Update book fields
  strcpy(book.title, "Book Title 7");
  strcpy(book.author, "Book Author 7");
  strcpy(book.description, "Book Description 7");
  book.year = 2009;

  // Update
  book_update(book);

  // Select updated book
  Book book_updated = book_select(LAST_INSERT_ID);

  // Assert updated values
  assert_same(book, book_updated);
}

void test_book_delete() {
  // Initialize book
  Book book = { 0, "Book Title 8", "Book Author 8", "Book Description 8", 2011 };
  
  // Insert book
  book_insert(book);

  // Delete book
  book_delete(LAST_INSERT_ID);

  // Try to select deleted book
  Book book_deleted = book_select(LAST_INSERT_ID);

  // Assert
  Book book_null = {0, "", "", "", 0};
  assert_same(book_deleted, book_null);
}

int main() {
  test_book();
  test_book_insert();
  test_book_select();
  test_book_update();
  test_book_delete();
  return 0;
}
