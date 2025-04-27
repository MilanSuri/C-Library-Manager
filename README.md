# C-Library-Manager

A simple C++ application for managing a library system. This program allows you to manage books, users, track book availability, and perform book checkouts and returns.

## Features

- **Book Class**: Manages book details such as title, author, ID, and availability status.
- **User Class**: Stores information about the user, including username and user ID.
- **Library Class**: Handles library operations such as adding/removing books and users, listing books and users, checking out and returning books, and ensuring availability status is updated.
- **Session-Based Interaction**: The program runs in a loop, allowing the user to interact with the system and make decisions on different library operations.

## Program Flow

The program starts by displaying a menu with the following options:

1. **Add a Book**: You can add a new book to the library by entering the book's title, author, ID, and availability.
2. **Remove a Book**: Allows you to remove a book from the library by entering the book's ID.
3. **List all Books**: Displays a list of all books currently available in the library.
4. **Register a User**: You can register a new user by providing their username and user ID.
5. **Remove a User**: Removes a user from the system using their ID.
6. **List all Users**: Displays all registered users.
7. **Check out a Book**: Allows a user to check out a book by entering the user ID and book ID.
8. **Return a Book**: Allows a user to return a checked-out book.
