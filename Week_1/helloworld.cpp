/* 
Comment
Block
*/
#include <iostream> // Enables cout for output, cin for input...etc
#include <vector> // Enables use of vector container(a dynamic array)
#include <string> // Enables use of string type

using namespace std; // Allows using cout, vector, string without std:: prefix

int main() { //Entry point of the program
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"}; // 	Declares and initializes a vector of strings named as "msg" that contains 6 string elements
    for (const string& word : msg) { // Iterates through each string in the vector, (const-read only)(string&-use reference to avoid copying, more efficient)(word-reference to each element in msg)
        cout << word << " "; // Prints each word with a space
    }
    cout << endl; // Moves to the next line after printing all words
    return 0; // Signals successful program completion
}
