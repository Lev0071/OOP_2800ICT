#include <iostream>
#include <memory>

class Resource {
private:
    int flag = 0;

public:
    Resource(int flag = 1) : flag(flag) {
        std::cout << flag << " | Resource acquired\n";
    }

    ~Resource() {
        std::cout << flag << " | Resource destroyed\n";
    }

    friend std::ostream& operator<<(std::ostream& out, const Resource& res);
};

std::ostream& operator<<(std::ostream& out, const Resource& res) {
    out << "Resource(flag=" << res.flag << ")";
    return out;
}

void someFunction2() {
    auto ptr = std::make_unique<Resource>(2);

    std::cout << "*ptr = " << *ptr << std::endl;

    // Address of the smart pointer object itself
    std::cout << "Address of ptr (unique_ptr object): " << &ptr << std::endl;

    // Address of the actual resource managed by the smart pointer
    std::cout << "Address of resource (ptr.get()):    " << ptr.get() << std::endl;
}

int main() {
    someFunction2();
    std::cout << "End of main\n";
    return 0;
}

// g++ -std=c++14  unique_ptr_resource_demo.cpp -o unique_ptr_resource_demo