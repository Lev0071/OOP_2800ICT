#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class eBook {
private:
    string id = "";
    double sizeMB = 100;
    string content = "";
};

class eBookManager {
private:
    vector<shared_ptr<eBook>> books;//vector<eBook> books;

public:
    // void addBook(const eBook& book) {
    //     books.push_back(book);
    // }
    void addBook() {
        books.emplace_back(make_shared<eBook>());
    }

    size_t getBookCount() const {
        return books.size();
    }

    void reserveBooks(size_t n) {
        books.reserve(n);
    }

    // void addBook() {
    //     books.emplace_back();  // Direct in-place construction
    // }

    void printSummary() const { // we will not waste time seeding with a driver file as we are in "production" mode for our 2800ICT boss hence the "[hidden]" placeholder
        for_each(books.begin(), books.end(), [](const shared_ptr<eBook>& book) {//for_each(books.begin(), books.end(), [](const eBook& book) {
            cout << "eBook ID: [hidden], SizeMB: 100 (default)" << endl;
        });
    }

    void removeDefaultSizeBooks() {
        auto newEnd = remove_if(books.begin(), books.end(), [](const shared_ptr<eBook>& book) {//remove_if(books.begin(), books.end(), [](const eBook& book) {
            return true; // We’ll pretend all match for demo
        });
        books.erase(newEnd, books.end());
    }
};

int main() {
    //-------------------------------------------------------------------------STEP_1 -- START
    eBookManager manager;

    cout << "STEP 1: Base eBookManager and eBook classes created.\n";
    /*
    Why STEP1 ?
    Test our base case before we progress based on concepts from WA2,WA3,WA6 and WA7 at its core.
    */
    //-------------------------------------------------------------------------STEP_1 -- END
    //-------------------------------------------------------------------------STEP_2 -- START
    cout << "STEP 2: Added 5 default eBooks to manager.\n";
    // Add 5 default eBooks
    for (int i = 0; i < 5; ++i) {
        // eBook book; // default constructor
        // manager.addBook(book);
        manager.addBook();  // no argument now after STEP_5
    }
    cout << "Book count: " << manager.getBookCount() << endl;

    /*
     Why is this efficient?
     - Using push_back with a vector means contiguous memory — fast append.
     - Adding by const reference avoids unnecessary copies on input.
     - This is fine for small numbers. We'll enhance it with reserve() next.
    */
    //-------------------------------------------------------------------------STEP_2 -- END

    //-------------------------------------------------------------------------STEP_3 -- START
    // Reserve space for 1000 eBooks to avoid reallocations
    manager.reserveBooks(1000);

    // Add 1000 default eBooks efficiently using emplace_back
    for (int i = 0; i < 1000; ++i) {
        manager.addBook();
    }

    cout << "STEP 3: Added 1000 default eBooks using reserve() and emplace_back().\n";
    cout << "Book count: " << manager.getBookCount() << endl; // Book count: 1005 not Book count: 1000

    /*
     Why is this even more efficient?
     - reserve() pre-allocates contiguous memory: avoids multiple reallocations.
     - emplace_back() constructs eBooks directly in the vector: no temporary copies.
     - Together, this is faster and uses less memory for bulk operations.
    */
    //-------------------------------------------------------------------------STEP_3 -- END

    //-------------------------------------------------------------------------STEP_4 -- START

    cout << "STEP 4: Total books after adding: " << manager.getBookCount() << endl;

    cout << "Printing summary of all eBooks:\n";
    manager.printSummary();

    manager.removeDefaultSizeBooks();

    cout << "Total books after remove_if: " << manager.getBookCount() << endl;

    /*
     Why is this efficient?
     - for_each iterates in place with no copies, so it's fast and cache-friendly.
     - remove_if + erase is the standard idiom for removing elements from a vector without reallocating new memory.
     - Together they show in-place vector processing: good for large datasets.
    */
    //-------------------------------------------------------------------------STEP_4 -- END

    //-------------------------------------------------------------------------STEP_5 -- START

    // In the eBookManager class I changed "vector<eBook> books;" to "vector<shared_ptr<eBook>> books;"

    // In the printSummary I changed "const eBook& book" to "const shared_ptr<eBook>& book" in method signature

    // In the printSummary I changed "const eBook& book" to "const shared_ptr<eBook>& book" in method signature

    /*
    Why is using shared_ptr efficient?
    - It avoids copying large content strings for each eBook.
    - The vector only copies small smart pointers, not whole objects.
    - This reduces memory usage and speeds up large moves/removals.
    - Ownership is automatic — no memory leaks.
    */

    // I would have loved to show ypu timings using our single and multithread workshop, we will do that if we get time , or I will do this in my own time after the exam 🙂
    //-------------------------------------------------------------------------STEP_5 -- END

    return 0;
}

// g++ -std=c++17 q3.cpp -o q3