#ifndef BOOK_H   // If BOOK_H is not defined
#define BOOK_H   // Define BOOK_H
#include <string>

class Book{

    private:
        std::string ISBN;
        std::string author;
        std::string title;
        bool isBorrow;

    public:

        Book(std::string& ISBN, std::string& author, std::string& title);

        std::string getISBN() const;

        std::string getAuthor() const;

        std::string getTitle() const;

        bool getIsBorrow() const;

        void borrowBook();

        void returnBook();

        void display() const;

        bool operator==(const Book& rhs) const;


};

#endif