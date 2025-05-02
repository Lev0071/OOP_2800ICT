#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

template<typename T>
void printVector(const vector<T>& elements);

template <typename X>
vector<X>  sortVectorsAndCombine(const vector<X>& vector1,const vector<X>& vector2);

int main() {
    // Example 1: Predefined sorted vectors
    vector<int> vec1 = {1, 3, 3, 5, 7};  
    vector<int> vec2 = {2, 4, 6, 8, 9, 10, 11}; 

    // Example 2: Predefined sorted vectors
    vector<int> vec_1 = {2, 4, 6, 8, 9, 10, 11}; 
    vector<int> vec_2 = {1, 3, 3, 5, 7};

    vector<int> sortedAndMerged {};
    cout << "First sorted array: ";
    printVector(vec1);
    cout << endl;

    cout << "Second sorted array: ";
    printVector(vec2);
    cout<< endl;

    cout << "Merged sorted array: ";
    sortedAndMerged = sortVectorsAndCombine(vec1,vec2);
    printVector(sortedAndMerged);
    cout << endl;

    cout << "First sorted array: ";
    printVector(vec_1);
    cout << endl;

    cout << "Second sorted array: ";
    printVector(vec_2);
    cout<< endl;

    cout << "Merged sorted array: ";
    sortedAndMerged = sortVectorsAndCombine(vec_1,vec_2);
    printVector(sortedAndMerged);
    cout << endl;


    return 0;
}

template <typename X>
vector<X> sortVectorsAndCombine(const vector<X>& vector1,const vector<X>& vector2){
    auto totalSize = vector1.size()+vector2.size();
    vector<X> sortedAndMerged {};
    auto iter1 = vector1.begin();
    auto iter2 = vector2.begin();

    while(iter1 != vector1.end() && iter2 != vector2.end()){
        if(*iter1<=*iter2){
            sortedAndMerged.push_back(*iter1);
            ++iter1;
        }
        else{
            sortedAndMerged.push_back(*iter2);
            ++iter2;
        }
    }
    while(iter1 != vector1.end()){
        sortedAndMerged.push_back(*iter1);
        ++iter1;
    }
    while(iter2 != vector2.end()){
        sortedAndMerged.push_back(*iter2);
        ++iter2;
    }
    return sortedAndMerged;
}

template<typename T>
void printVector(const vector<T>& elements){
    for (const T& elems : elements) {
        cout << elems << " ";
    }
}

