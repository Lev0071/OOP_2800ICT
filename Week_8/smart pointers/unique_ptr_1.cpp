// unique_ptr_1.cpp
#include <iostream>
#include <memory> // for unique_ptr

void demoUniquePtr()
{
    std::unique_ptr<int> ptr = std::make_unique<int>(10);
    std::cout << "Value: " << *ptr << std::endl;

    std::unique_ptr<int> ptr1 = std::make_unique<int>(42);
    // std::unique_ptr<int> ptr2 = ptr1; // ❌ Copying not allowed
    std::unique_ptr<int> ptr2 = std::move(ptr1); // ✅ Ownership transferred

    if (ptr2)
        std::cout << "Transferred value: " << *ptr2 << std::endl;
}

int main()
{
    demoUniquePtr();
    return 0;
}
// g++ -std=c++14 -o unique_ptr_1 unique_ptr_1.cpp
// ./unique_ptr_1