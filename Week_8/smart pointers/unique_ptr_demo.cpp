#include <iostream>
#include <memory> // for unique_ptr and make_unique

void demoUniquePtr()
{
    int a_int = 10;

    std::unique_ptr<int> ptr = std::make_unique<int>(10);

    std::cout << "Address: " << ptr.get() << std::endl;
    std::cout << "Value: " << *ptr << std::endl;
    std::cout << "Value: " << *ptr.get() << std::endl;

    std::unique_ptr<int> ptr1 = std::make_unique<int>(42);

    // std::unique_ptr<int> ptr2 = ptr1; // ❌ Not allowed — copy constructor is deleted
    std::unique_ptr<int> ptr2 = std::move(ptr1); // ✅ Ownership transferred from ptr1 to ptr2

    if (ptr2)
        std::cout << "Transferred value: " << *ptr2 << std::endl;
}

int main()
{
    demoUniquePtr();
    return 0;
}
// g++ -std=c++11 -o unique_ptr_demo unique_ptr_demo.cpp
// g++ -std=c++14 -o unique_ptr_demo unique_ptr_demo.cpp

// ./unique_ptr_demo