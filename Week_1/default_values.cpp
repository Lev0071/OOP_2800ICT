#include <iostream>
using namespace std;

// Function prototype with default arguments
void displayStars(int cols = 10, int rows = 1);

int main()
{
    displayStars();
    cout << endl;
    displayStars(5);
    cout << endl;
    displayStars(7,3);

    return 0;
}

// Function definition
void displayStars(int cols, int rows)
{
    // Nested loop. The outer loop controls the rows
    // and the inner loop controls the columns.
    for (int down = 0; down < rows; down++)
    {
        for (int across = 0; across < cols; across++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
