#include <iostream>
using namespace std;

int main() {

    cout << "=== Exercise 1: No capture, no outside variables used ===\n";
    // TODO: Define a lambda that prints "Hi!" with no capture
    auto sayHi = []() {
        cout << "Hi!" << endl;
    };
    sayHi();

    cout << "\n=== Exercise 2: Try using an outside variable without capturing it ===\n";
    int x = 5;
    // TODO: Uncomment the next lines and explain the compiler error
    // auto printX = []() {
    //     cout << x; // ❌ Error: 'x' is not captured
    // };
    // printX();

    cout << "\n=== Exercise 3: Capture by value [=] ===\n";
    // TODO: Use [=] to capture 'x' and print it inside the lambda
    auto printXByValue = [=]() {
        cout << "x = " << x << endl;
    };
    printXByValue();  // Output: x = 5

    cout << "\n=== Exercise 4: Capture by reference [&] ===\n";
    // TODO: Modify 'x' inside the lambda using reference capture
    auto modifyXByRef = [&]() {
        x += 10;
    };
    modifyXByRef();
    cout << "x after modifyXByRef: " << x << endl;  // Output: 15

    cout << "\n=== Exercise 5: Capture specific variables ===\n";
    int y = 10;
    // TODO: Capture 'x' by value and 'y' by reference, then print and modify 'y'
    auto customCapture = [x, &y]() {
        cout << "x (by value): " << x << ", y (by ref): " << y << endl;
        y += 5;
    };
    customCapture();
    cout << "y after customCapture: " << y << endl;  // y should be incremented

    cout << "\n=== Exercise 6: Lambda with parameters and return types ===\n";
    // TODO: Define a lambda 'square' that returns x*x
    auto square = [](int n) {
        return n * n;
    };
    cout << "square(4): " << square(4) << endl;

    // TODO: Define a lambda 'divide' with explicit return type
    auto divide = [](double a, double b) -> double {
        return (b != 0) ? a / b : 0;
    };
    cout << "divide(10, 2): " << divide(10, 2) << endl;

    // TODO: Lambda capturing 'base' by value and accepting int parameter
    int base = 10;
    auto addToBase = [base](int n) {
        return base + n;
    };
    cout << "addToBase(5): " << addToBase(5) << endl;

    cout << "\n=== Lambda Capture Quiz ===\n";

    cout << "Q1. What will this print?\n";
    cout << "int x = 3;\nauto f = [=]() { return x + 2; };\ncout << f();\n";
    cout << "Answer: " << [=]() { return x + 2; }() << "  // Should be 5\n";

    cout << "\nQ2. Which capture mode allows modifying the original variable?\n";
    cout << "Answer: [&]  // Captures by reference\n";

    cout << "\nQ3. What will happen in this case?\n";
    cout << "int x = 10;\nauto f = []() { cout << x; };\n";
    cout << "Answer: Compile-time Error  // x is not captured\n";

    return 0;
}
// g++ -std=c++2b lambdaQuiz.cpp -o lambdaQuiz

1. Lambda without any capture
Concept: A lambda can exist on its own without needing external variables.
💪 Exercise:
Write a lambda that prints "The void has spoken." without using or referencing any outside variables. Call it immediately.
Answer:
auto printX = [](){cout<<"The void has spoken."<<endl;};

2. Using outside variable without capturing (should error)
Concept: Lambdas don’t see variables outside their scope unless captured.
💪 Exercise:
Create a lambda that tries to print a variable x = 42 without capturing it. Observe and explain the compiler error.
Answer:
int x=42;
auto printX = [](){cout<<x<<endl;}; // Error: 'x' is not captured


3. Capture by value [=]
Concept: Variables captured by value are copied and read-only.
💪 Exercise:
Create a variable x = 7. Write a lambda that captures it by value and returns x * 2. Print the result.
Then, try to increment x inside the lambda — what happens?
Answer:
int x=7;
auto result = [=](){return x * 2;};
you cannot increment x as it is passed by value, you can return x+1, or pass x by reference ie [&x] or [&] in the capture argument.

4. Capture by reference [&]
Concept: Capturing by reference gives the lambda access to the real variable.
💪 Exercise:
Create an integer counter = 0. Write a lambda that increments it. Call the lambda 3 times, then print counter.
Answer:
int counter=0;
auto count = [&](){
    counter++;
};
for(int i = 0;i<3;i++){
    cout<<"count: " << count() << endl;
}


5. Capture specific variables by value/reference
Concept: You can choose how each variable is captured.
💪 Exercise:
Declare int a = 1, b = 2. Write a lambda that:
Captures a by value and b by reference.
Try to increment both.
What’s the outcome? Prove it by printing a and b after calling the lambda.
Answer:

int a = 1, b = 2;
auto valAndref = [a,&b](){
    //a+=1; // Error, only option is "return a+1
    b+=1; // Works original variable updated   
    cout<<"Captured Values: \na: "<< a << " (copied)" << "\nb: "<< b << " (referenced)"<<endl;
};
cout<<"Captured Values: \na: "<< a << " (copied)" << "\nb: "<< b << " (referenced)"<<endl;
valAndref();

6. Lambda with parameters
Concept: Lambdas can accept arguments just like normal functions.
💪 Exercise:
Write a lambda that accepts an int and returns "even" or "odd" depending on the input.
Answer:
auto oddOrEven = [](int x){if(x%2==0)return "even";else return "odd";};

7. Lambda with explicit return type
Concept: You can use -> type to control return types explicitly.
💪 Exercise:
Write a lambda that divides two doubles and returns a double.
If division by zero is attempted, return -1.0. Use -> double syntax.
Answer:
auto divide = [](double a,double b) -> double {return b!=0 ? a/b:-1;};

8. Lambda with mixed capture + parameters

Concept: You can capture outside variables and pass parameters at the same time.

💪 Exercise:
Create int base = 0.
Write a lambda that:
    Captures base by value.
    Takes one int parameter.
    Returns the sum of base and the parameter.
Answer:
int base = 0;
auto countInFives = [base](int x){return base+x;};

9. Quiz: Predict the output of a [=] capture
Concept: When [=] is used, the lambda keeps a snapshot of variables.
💪 Exercise:
What will this print?
int x = 3;
auto f = [=]() {
    return x + 2;
};
cout << f() << endl;
Answer:
it will print "5"

10. Quiz: Which capture lets you modify variables?
Concept: Only reference capture [&] lets you change external variables.
💪 Exercise:
Write a lambda that:
    Tries to modify int x = 9 when captured with [=].
    Then switch to [&] and succeed.
    Verify by printing x.
Answer:
int x=5;
int y=5;
auto updateVariable = [&x,y](){
    std::cout<<"Captured Values: \ny: "<< y << " (copied)" << "\nx: "<< x << " (referenced)"<<std::endl;
    x+=1;
    //y+=1; // error: assignment of read-only variable ‘y’
};

11. Quiz: No capture, tries to use outside variable
Concept: A lambda with [] cannot see outside variables.
💪 Exercise:
What happens here?
int x = 10;
auto f = []() {
    cout << x;
};
f();
Answer:
x is not captures needs to be:
int x = 10;
auto f = [x]() {
    cout << x;
};
f();

