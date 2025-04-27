//
//  library.cpp
//  LibraryManager
//

#include "library.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <variant>



Book::Book(std::string new_author, std::string new_title, int new_id, bool new_available) {
    author = new_author;
    title = new_title;
    id = new_id;
    available = new_available;
}

std::string Book::get_title(){
    return title;
}

std::string Book::get_author(){
    return author;
}

int Book::get_id() {
    return id;
}

bool Book::get_availability() {
    return available;
}

bool Book::set_availability(bool availability)  {
    available = availability;
    return availability;
}

void Book::displayInfo() {
    std::cout << "Book-Id: " << id << std::endl;
    std::cout << "Book Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Available: " << available << std::endl;
}

User::User(int new_user_id, std::string new_username) {
    username = new_username;
    user_id = new_user_id;
}

int User::get_user_id() {
    return user_id;
}

std::string User::get_username() {
    return username;
}

void User::displayUserInfo() {
    std::cout << "User-Id: " << user_id << std::endl;
    std::cout << "Username: " << username << std::endl;
}
