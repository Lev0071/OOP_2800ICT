// 🧠 Exercise 3: Multiple Throws

// Write a function that throws:

//     invalid_argument if a string is empty

//     overflow_error if a number is too big

//     runtime_error for something else



#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// A function that may thro an exception
double divide(int a,int b);

int main(){
    int x,y;
    bool cont = true;
    cout << "Enter two numners  (Enter two exclamation marks (!) to quit: )>";
    
    while(cont){
        try{
            cin >> x >> y;
            if (cin.fail()){
                string maybeQuit;
                cin.clear(); // clear error flags
                cin >> maybeQuit; // read the remaining invalid part

                if (maybeQuit == "!!") {
                    cout << "Quitting...\n";
                    cont = false;
                    break;
                }

                cout << "\nInvalid input. Enter two numners  (Enter two exclamation marks (!) to quit: )>";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard rest of line
                continue;
                throw invalid_argument("Invalid argument passed.");
            }
        }catch(const exception &e){
            cout << "Exception caught: " << e.what() << endl;
        }
       
        try{
            double result = divide(x,y); // Call the function
            cout << "Result: " << result << endl;
        }
        catch(const exception &e){
            cout << "Exception caught: " << e.what() << endl;
            //cerr << "Exception caught: " << e.what() << endl;
        }
    
        cout << "Program continues..." << endl;
        cout << "Enter two numners  (Enter two exclamation marks (!) to quit: )>";
    }
    return 0;
}

double divide(int a,int b){
    if(b==0){
        throw logic_error("Denominator should not be zero.");
    }
    return static_cast<double>(a)/b;
}

// g++ -std=c++2b basic_try_catch_3.cpp -o basicTC3

//////////////
// Catch and print each differently
// if (cin.fail()) {
//     string maybeQuit;
//     cin.clear(); // clear error flags
//     cin >> maybeQuit; // read the remaining invalid part

//     if (maybeQuit == "!!") {
//         cout << "Quitting...\n";
//         break;
//     }

//     cout << "Invalid input. Please enter two integers.\n";
//     cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard rest of line
//     continue;
// }

// cout << "You entered: " << x << " and " << y << '\n';
// // do something with x and y