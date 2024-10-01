#include "Book.h"
#include <iostream>

Book::Book(std::string& ISBN, std::string& author, std::string& title):ISBN(ISBN), author(author), title(title){
    isBorrow = false;
}

void Book::borrowBook(){
    if(!isBorrow){
        isBorrow = true;
        std::cout << "Book has been borrowed successfuly!" << std::endl;
    }
    else{
        std::cout << "This book has taken by other member." << std::endl;
    }

}
void Book::display() const{
    std::cout << "ISBN: " << getISBN() << std::endl
    << "Author: " << getAuthor() << std::endl 
    << "Title: " << getTitle() << std::endl
    << "Borrowed" << (getIsBorrow() ? "Yes" : "No") << std::endl;
}

void Book::returnBook(){
    if(isBorrow){
        isBorrow = false;
        std::cout << "Book has returned successfully!" << std::endl;
    }
    else{
        std::cout << "This book has not borrowed" << std::endl;
    }
}

bool Book::getIsBorrow() const{
    return isBorrow;
}


std::string Book::getISBN() const{
    return ISBN;
}

std::string Book::getAuthor() const{
    return author;
}

std::string Book::getTitle() const{
    return title;
}

bool Book::operator==(const Book& other) const{
    return this->getISBN() == other.getISBN(); 
}