#include <iostream>
#include <initializer_list> // Include necessary header

using namespace std;

// Function definition
template <typename X>
void processItems(std::initializer_list<X> items) {
    for(auto i: items){
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    processItems({10, 20, 30, 40, 50});
    processItems({"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dogs"});
    return 0;
}




