#ifndef BOOKH
#define BOOKH 

class Book
{
private:
    char *name;
    char *author;
    float price;

public:
    Book();
    Book(char *_name, char *_author, float _price);
    Book(Book &book);
    void setName(char *_name);
    void setAuthor(char *_author);
    void setPrice(float price);
    void set(char* _name, char* _author, float _price);
    char *getName() { return name; };
    char *getAuthor() { return author; };
    float getPrice() { return price; };
    void show();
    ~Book();
};

void showBook(Book book);
Book noName(Book& book);

#endif