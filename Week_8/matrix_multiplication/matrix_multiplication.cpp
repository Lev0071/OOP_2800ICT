// matrix_multiplication.cpp
#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <sstream>  // <<== include this

using namespace std;


void task(int num) {
    std::ostringstream oss;
    oss << "thread id: " << std::this_thread::get_id()
        << " | task number: " << num << "\n";

    std::string str = oss.str();
    std::cout << str;
}

void addRow(const vector<vector<int>>& A,const vector<vector<int>>& B,vector<vector<int>>& C,int row){
    for(size_t col = 0;col<A[0].size();++col){
        C[row][col] = A[row][col] + B[row][col];
    }
}

int main() {

    const int rows = 3,cols = 4;
    
    // Create matrices A,B and C
    vector<vector<int>> A(rows,vector<int>(cols));
    vector<vector<int>> B(rows,vector<int>(cols));
    vector<vector<int>> C(rows,vector<int>(cols,0));

    // Initialise vectors A and B:
    //Initialises vector A:
    A[0][0]= 1;A[0][1]= 2;A[0][2]= 3;A[0][3]= 4;A[1][0]= 5;A[1][1]= 6;A[1][2]= 7;A[1][3]= 8;A[2][0]= 9;A[2][1]= 10;A[2][2]= 11;A[2][3]= 12;

    //Initialises vector B:
    B[0][0]= 12;B[0][1]= 11;B[0][2]= 10;B[0][3]= 9;B[1][0]= 8;B[1][1]= 7;B[1][2]= 6;B[1][3]= 5;B[2][0]= 4;B[2][1]= 3;B[2][2]= 2;B[2][3]= 1;

    cout << "Matrice A" << endl;
    for(const auto& row:A){
        for(int val:row){
            cout << val << " ";
        }
        cout << "\n";
    }

    cout << "Matrice B" << endl;
    for(const auto& row:B){
        for(int val:row){
            cout << val << " ";
        }
        cout << "\n";
    }

    // Arithemtics
    vector<thread>threads;
    // Create a thread for each row
    for(int i = 0;i<rows; i++){
        threads.emplace_back(addRow,cref(A),cref(B),ref(C),i);
    }

    // Join all threads
    for(auto& t:threads){
        t.join();
    }

    cout << "Result Matrix C = A + B" << endl;
    for(const auto& row:C){
        for(int val:row){
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}

// g++ -std=c++14 matrix_multiplication.cpp -o matrix_multiplication