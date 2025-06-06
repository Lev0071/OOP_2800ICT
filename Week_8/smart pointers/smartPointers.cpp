#include <iostream>
#include <memory>

class Book {
public:
    Book(const std::string& name) : title(name) {
        std::cout << "📘 Book \"" << title << "\" created.\n";
    }

    ~Book() {
        std::cout << "🔥 Book \"" << title << "\" destroyed.\n";
    }

    void read() const {
        std::cout << "📖 Reading \"" << title << "\"...\n";
    }

private:
    std::string title;
};

int main() {
    std::cout << "=== Unique Pointer Section ===\n";
    {
        std::unique_ptr<Book> unique1 = std::make_unique<Book>("Unique Book 1");
        std::unique_ptr<Book> unique2 = std::make_unique<Book>("Unique Book 2");

        unique1->read();
        unique2->read();

        // Exiting this scope → both unique_ptrs are destroyed
    }

    std::cout << "\n=== Shared Pointer Section ===\n";
    {
        std::shared_ptr<Book> shared1 = std::make_shared<Book>("Shared Book");
        {
            std::shared_ptr<Book> shared2 = shared1; // shared2 also points to the same object

            shared1->read();
            shared2->read();

            std::cout << "➡️ shared2 is going out of scope...\n";
        } // shared2 is destroyed here, but shared1 still exists

        std::cout << "➡️ shared1 is going out of scope...\n";
    } // Now shared1 is destroyed → book finally deleted

    std::cout << "\n=== End of Program ===\n";
    return 0;
}
// g++ -std=c++2b smartPointers.cpp -o smartPointers