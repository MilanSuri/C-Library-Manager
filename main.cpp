//
//  main.cpp
//  LibraryManager
//
//  Created by Milan Suri on 4/25/25.
//

#include <iostream>
#include "library.hpp"
#include <vector>
#include <string>



int main() {
    int decision;
    bool session = true;
    Library library;
    
    std::cout << "Welcome to a library management system. \n";

    while (session == true) {
        std::cout << "Press [0] to End Session \n";
        std::cout << "Press [1] to Add a Book \n";
        std::cout << "Press [2] to Remove a Book \n";
        std::cout << "Press [3] to List all Books \n";
        std::cout << "Press [4] to Register a User \n";
        std::cout << "Press [5] to Remove a User \n";
        std::cout << "Press [6] to List all Users \n";
        std::cout << "Press [7] to Check out a Book \n";
        std::cout << "Press [8] to Return a Book \n";
        std::cin >> decision;
        
        switch (decision) {
            case 0: {
                std::cout << "Goodbye \n";
                session = false;
                break;
            }
            case 1: {
                std::string title, author;
                int id;
                bool available;
                
                std::cout << "Enter book title \n";
                std::cin.ignore();
                getline(std::cin, title);
                
                std::cout << "Enter author \n";
                
                getline(std::cin, author);
                
                bool idExists = true;
                   while (idExists) {
                       std::cout << "Enter id \n";
                       std::cin >> id;
                       
                       if (library.bookIdExists(id))  {
                           std::cout << "Error: Book ID already exists. Please try a different ID. \n";
                       } else {
                           idExists = false;
                       }
                   }
                
                std::cout << "Is the book available? (1 for yes, 0 for no) \n";
                std::cin >> available;
                
                Book newBook (author, title, id, available);
                library.addBook (newBook);
                break;
            }
                
            case 2: {
                int bookId;
                std::cout << "Enter the id of the book you would like to remove \n";
                std::cin >> bookId;
                library.removeBook(bookId);
                break;
            }
                
            case 3: {
                library.listBooks();
                break;
            }
                
            case 4: {
                std::string username;
                int userId;
                
                std::cout << "Input username \n";
                std::cin.ignore();
                getline(std::cin, username);
                
                bool userIdExists = true;
                   while (userIdExists) {
                       std::cout << "Enter user id \n";
                       std::cin >> userId;
                       
                       if (library.userIdExists(userId))  {
                           std::cout << "Error: User ID already exists. Please try a different ID. \n";
                       } else {
                           userIdExists = false;
                       }
                   }
                
                User newUser (userId, username);
                library.addUser(newUser);
                std::cout << "User registered successfully.\n";
                break;
            }
            case 5: {
                int userId;
                std::cout << "Enter the id of the user you would like to remove \n";
                std::cin >> userId;
                library.removeUser(userId);
                break;
            }
            case 6: {
                library.listUsers();
                break;
            }
            case 7: {
                int bookId;
                int userId;
                std::cout << "Enter the id of the user. \n";
                std::cin >> userId;
                
                std::cout << "Enter book id \n";
                std::cin >> bookId;
                library.checkOutBook(userId, bookId);
                break;
            }
            case 8: {
                int bookId;
                std::cout << "Input the id of the book you are returning";
                std::cin >> bookId;
                library.returnBook(bookId);
                break;
            }
            default: {
                std::cout << "Error! Please try again \n";
            }
        }
    }
}
