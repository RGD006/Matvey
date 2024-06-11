#include <iostream>
#include <cstring>
#include <vector>

class IMubageProduct // паперовий виріб (I - інтерфейс)
{
protected:
    char* name;
    char* author;
    float price;
public:
    virtual void printBook() const;
    virtual char* getName() const { return name; }
    IMubageProduct(const char *_name, const char *_author, const float &_price);
};

IMubageProduct::IMubageProduct(const char *_name, const char *_author, const float &_price)
    : price(_price)
{
    if (_name != nullptr && _author != nullptr)
    {
        name = new char[strlen(_name)];
        author = new char[strlen(_author)];
        strcpy(name, _name);
        strcpy(author, _author);
    }
}

void IMubageProduct::printBook() const
{
    std::cout << "name: " << name << " | "
              << "author: " << author << " | "
              << "price: " << price << std::endl;
}

class Book : public IMubageProduct
{
protected:
    char* summary;
public:
    Book(const char *_name, const char *_author, const float &price, const char* _summary);
    void printBook() const override;
};

Book::Book(const char *_name, const char *_author, const float &price, const char *_summary)
    : IMubageProduct(_name, _author, price)
{
    if (_summary != nullptr)
    {
        summary = new char[strlen(_summary)];
        strcpy(summary, _summary);
    }
}

void Book::printBook() const
{
    std::cout << "Book: ";
    std::cout << "name: " << name << " | "
              << "author: " << author << " | "
              << "price: " << price << " | "
              << "summary: " << summary << std::endl;
}

class FantasyBook : public Book
{
private:
    char* genre;
public:
    FantasyBook(const char* _name, const char* _author, const float& price, const char* _summary);
    void printBook() const final;
};

FantasyBook::FantasyBook(const char *_name, const char *_author, const float &_price, const char *_summary)
    : Book(_name, _author, _price, _summary)
{
    genre = strdup("Fantasy");
}

void FantasyBook::printBook() const
{
    std::cout << "Book: " << " ";
    std::cout << "Genre: " << genre << " | ";
    std::cout << "name: " << name << " | "
              << "author: " << author << " | "
              << "price: " << price << " | "
              << "summary: " << summary << std::endl;
}

class BookSciFi : public Book
{
private:
    char* genre;
public:
    BookSciFi(const char* _name, const char* _author, const float &_price, const char* _summary);
    void printBook() const final;
};

BookSciFi::BookSciFi(const char *_name, const char *_author, const float &_price, const char *_summary)
    : Book(_name, _author, _price, _summary)
{
    genre = strdup("Sci-Fi");
}

void BookSciFi::printBook() const
{
    std::cout << "Book: " << " ";
    std::cout << "Genre: " << genre << " | ";
    std::cout << "name: " << name << " | "
              << "author: " << author << " | "
              << "price: " << price << " | "
              << "summary: " << summary << std::endl;
}

class BookRomance : public Book
{
private:
    char* genre;
public:
    BookRomance(const char* _name, const char* _author, const float &_price, const char* _summary);
    void printBook() const final;
};

BookRomance::BookRomance(const char *_name, const char *_author, const float &_price, const char *_summary)
    : Book(_name, _author, _price, _summary)
{
    genre = strdup("Romance");
}

void BookRomance::printBook() const
{
    std::cout << "Book: " << " ";
    std::cout << "Genre: " << genre << " | ";
    std::cout << "name: " << name << " | "
              << "author: " << author << " | "
              << "price: " << price << " | "
              << "summary: " << summary << std::endl;
}

class Manual : public IMubageProduct
{
protected:
    char* type;
    size_t pages;
public:
    Manual(const char* _name, const char* _author, const float& _price, const char* _type, size_t _pages);
    void printBook() const override;
};

Manual::Manual(const char *_name, const char *_author, const float &_price, const char *_type, size_t _pages)
    : IMubageProduct(_name, _author, _price)
{
    if (_type != nullptr)
    {
        type = new char[strlen(_type)];
        strcpy(type, _type);
    }
}

void Manual::printBook() const
{
    std::cout << "Manual: " << " ";
    std::cout << "name: " << name << " | "
              << "author: " << author << " | "
              << "price: " << price << " | "
              << "type: " << type << " | "
              << "pages: " << pages << std::endl;
}

class ServiceManual : public Manual
{
private:
    char* information;
public:
    ServiceManual(const char* _name,
                  const char* _author,
                  const float &_price,
                  const char* type,
                  size_t _pages,
                  const char* _information);
    void printBook() const final;
};

ServiceManual::ServiceManual(const char *_name,
                             const char *_author,
                             const float &_price,
                             const char *type,
                             size_t _pages, const char *_information)
                             : Manual(_name, _author, _price, type, _pages)
{
    if (_information != nullptr)
    {
        information = new char[strlen(_information)];
        strcpy(information, _information);
    }
}

void ServiceManual::printBook() const
{
    std::cout << "Manual: " << " ";
    std::cout << "name: " << name << " | "
              << "author: " << author << " | "
              << "price: " << price << " | "
              << "type: " << type << " | "
              << "pages: " << pages <<  " | "
              << "information: " << information << std::endl;
}

class UserManual : public Manual
{
private:
    char* information;
public:
    UserManual(const char* _name,
               const char* _author,
               const float &_price,
               const char* _type,
               size_t _pages,
               const char* _information);
    void printBook() const final;
};

UserManual::UserManual(const char *_name,
                       const char *_author,
                       const float &_price,
                       const char *_type,
                       size_t _pages,
                       const char *_information)
                       : Manual(_name, _author, _price, _type, _pages)
{
    if (_information != nullptr)
    {
        information = new char[strlen(_information)];
        strcpy(information, _information);
    }
}

void UserManual::printBook() const
{
    std::cout << "Manual: " << " ";
    std::cout << "name: " << name << " | "
              << "author: " << author << " | "
              << "price: " << price << " | "
              << "type: " << type << " | "
              << "pages: " << pages <<  " | "
              << "information: " << information << std::endl;
}

class Library
{
private:
    std::vector<IMubageProduct*> products;
public:
    Library() = default;
    void addProduct(IMubageProduct* product);
    void printProducts();
    IMubageProduct* searchProductByName(const char* name);
};

void Library::addProduct(IMubageProduct *product)
{
    products.push_back(product);
}

void Library::printProducts()
{
    for (const auto& el : products)
    {
        el->printBook();
    }
    std::cout << std::endl;
}

IMubageProduct* Library::searchProductByName(const char *name)
{
    for (const auto& el : products)
    {
        if (strcmp(el->getName(), name) == 0)
        {
            return el;
        }
    }
    return nullptr;
}

int main()
{
    Library library;
    library.addProduct(new FantasyBook("Test1", "Author1", 10.5f, "text1"));
    library.addProduct(new BookSciFi("Test2", "Author2", 20.6f, "text2"));
    library.addProduct(new BookRomance("Test3", "Author3", 30.7f, "text3"));
    library.addProduct(new BookRomance("Test4", "Author4", 40.7f, "Ya ystal pisat testi :("));
    library.addProduct(new Book("Test5", "Author5", 50.8f, "sgsgg"));
    library.addProduct(new Manual("Test6", "Author6", 60.9f, "gsgsgags", 200));
    library.addProduct(new ServiceManual("Test7", "Author7", 70.f, "sgsagsg", 100, "sgasgsg"));
    library.addProduct(new UserManual("Test8", "Author8", 80.1f, "gsdgsgg", 300, "tsssssss"));

    library.printProducts();

    IMubageProduct* found = library.searchProductByName("Test5");

    if (found != nullptr)
    {
        std::cout << "Founded!" << std::endl;
        found->printBook();
    }
    else
    {
        std::cout << "Didn't find" << std::endl;
    }

    IMubageProduct* didnt_find = library.searchProductByName("Test9");
    if (didnt_find != nullptr)
    {
        std::cout << "Founded!" << std::endl;
        found->printBook();
    }
    else
    {
        std::cout << "Didn't find" << std::endl;
    }

    return 0;
}
