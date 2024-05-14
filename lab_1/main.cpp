#include <iostream>
#include <cstring>
#include "Book.h"

int main()
{
    char* name_test = new char[] {"Mathbook"};
    char* author_test = new char[] {"Merzlyak"};
    char* name_to_set = new char[] {"C++ for beginers"};
    char* author_to_set = new char[] {"Tolik"};

    Book a; 
    Book b(name_test, author_test, 50.1f);
    Book c = b;

    showBook(a);
    showBook(b);

    c.setName(name_to_set);
    c.setAuthor(author_to_set);
    c.setPrice(100.25235f);

    showBook(c);

    Book d = noName(a);

    showBook(d);

    Book library[3] = {Book(strdup("Name #1"), strdup("Author #1"), 1.1), 
                       Book(strdup("Name #2"), strdup("Author #2"), 2.2), 
                       Book(strdup("Name #3"), strdup("Author #3"), 3.3)
    };
    
    for (int i = 0; i < 3; i++)
        showBook(library[i]);

    char *name_ptr_1 = new char[]{"Name #1 ptr"};
    char *name_ptr_2 = new char[]{"Name #2 ptr"};
    char *name_ptr_3 = new char[]{"Name #3 ptr"};

    char *author_ptr_1 = new char[]{"Author #1 ptr"};
    char *author_ptr_2 = new char[]{"Author #2 ptr"};
    char *author_ptr_3 = new char[]{"Author #3 ptr"};
    
    Book* book_ptr = new Book[3];

    book_ptr[0].set(name_ptr_1, author_ptr_1, 4.4);
    book_ptr[1].set(name_ptr_2, author_ptr_2, 4.4);
    book_ptr[2].set(name_ptr_3, author_ptr_3, 4.4);

    for (int i = 0; i < 3; i++)
        showBook(book_ptr[i]);

    delete[] book_ptr;

    void (Book::*pf)();
    pf = &Book::show;

    (a.*pf)();

    return 0;
}