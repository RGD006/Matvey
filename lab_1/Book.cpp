#include "Book.h"
#include <cstring>
#include <iostream>

Book::Book()
{
    name = new char[]{"Kobzar"};
    author = new char[]{"Taras Shevchenko"};
    price = 20.5f;
    
    std::cout << "Constructor -> " << this << std::endl;
}

Book::Book(char *_name, char *_author, float _price)
{
    name = new char[strlen(_name)]; // виділяємо пам'ять для name через strlen()
    author = new char[strlen(_author)];

    std::strcpy(name, _name);
    std::strcpy(author, _author);

    price = _price;

    std::cout << "Constructor -> " << this << std::endl;
}

Book::Book(Book &book)
{
    name = new char[strlen(book.getName())];
    author = new char[strlen(book.getAuthor())];

    std::strcpy(name, book.getName());
    std::strcpy(author, book.getAuthor());

    price = book.getPrice();

    std::cout << "Constructor -> " << this << std::endl;
}

void Book::setName(char *_name)
{
    name = new char[strlen(_name)];
    std::strcpy(name, _name);
}

void Book::setAuthor(char *_author)
{
    author = new char[strlen(_author)];
    std::strcpy(author, _author);
}

void Book::setPrice(float _price)
{
    price = _price;
}

void Book::set(char *_name, char *_author, float _price)
{
    name = new char[strlen(_name)];
    author = new char[strlen(_author)];

    std::strcpy(name, _name);
    std::strcpy(author, _author);

    price = _price;
}

void Book::show()
{
    std::cout << name << " " << author << " " << price << std::endl;
}

Book::~Book()
{
    delete name;
    delete author;

    std::cout << "Destructor -> " << this << std::endl;
}

void showBook(Book book)
{
    book.show();
}

Book noName(Book &book)
{
    Book tmp(book);
    tmp.setName(strdup("noName"));
    return tmp;
}