#include "Member.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

Member::Member(std::string& name, std::string& id):name(name), id(id){
    
}

std::string Member::getName() const{
    return name;
}

std::string Member::getId() const{
    return id;
}

std::vector<Book*> Member::getBorrowedBooks() const{
    return borrowedBooks;
}

Member::~Member() {
    for (Book* book : borrowedBooks) {
        book->returnBook();
    }
    borrowedBooks.clear();
}

std::ostream& operator<<(std::ostream& os, const Member& member) {
    os << "Member Name: " << member.getName() << "\n";
    os << "Member ID: " << member.getId() << "\n";
    os << "Borrowed Books:\n";

    for (const auto& book : (member.getBorrowedBooks())) {
        (*book).display(); 
    }

    return os;
}

void Member::addBook(Book* book){
    borrowedBooks.push_back(book);
}

void Member::removeBook(const Book* book){
    
    auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), book);
    
    if (it != borrowedBooks.end()) {
        borrowedBooks.erase(it);
    }
}
