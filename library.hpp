//
//  library.hpp
//  LibraryManager
//

#ifndef library_hpp
#define library_hpp

#include <stdio.h>

#endif /* library_hpp */

#include <iostream>
#include <string>
#include <vector>


class Book {
private:
    std::string author;
    std::string title;
    int id;
    bool available;
public:
    Book (std::string new_author, std::string new_title, int new_id, bool new_available);
    std::string get_author();
    std::string get_title();
    int get_id();
    bool get_availability();
    bool set_availability(bool availability);
    void displayInfo();
};

class User {
private:  
    int user_id;
    std::string username;
public:
    User (int new_user_id, std::string new_username);
    void displayUserInfo();
    int get_user_id();
    std::string get_username();
};

class Library {
private:
    
    std::vector<std::pair<int, int>> checkout;
    std::vector <Book> books;
    std::vector <User> users;
    
public:
  
    
    void addBook(const Book& newBook) {
        books.push_back(newBook);
    }
    
    void addUser(const User& newUser) {
        users.push_back(newUser);
    }
    
    void removeBook (int bookId) {
        for (auto i = books.begin(); i != books.end(); i++) {
            if (i -> get_id() == bookId) {
                books.erase(i);
                std::cout << "Book removed \n";
                return;
            }
        }
        std::cout << "Book not found \n";
    }
    
    void removeUser(int userId) {
        for (auto j = users.begin(); j != users.end();) {
            if (j->get_user_id() == userId) {
                j = users.erase(j);
                std::cout << "User removed \n";
                return;
            } else {
                ++j;
            }
        }
        std::cout << "User not found \n";
    }
    
    bool userIdExists(int userId) {
        for (auto& user : users) {
            if (user.get_user_id() == userId) {
                return true;
            }
        }
        return false;
    }
    
    bool bookIdExists(int bookId) {
        for (auto&book : books) {
            if (book.get_id() == bookId) {
                return true;
            }
        }
        return false;
    }
    
    void listBooks() {
            if (books.empty()) {
                std::cout << "No books available in the library.\n";
                return;
            }

            for (auto& book : books) {
                book.displayInfo();
            }
        }
    
    void listUsers() {
        if (users.empty()) {
            std::cout << "No users registered. \n";
            return;
        }
        
        for (auto& user : users) {
            user.displayUserInfo();
        }
    }
    
    void checkOutBook (int userId, int bookId) {
        if (!userIdExists(userId)) {
            std::cout << "User does not exist \n";
        }
        
        if (!bookIdExists(bookId)) {
            std::cout << "Book does not exist \n";
        }
        
        for (const auto& record : checkout) {
            if (record.second == bookId) {
                std::cout << "Sorry, this book is already checked out \n";
                return;
            }
        }
        
        checkout.push_back(std::make_pair(userId, bookId));
        
        for (auto &book : books) {
            if (book.get_id() == bookId) {
                book.set_availability(false);
                break;
            }
        }
        std::cout << "Book checked out successfully!\n";
    }
    
    void returnBook (int bookId) {
        for (auto k = checkout.begin(); k != checkout.end(); ++k) {
            if (k -> second == bookId) {
                checkout.erase(k);
                for (auto &book : books) {
                    if (book.get_id() == bookId) {
                        book.set_availability(true);
                        break;
                    }
                }
                std::cout << "Book returned";
                return;
            }
        }
        std::cout << "There was an error with the return";
    }
};
