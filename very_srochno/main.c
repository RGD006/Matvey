#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

typedef struct
{
    char* name;
    char* author;
    float price;
    int pages;
} Book;

void setName(Book* s, const char* name)
{
    s->name = (char*)malloc(strlen(name) + 1);
    if (s->name != NULL)
    {
        strcpy(s->name, name);
    }
}

void setAuthor(Book* s, const char* author)
{
    s->author = (char*)malloc(strlen(author) + 1);
    if (s->author != NULL)
    {
        strcpy(s->author, author);
    }
}

void setPrice(Book* s, const float price)
{
    s->price = price;
}

void setPages(Book* s, const int pages)
{
    s->pages = pages;
}

void initBook(Book* s, const char* name, const char* author, const float price, const int pages)
{
    setName(s, name);
    setAuthor(s, author);
    setPrice(s, price);
    setPages(s, pages);
}

void printBook(const Book* s)
{
    if (s->name != NULL && s->author != NULL)
    {
        printf("Назва: %s автор: %s ціна: %.2f сторінок: %d \n", s->name, s->author, s->price, s->pages);
    }
    else
    {
        printf("Ім'я або автор не заповнений в цій структурі\n");
        exit(1);
    }
}

#define FLOAT_SIZE_STR 10
#define INT_SIZE_STR 10

char* returnBookStr(const Book* s)
{
    char price_str[FLOAT_SIZE_STR];
    char pages_str[INT_SIZE_STR];
    sprintf(price_str, "%.2f", s->price);
    sprintf(pages_str, "%d", s->pages);
    if (s->name != NULL && s->author != NULL)
    {
        size_t size_str = strlen(s->name) + strlen(s->author) + FLOAT_SIZE_STR + INT_SIZE_STR + 34; // 34 for fixed text
        char* result = (char*)malloc(size_str + 1);
        if (result != NULL)
        {
            snprintf(result, size_str + 1, "Назва: %s автор: %s ціна: %s сторінок: %s", s->name, s->author, price_str, pages_str);
        }
        return result;
    }
    else
    {
        printf("Ім'я або автор не заповнений в цій структурі\n");
        exit(1);
    }
}

void freeBook(Book* s)
{
    if (s != NULL)
    {
        free(s->name);
        free(s->author);
        free(s);
    }
}

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Book* book = (Book*)malloc(sizeof(Book));
    char* name = _strdup("Матвєй");
    char* author = _strdup("Міняй значення");

    initBook(book, name, author, 20.5f, 100);
    printBook(book);
    char* str_book = returnBookStr(book);
    if (str_book != NULL)
    {
        printf("returned book: %s\n", str_book);
        free(str_book);
    }

    freeBook(book);
    free(name);
    free(author);
    
    return 0;
}
