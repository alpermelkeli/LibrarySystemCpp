#include "Library.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


Library::Library(){
    books = new std::vector<Book*>;
    members = new std::vector<Member*>;
}

void Library::displayMembers() const{
    for(auto const& member: *members){
        std::cout << member;
    }
}

Library::~Library() {
    for (auto& book : *books) {
        delete book;  // Free each Book*
    }
    for (auto& member : *members){
        delete member; //Free each Member*
    }
    delete books;  // Free the vector itself
    delete members; // Free the member itself
}
        
void Library::displayBooks() const {
    for (const auto& book : *books) {  
        book->display();           
    }
}


void Library::borrowBook(std::string& memberId, std::string& ISBN){
    auto memberIt = std::find_if(members->begin(), members->end(),
            [&memberId](const Member& member) {
                return member.getId() == memberId;
            });    

    if (memberIt == members->end()) {
        std::cout << "Member with ID " << memberId << " not found!" << std::endl;
        return;
    }

    auto bookIt = std::find_if(books->begin(), books->end(),
    [&ISBN](const Book* book) {
        return book->getISBN() == ISBN;
    });

    if (bookIt == books->end()) {
        std::cout << "Book with ISBN " << ISBN << " not found!" << std::endl;
        return;
    }

    if(!((*bookIt)->getIsBorrow())){
        (*memberIt)->addBook(*bookIt); 
        (*bookIt)->borrowBook(); 
        std::cout << "Book borrowed successfully!" << std::endl;
    }
    else{
        std::cout << "This book borrowed before!" << std::endl;
    }
    


}

void Library::returnBook(std::string& ISBN, std::string& memberId){
    auto memberIt = std::find_if(members->begin(), members->end(),
            [&memberId](const Member& member) {
                return member.getId() == memberId;
            });    

    if (memberIt == members->end()) {
        std::cout << "Member with ID " << memberId << " not found!" << std::endl;
        return;
    }

    auto bookIt = std::find_if(books->begin(), books->end(),
    [&ISBN](const Book* book) {
        return book->getISBN() == ISBN;
    });

    if (bookIt == books->end()) {
        std::cout << "Book with ISBN " << ISBN << " not found!" << std::endl;
        return;
    }
    
    (*memberIt)->removeBook(*bookIt);


    (*bookIt)->returnBook();

    std::cout << "Book returned successfully!" << std::endl;

}

void Library::addBook(std::string& ISBN, std::string& author, std::string& title){
    Book* newBook = new Book(ISBN, author, title);
    books->push_back(newBook);
}

void Library::removeBook(std::string& ISBN){
    auto bookIt = std::find_if(books->begin(), books->end(),
    [&ISBN](const Book* book) {
        return book->getISBN() == ISBN;
    });

    if (bookIt == books->end()) {
        std::cout << "Book with ISBN " << ISBN << " not found!" << std::endl;
        return;
    }
    else{
        books->erase(bookIt);
        delete *bookIt;
        std::cout << "Book with ISBN " << ISBN << " has been removed." << std::endl;
    }
}

void Library::addMember(std::string& name, std::string& id){
    Member* member = new Member(name, id);
    members->push_back(member);
    std::cout << "Member added! " << std::endl;
}

void Library::removeMember(std::string& id){
    auto memberIt = std::find_if(members->begin(), members->end(), [&id](const Member& member){
        return member.getId() == id;
    });

    if(memberIt == members->end()){
        std::cout << "Member with id " << id << " not found" << std::endl;
    }
    else{
        members->erase(memberIt);
        delete *memberIt;
    }

}