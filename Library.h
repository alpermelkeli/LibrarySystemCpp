#ifndef LIBRARY_H
#define LIBRARY_H

#include "Member.h"
#include "Book.h"
#include <string>
#include <vector>
#include <map>

class Library{

    private:
        std::vector<Book*>* books;
        std::vector<Member*>* members;
    
    public:

        Library();
        
        ~Library(); //Destructor

        void displayMembers() const;
        
        void displayBooks() const;

        void addMember(std::string& name, std::string& id);

        void removeMember(std::string& id);

        void borrowBook(std::string& memberId, std::string& ISBN);

        void returnBook(std::string& ISBN, std::string& memberId);

        void addBook(std::string& ISBN, std::string& author, std::string& title);

        void removeBook(std::string& ISBN);


};
#endif