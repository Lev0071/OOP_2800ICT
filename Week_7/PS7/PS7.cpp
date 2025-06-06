#include <iostream>

#include "inventory.hpp"
#include "threshold.hpp"
#include "exceptions.hpp"
#include "book.hpp"

// ---------- Main ----------
int main() {
    Inventory inventory;

    // Add books to inventory
    inventory.addBook(Book("C++ Primer", "Lippman", 12));
    inventory.addBook(Book("Effective Modern C++", "Scott Meyers", 5));
    inventory.addBook(Book("Clean Code", "Robert C. Martin", 2));
    inventory.addBook(Book("The Pragmatic Programmer", "Hunt & Thomas", 7));

    // Sell books with exception handling
    try {
        std::cout << "\nTrying to sell 15 of \"C++ Primer\"...\n";
        inventory.sellBook("C++ Primer", 15);
    } catch (const std::exception& ex) {
        std::cout << "Caught exception: " << ex.what() << "\n";
    }

    try {
        std::cout << "\nTrying to sell -1 of \"Effective Modern C++\"...\n";
        inventory.sellBook("Effective Modern C++", -1);
    } catch (const std::exception& ex) {
        std::cout << "Caught exception: " << ex.what() << "\n";
    }

    try {
        std::cout << "\nTrying to sell 1 of \"Nonexistent Book\"...\n";
        inventory.sellBook("Nonexistent Book", 1);
    } catch (const std::exception& ex) {
        std::cout << "Caught exception: " << ex.what() << "\n";
    }

    // Use functor to find books with stock < 10
    std::cout << "\nBooks with stock < 10 (via functor):\n";
    LowStockChecker checker(10);
    inventory.applyToAllBooks([&checker](Book& book) {
        if (checker(book)) {
            std::cout << " - " << book.getTitle() << " (Stock: " << book.getStock() << ")\n";
        }
    });

    // Use lambda to find books with stock < 5
    std::cout << "\nBooks with stock < 5 (via lambda):\n";
    inventory.applyToAllBooks([](Book& book) {
        if (book.getStock() < 5) {
            std::cout << " - " << book.getTitle() << " (Stock: " << book.getStock() << ")\n";
        }
    });

    // Restock all books by 5
    std::cout << "\nRestocking all books by 5...\n";
    inventory.applyToAllBooks([](Book& book) {
        book.restock(5);
        std::cout << "Restocked \"" << book.getTitle() << "\"\n";
    });

    // Example usage of findBook()
    std::cout << "\nFinding book by title...\n";
    Book foundBook("", "", 0);
    if (inventory.findBook("Clean Code", foundBook)) {
        std::cout << "Found \"" << foundBook.getTitle() << "\" (Stock: " << foundBook.getStock() << ")\n";
    } else {
        std::cout << "Book not found.\n";
    }

    return 0;
}
// g++ -std=c++2b PS7.cpp -o PS7