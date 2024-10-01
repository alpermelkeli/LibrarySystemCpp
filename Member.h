#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include "Book.h"

class Member{


    private:
        std::string name;

        std::string id;

        std::vector<Book*> borrowedBooks;        


    public: 
        
        Member(std::string& name, std::string& id);
        
        ~Member();

        std::string getName() const;

        std::string getId() const;

        std::vector<Book*> getBorrowedBooks() const;

        void addBook(Book* book);

        void removeBook(const Book* book);

        friend std::ostream& operator<<(std::ostream& os, const Member& member);

};

#endif