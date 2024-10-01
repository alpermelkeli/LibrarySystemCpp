#include <iostream>
#include "Library.h"

// Main function to display menu options to the user
void printMenu() {
    std::cout << "----------------------" << std::endl;
    std::cout << "Select your operation" << std::endl;
    std::cout << "1- Add Book" << std::endl;
    std::cout << "2- Remove Book" << std::endl;
    std::cout << "3- Display Members" << std::endl;
    std::cout << "4- Display Books" << std::endl;
    std::cout << "5- Add Member" << std::endl;  // New option
    std::cout << "6- Remove Member" << std::endl; 
    std::cout << "7- Borrow Book" << std::endl; // New option
    std::cout << "8- Return Book" << std::endl;
    std::cout << "9- Exit" << std::endl;
    std::cout << "----------------------" << std::endl;
}

int main() {
    Library lb;  // Declare the Library instance inside the main function

    while (true) {
        printMenu();  // Print the menu options

        int operation;

        std::cout << "Enter your choice: " << std::endl;

        std::cin >> operation;  // Take user input for the operation choice

        if (operation == 1) {  // Add a book
            std::string ISBN, author, title;
            std::cout << "Enter ISBN: ";
            std::cin >> ISBN;
            std::cout << "Enter author: ";
            std::cin >> author;
            std::cout << "Enter title: ";
            std::cin >> title;

            lb.addBook(ISBN, author, title);  
        }
        else if (operation == 2) {  
            std::string ISBN;
            std::cout << "Enter ISBN of book to remove: ";
            std::cin >> ISBN;

            lb.removeBook(ISBN); 
        }
        else if (operation == 3) {  
            lb.displayMembers();  
        }
        else if (operation == 4) {  
            lb.displayBooks();  
        }
        else if (operation == 5) {  // Add a member
            std::string name, id;
            std::cout << "Enter member name: ";
            std::cin >> name;
            std::cout << "Enter member ID: ";
            std::cin >> id;

            lb.addMember(name, id);  
        }
        else if (operation == 6) {  // Remove a member
            std::string id;
            std::cout << "Enter ID of member to remove: ";
            std::cin >> id;

            lb.removeMember(id); 
        }
        else if(operation == 7){
            std::string id;
            std:: string ISBN;
            std::cout << "Enter ID of user: ";
            std::cin >> id;
            std::cout << "Enter ISBN of book: ";
            std::cin >> ISBN;
            lb.borrowBook(id, ISBN);
        }
        else if (operation == 8){
            std::string id;
            std:: string ISBN;
            std::cout << "Enter ID of user: ";
            std::cin >> id;
            std::cout << "Enter ISBN of book: ";
            std::cin >> ISBN;

            lb.returnBook(ISBN, id);
        }

        else if (operation == 9) {  
            std::cout << "Exiting the program." << std::endl;
            break;
        }
        else {
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    }

    return 0;
}
